#pragma once
#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library
#define _USE_MATH_DEFINES 
#include <cmath>
class Spheres
{
public:
	Spheres();
	virtual ~Spheres();

	void buildSphere(float radius, int nbStacks, int nbSlices);
	void InitVBO(void);

	unsigned int getSize() { return _size; }
	unsigned int getSlices() { return _stacks; }
	unsigned int getStacks() { return _slices; }

	unsigned int _vao;
	float        _coords[3];
	float        _velocity[3];
	float        _radius;
	float        _mass;

protected:
	float * _vertices;
	float * _normals;
	float * _texcoors;
	int _stacks;
	int _slices;
	unsigned int _size; //Number of Vertices / Normals / Texture Coordonates

};

