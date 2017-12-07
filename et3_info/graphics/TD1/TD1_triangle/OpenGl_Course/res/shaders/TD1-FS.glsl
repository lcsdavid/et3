/*****************************************************************************
File: TD1-FS.glsl

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

in vec3 colorOut;
// uniform sampler2DRect mire;
out vec4 frag_colour;

void main () {
  // frag_colour.xyz = texture(mire,texCoord);
  frag_colour = vec4(colorOut,1);
}

