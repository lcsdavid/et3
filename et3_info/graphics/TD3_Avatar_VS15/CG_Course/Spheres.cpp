#include "stdafx.h"
#include "Spheres.h"


Spheres::Spheres()
{
	_radius = 0;
}


Spheres::~Spheres()
{
	
}

// array is 71 floats (24 * 3 = 71).
void Spheres::buildSphere(float radius, int nbStacks, int nbSlices)
{
	float deltaTheta, deltaPhi;

	// vertex, normal and texture coordinates
	_slices = nbSlices;
	_stacks = nbStacks;
	_size = nbStacks * (nbSlices + 1) * 2;

	_vertices = new float[_size * 3];
	_normals = new float[_size * 3];
	_texcoors = new float[_size * 2];

	// angular distance between two latitudinal lines
	deltaPhi = -M_PI / nbSlices;

	// angular distance between two longitudinal lines
	deltaTheta = 2.0f * M_PI / nbStacks;

	float *vertices = _vertices;
	float *normals = _normals;
	float *texcoors = _texcoors;

	// triangle strips made of vertical stacks
	for (int i = 0; i < nbStacks; i++) {
		// azimuth angles of the two arcs defining the stack (longitudes)
		float theta = i * deltaTheta;
		float thetaPrime = theta + deltaTheta;

		// projection of the first theta in the horizontal plane
		float x0 = cos(theta);
		float y0 = sin(theta);

		// projection of the second theta in the horizontal plane
		float x1 = cos(thetaPrime);
		float y1 = sin(thetaPrime);

		// tesselating the triangle strip into nbSlices
		// note <= instead of < for making sure that the last angke is used
		for (int j = 0; j <= nbSlices; j++) {
			// polar angle
			float phi = j * deltaPhi;

			// polar vector in a vertical plane
			float xPolar = cos(phi);
			float yPolar = sin(phi);

			// vertex #1 (theta , phi)
			*normals = yPolar * x0;
			*vertices = *normals * radius;

			normals++;
			vertices++;

			*normals = yPolar * y0;
			*vertices = *normals * radius;

			normals++;
			vertices++;

			*normals = xPolar;
			*vertices = *normals * radius;

			normals++;
			vertices++;

			*texcoors = (float)i / (float)nbStacks;
			texcoors++;
			*texcoors = (float)j / (float)nbSlices;
			texcoors++;

			// vertex #2 (theta , phiPrime)
			*normals = yPolar * x1;
			*vertices = *normals * radius;

			normals++;
			vertices++;

			*normals = yPolar * y1;
			*vertices = *normals * radius;

			normals++;
			vertices++;

			*normals = xPolar;
			*vertices = *normals * radius;

			normals++;
			vertices++;

			*texcoors = (float)(i + 1) / (float)nbStacks;
			texcoors++;
			*texcoors = (float)j / (float)nbSlices;
			texcoors++;
		}
	}
}

void Spheres::draw() {
	// draw triangle strips from the currently bound VAO
	// with current in-use shader
	int nbStackTriangles = (_slices + 1) * 2;
	// draw triangles from the currently bound VAO with current in-use shader
	glBindVertexArray(_vao);
	for (int i = 0; i < _stacks; i++) {
		glDrawArrays(GL_TRIANGLE_STRIP, i * nbStackTriangles,
			nbStackTriangles);
	}
}