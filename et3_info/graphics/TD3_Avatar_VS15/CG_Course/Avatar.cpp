#include "stdafx.h"
#include "Avatar.h"


Avatar::Avatar()
{
	_head = new Spheres();
	_torso = new Cylinder();
	_arm[LEFT] = new Cylinder();
	_arm[RIGHT] = new Cylinder();
	_forearm[LEFT] = new Cylinder();
	_forearm[RIGHT] = new Cylinder();
	_thigh[LEFT] = new Cylinder();
	_thigh[RIGHT] = new Cylinder();
	_leg[LEFT] = new Cylinder();
	_leg[RIGHT] = new Cylinder();

	// avatar initialization
	_head->buildSphere(1.5, 20, 20);
	_torso->buildCylinder(2.5, 2.5, 7.0, 20);
	_arm[LEFT]->buildCylinder(0.5, 0.5, 5.0, 20);
	_arm[RIGHT]->buildCylinder(0.5, 0.5, 5.0, 20);
	_forearm[LEFT]->buildCylinder(0.5, 0.25, 5.0, 20);
	_forearm[RIGHT]->buildCylinder(0.5, 0.25, 5.0, 20);
	_thigh[LEFT]->buildCylinder(1.25, 0.75, 5.0, 20);
	_thigh[RIGHT]->buildCylinder(1.25, 0.75, 5.0, 20);
	_leg[LEFT]->buildCylinder(0.75, 0.25, 5.0, 20);
	_leg[RIGHT]->buildCylinder(0.75, 0.25, 5.0, 20);

	// avatar objects coords init
	_head->_coords[0] = 0;
	_head->_coords[1] = _Yposition;
	_head->_coords[2] = 8.5f;
	_torso->_coords[0] = 0;
	_torso->_coords[1] = _Yposition;
	_torso->_coords[2] = 0;
	_arm[LEFT]->_coords[0] = 3.0f;
	_arm[LEFT]->_coords[1] = _Yposition;
	_arm[LEFT]->_coords[2] = 7.0f;
	_arm[RIGHT]->_coords[0] = -3.0f;
	_arm[RIGHT]->_coords[1] = _Yposition;
	_arm[RIGHT]->_coords[2] = 7.0f;
	_forearm[LEFT]->_coords[0] = 3.0f;
	_forearm[LEFT]->_coords[1] = _Yposition;
	_forearm[LEFT]->_coords[2] = 2.0f;
	_forearm[RIGHT]->_coords[0] = -3.0f;
	_forearm[RIGHT]->_coords[1] = _Yposition;
	_forearm[RIGHT]->_coords[2] = 2.0f;
	_thigh[LEFT]->_coords[0] = 1.25f;
	_thigh[LEFT]->_coords[1] = _Yposition;
	_thigh[LEFT]->_coords[2] = 0;
	_thigh[RIGHT]->_coords[0] = -1.25f;
	_thigh[RIGHT]->_coords[1] = _Yposition;
	_thigh[RIGHT]->_coords[2] = 0;
	_leg[LEFT]->_coords[0] = 1.25f;
	_leg[LEFT]->_coords[1] = _Yposition;
	_leg[LEFT]->_coords[2] = -5.0f;
	_leg[RIGHT]->_coords[0] = -1.25f;
	_leg[RIGHT]->_coords[1] = _Yposition;
	_leg[RIGHT]->_coords[2] = -5.0f;

	// initVBO
	_head->InitVBO();
	_torso->InitVBO();
	_arm[LEFT]->InitVBO();
	_arm[RIGHT]->InitVBO();
	_forearm[LEFT]->InitVBO();
	_forearm[RIGHT]->InitVBO();
	_thigh[LEFT]->InitVBO();
	_thigh[RIGHT]->InitVBO();
	_leg[LEFT]->InitVBO();
	_leg[RIGHT]->InitVBO();
}


Avatar::~Avatar()
{
	delete _head;
	delete _torso;
	delete _arm[LEFT];
	delete _arm[RIGHT];
	delete _forearm[LEFT];
	delete _forearm[RIGHT];
	delete _thigh[LEFT];
	delete _thigh[RIGHT];
	delete _leg[LEFT];
	delete _leg[RIGHT];
}

void Avatar::update(double t) {
	// TODO update the variables for the animation
	// of the avatar as a function of input time
	// (use a time scale for controlling the animation speed)
	for (size_t i = 0; i < 3; i++) {
		_head->_coords[i] += _velocity[i] * LINEAR_SPEED_SCALE;
		_torso->_coords[i] += _velocity[i] * LINEAR_SPEED_SCALE;
		_arm[LEFT]->_coords[i] += _velocity[i] * LINEAR_SPEED_SCALE;
		_arm[RIGHT]->_coords[i] += _velocity[i] * LINEAR_SPEED_SCALE;
		_forearm[LEFT]->_coords[i] += _velocity[i] * LINEAR_SPEED_SCALE;
		_forearm[RIGHT]->_coords[i] += _velocity[i] * LINEAR_SPEED_SCALE;
		_thigh[LEFT]->_coords[i] += _velocity[i] * LINEAR_SPEED_SCALE;
		_thigh[RIGHT]->_coords[i] += _velocity[i] * LINEAR_SPEED_SCALE;
		_leg[LEFT]->_coords[i] += _velocity[i] * LINEAR_SPEED_SCALE;
		_leg[RIGHT]->_coords[i] += _velocity[i] * LINEAR_SPEED_SCALE;
	}

}
