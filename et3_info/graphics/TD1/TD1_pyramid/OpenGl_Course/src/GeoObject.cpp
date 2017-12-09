#include "GeoObject.h"

GeoObject::GeoObject()
{

	_size = 0;
	_vertices = _normals = _texcoors = NULL;
	_colors = NULL;
	_vao = 0;

}

GeoObject::~GeoObject()
{

	if (_vertices != NULL)
		delete[] _vertices;

	if (_normals != NULL)
		delete[] _normals;

	if (_texcoors != NULL)
		delete[] _texcoors;

	if (_colors != NULL)
		delete[] _colors;

	_vertices = NULL;
	_normals = NULL;
	_texcoors = NULL;
	_colors = NULL;
	_vao = 0;

}


void GeoObject::buildPolyeder(int size, float r, float g, float b)
{
	// vertices array
	float vertices[] = { 0, 0, 2,  1, -1, 0,   1, 1, 0,		// SAB
						 0, 0, 2,  1, 1, 0,   -1, 1, 0,		// SBC
						 0, 0, 2,  -1, 1, 0,   -1, -1, 0,	// SCD
						 0, 0, 2,  -1, -1, 0,   1, -1, 0,	// SDA
						 1, -1, 0,  1, 1, 0,   -1, 1, 0,		// ABC
						 1, -1, 0,  -1, 1, 0,   -1, -1, 0 };	// ACD

	// normal array
	float normals[] = {  0, 0, 1,   0, 0, 1,   0, 0, 1,
						 0, 0, 1,   0, 0, 1,   0, 0, 1,
						 0, 0, 1,   0, 0, 1,   0, 0, 1,
						 0, 0, 1,   0, 0, 1,   0, 0, 1,
						 0, 0, 1,   0, 0, 1,   0, 0, 1,
						 0, 0, 1,   0, 0, 1,   0, 0, 1 };

	// color array
	float colors[] = { 0, 0, 0,   0, 0, 0,    0, 0, 0,
					   0, 0, 0,   0, 0, 0,    0, 0, 0,
					   0, 0, 0,   0, 0, 0,    0, 0, 0,
					   0, 0, 0,   0, 0, 0,    0, 0, 0,
					   0, 0, 0,   0, 0, 0,    0, 0, 0,
					   0, 0, 0,   0, 0, 0,    0, 0, 0 };

	// texCoord array
	float texCoord[] = { 0, 0,   0, 0,   0, 0,
						 0, 0,   0, 0,   0, 0,
						 0, 0,   0, 0,   0, 0,
						 0, 0,   0, 0,   0, 0,
						 0, 0,   0, 0,   0, 0,
						 0, 0,   0, 0,   0, 0 };

	_size = size;
	_vertices = new float[_size * 3];
	_normals = new float[_size * 3];
	_colors = new float[_size * 3];
	_texcoors = new float[_size * 2];

	for (unsigned int i = 0; i<_size * 3; i++)
	{
		_vertices[i] = vertices[i];
		_normals[i] = normals[i];
		_colors[i] = colors[i];
	}
	
	for (unsigned int i = 0; i<_size * 2; i++)
	{
		_texcoors[i] = texCoord[i];
	}
	
}


void GeoObject::InitVBO(void) {
	// vertex buffer objects and vertex array
	_vboVertices = 0;
	//creates 1 buffer at the identifier "vboVertices"
	glGenBuffers(1, &_vboVertices);
	//bind the buffer and tell it which kind of buffer it is. in this case, just an array
	glBindBuffer(GL_ARRAY_BUFFER, _vboVertices);
	//load data into the buffer. (type of buffer, size of buffer, pointer to data, kind of usage)
	glBufferData(GL_ARRAY_BUFFER, 3 * _size * sizeof(float), _vertices, GL_DYNAMIC_DRAW);

	_vboColors = 0;
	glGenBuffers(1, &_vboColors);
	glBindBuffer(GL_ARRAY_BUFFER, _vboColors);
	glBufferData(GL_ARRAY_BUFFER, 3 * _size * sizeof(float), _colors, GL_STATIC_DRAW);

	_vboNormals = 0;
	glGenBuffers(1, &_vboNormals);
	glBindBuffer(GL_ARRAY_BUFFER, _vboNormals);
	glBufferData(GL_ARRAY_BUFFER, 3 * _size * sizeof(float), _normals, GL_STATIC_DRAW);

	_vao = 0;
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	// vertex positions are location 0
	glBindBuffer(GL_ARRAY_BUFFER, _vboVertices);
	//make OpenGL understand what the vertex is (position of the vertex to be defined, size (2 for 2D), type, normalized between 0 and 1,
	//size of one vertex, offset of the first component to the vertex to be defined)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL);
	glEnableVertexAttribArray(0);

	// vertex colors are location 1
	glBindBuffer(GL_ARRAY_BUFFER, _vboColors);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL);
	glEnableVertexAttribArray(1); // don't forget this!

	// vertex colors are location 2
	glBindBuffer(GL_ARRAY_BUFFER, _vboNormals);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL);
	glEnableVertexAttribArray(2); // don't forget this!

}

void GeoObject::updateVBO(void)
{
	glBindBuffer(GL_ARRAY_BUFFER, _vboVertices);
	glBufferData(GL_ARRAY_BUFFER, 3 * _size * sizeof(float), _vertices, GL_DYNAMIC_DRAW);
}

void GeoObject::setColors(float * colors)
{
	for (size_t i = 0; i < _size * 3; i++)
		_colors[i] = colors[i];
}

void GeoObject::setVertices(float * vertices)
{
	for (size_t i = 0; i < _size * 3; i++)
		_vertices[i] = vertices[i];
}

float * GeoObject::getVertices()
{
	return _vertices;
}