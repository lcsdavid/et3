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
	/* Needed if we have collision with other objects
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
	_thigh[LEFT]->_coords[0] = 1.25;
	_thigh[LEFT]->_coords[1] = _Yposition;
	_thigh[LEFT]->_coords[2] = -5;
	_thigh[RIGHT]->_coords[0] = -1.25;
	_thigh[RIGHT]->_coords[1] = _Yposition;
	_thigh[RIGHT]->_coords[2] = -5;
	_leg[LEFT]->_coords[0] = 1.25;
	_leg[LEFT]->_coords[1] = _Yposition;
	_leg[LEFT]->_coords[2] = -10;
	_leg[RIGHT]->_coords[0] = -1.25;
	_leg[RIGHT]->_coords[1] = _Yposition;
	_leg[RIGHT]->_coords[2] = -10;
	*/

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
	if (_velocity[0] || _velocity[1] || _velocity[2]) {
		//float w = sqrtf(_velocity[0] * _velocity[0] + _velocity[1] * _velocity[1] + _velocity[2] * _velocity[2]) * ANGULAR_SPEED_SCALE;
		_rightArmAngle = M_PI_4 * fabs(cosf(t + 33.56)) - (M_PI_2 / 3);
		_leftArmAngle = M_PI_4 * fabs(cosf(t + 33.56 + M_PI_2)) - (M_PI_2 / 3);

		_rightForearmAngle = (M_PI_4 / 3) * fabs(cosf(t + 33.56));
		_leftForearmAngle = (M_PI_4 / 3) * fabs(-cosf(t + 33.56));

		_rightThighAngle = (M_2_PI / 9)  * fabs(cosf(t)) - (M_PI / 9);
		_leftThighAngle = (M_2_PI / 9)  * fabs(-cosf(t)) - (M_PI / 9);

		_rightLegAngle = (M_PI / 9) * fabs(cosf(t + 33.56 + M_PI_2)) - (M_PI / 9);
		_leftLegAngle = (M_PI / 9) * fabs(-cosf(t + 33.56 + M_PI_2)) - (M_PI / 9);
	}	
	for (size_t i = 0; i < 3; i++) {
		// Globally torso is the avatar's position
		_torso->_coords[i] += _velocity[i] * LINEAR_SPEED_SCALE;
	}

}
