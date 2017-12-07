/*****************************************************************************
File: TD1-VS.glsl

Informatique Graphique
Christian Jacquemin, Universite Paris-Sud & LIMSI-CNRS

Copyright (C) 2016 University Paris-Sud
This file is provided without support, instruction, or implied
warranty of any kind.  University Paris 11 makes no guarantee of its
fitness for a particular purpose and is not liable under any
circumstances for any damages or loss whatsoever arising from the use
or inability to use this file or items derived from it.
******************************************************************************/
#version 130

in vec3 vp;
in vec3 color;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
out vec3 colorOut;

void main () {
  colorOut = color;
  gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4 (vp, 1.0);
}

