#shader vertex
#version 330 core

in vec3 vp;
in vec3 color;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec3 colorOut;
void main()
{
	colorOut = color;
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vp, 1.0);

};

#shader fragment
#version 330 core

in vec3 colorOut;
out vec4 frag_color;
void main()
{
	frag_color = vec4(colorOut, 1.0);
};