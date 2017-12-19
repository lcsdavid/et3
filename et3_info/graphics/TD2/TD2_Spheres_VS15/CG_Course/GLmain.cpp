#include "stdafx.h"
#include "GLmain.h"
//#include "td1_utils.h"
#include "Spheres.h"

// number of spheres
#define NB_SPHERES  30
#define SPEED_SCALE  .05

static float BBnormalVectors[6][3] = 
	{ { 1.0f, 0.0f, 0.0f }, { -1.0f, 0.0f, 0.0f },
	{ 0.0f, 1.0f, 0.0f }, { 0.0f, -1.0f, 0.0f }, 
	{ 0.0f, 0.0f , 1.0f }, { 0.0f, 0.0f, -1.0f } };

// perspective vs ortho projection
bool perspective = false;

Spheres _spheres[NB_SPHERES];

// shader variable pointers
GLint uniform_model;
GLint uniform_inverseModel;
GLint uniform_view;
GLint uniform_proj;
GLint uniform_texture;
GLint uniform_light;

// eye & light
float eye[3] = { 2.0f , 2.0f , 2.0f };
float light[3] = { 4.0f , 0.0f , 6.0f };

// light
float lightPosition[3] = { 4.0f , 0.0f , 6.0f };

int screen_width = 1024;
int screen_height = 768;

GLuint textureID;


struct ShaderProgramSources
{
	std::string VertexSource;
	std::string FragmentSource;
};

static ShaderProgramSources ParseShader(const std::string& filepath)
{

	std::ifstream stream(filepath);

	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else
		{
			ss[(int)type] << line << '\n';
		}
	}

	return{ ss[0].str(), ss[1].str() };
}

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	//pointer to the beginning of our data, source must exist
	const char* src = source.c_str();
	//(id of source code, number of shaders(strings), adress of source code, length assumes that each 
	//source code string is null terminated, can also get an array of length values)
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	//attach both shaders to our program
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	//delete intermediate shaders as they are now added to the program
	glDeleteShader(vs);
	glDeleteShader(fs);

	// shader parameeter bindings
	uniform_model = glGetUniformLocation(program, "modelMatrix");
	uniform_inverseModel = glGetUniformLocation(program, "inverseModelMatrix");
	uniform_view = glGetUniformLocation(program, "viewMatrix");
	uniform_proj = glGetUniformLocation(program, "projectionMatrix");
	uniform_texture = glGetUniformLocation(program, "mire");
	uniform_light = glGetUniformLocation(program, "light");

	if (uniform_model == -1)
		fprintf(stderr, "Could not bind uniform uniform_model\n");

	if (uniform_inverseModel == -1)
		fprintf(stderr, "Could not bind uniform uniform_inverseModel\n");

	if (uniform_view == -1)
		fprintf(stderr, "Could not bind uniform uniform_view\n");

	if (uniform_proj == -1)
		fprintf(stderr, "Could not bind uniform uniform_proj\n");

	if (uniform_texture == -1)
		fprintf(stderr, "Could not bind uniform uniform_texture\n");

	if (uniform_light == -1)
		fprintf(stderr, "Could not bind uniform uniform_light\n");

	return program;
}

//generate random number between 0 and 1
float Random(void) {
	return (float)(rand() / (double)RAND_MAX);
}

// initial setup function
void setup_spheres(void) {
	// spheres initialization
	for (int indSphere = 0; indSphere < NB_SPHERES; indSphere++) {
		for (int indCoord = 0; indCoord < 3; indCoord++) {
			// TODO locate randomly the spheres inside the cube
			_spheres[indSphere]._coords[indCoord] = Random() *  2.0f - 1.0f;
		}
		for (int indVel = 0; indVel < 3; indVel++) {
			// random number -.1 +.1
			_spheres[indSphere]._velocity[indVel] = Random() * 0.2f - 0.1f;
		}
		// random number 0.01 -> 0.11
		// TODO define random radiuses and associated masses
		_spheres[indSphere]._radius = Random() * 0.10f + 0.01f;
		_spheres[indSphere]._mass = pow(_spheres[indSphere]._radius, 3);
		// vbo construction (instancing could be used instead)
		_spheres[indSphere].buildSphere(_spheres[indSphere]._radius, 20, 20);
		_spheres[indSphere].InitVBO();
	}
}

// update function
GLvoid update(void) {
	int indSphere;
	int indSphereAux;
	int indCoord;
	int indPlan;
	float origin[3] = { 0, 0, 0 };
	float SO[3] = { 0, 0, 0 };
	float SOscalNormale = 0;
	float VscalNormale = 0;
	float distance = 0;
	float vitesseRelative[3] = { 0, 0, 0 };
	float vitesseRelativeScalNormale = 0;
	float normale[3] = { 0, 0, 0 };
	float norme = 0;
	float coef = 0;

	// sphere update
	for (indSphere = 0; indSphere < NB_SPHERES; indSphere++) {
		// inter-sphere collisions
		for (indSphereAux = indSphere + 1; indSphereAux < NB_SPHERES;
			indSphereAux++) {
			// distance between centers
			distance = 0;
			for (indCoord = 0; indCoord < 3; indCoord++) {
				float valAux = _spheres[indSphere]._coords[indCoord]
					- _spheres[indSphereAux]._coords[indCoord];
				distance += valAux * valAux;
			}
			distance = sqrt(distance);
			// sphere collisions if distance < r1+r2
			if (distance < _spheres[indSphere]._radius
				+ _spheres[indSphereAux]._radius) {
				// TODO manage sphere collisions, update speeds and
				// move spheres away using these speeds (so that
				// collision does not occur at next frame again

				// relative speed: v1 - v2
				for (indCoord = 0; indCoord < 3; indCoord++)
					vitesseRelative[indCoord] = _spheres[indSphere]._velocity[indCoord] 
					- _spheres[indSphereAux]._velocity[indCoord];
				// n = x2 - x1: the vector connecting the centers
				//   = the normal at the contact (should be normalized)
				for (indCoord = 0; indCoord < 3; indCoord++)
					normale[indCoord] = _spheres[indSphere]._coords[indCoord] 
					- _spheres[indSphereAux]._coords[indCoord];
				glm::vec3 n(normale[0], normale[1], normale[2]);
				n = glm::normalize(n);
				// relative speed along the normal v1 - v2 . n
				float v2dotn = glm::dot(glm::vec3(_spheres[indSphereAux]._velocity[0], _spheres[indSphereAux]._velocity[1], _spheres[indSphereAux]._velocity[2]), n);
				// new speed for S1: the tangential component does not change
				for (indCoord = 0; indCoord < 3; indCoord++)
					vitesseRelative[indCoord] = _spheres[indSphere]._velocity[indCoord] - v2dotn;
				// new speed for S1: the tangential component does not change
				// the normal component is computed as follows
				// v1' = v1 - 2 * (1/m1) / (1/m1 + 1/m2) * n
				for (indCoord = 0; indCoord < 3; indCoord++)
					_spheres[indSphere]._velocity[indCoord] = _spheres[indSphere]._velocity[indCoord] - (2 / _spheres[indSphere]._mass)
					/ ((1 / _spheres[indSphere]._mass) + (1 / _spheres[indSphereAux]._mass)) * n[indCoord];
				for (indCoord = 0; indCoord < 3; indCoord++)
					_spheres[indSphereAux]._velocity[indCoord] = _spheres[indSphereAux]._velocity[indCoord] - (2 / _spheres[indSphereAux]._mass)
					/ ((1 / _spheres[indSphereAux]._mass) + (1 / _spheres[indSphere]._mass)) * n[indCoord];
			}
		}

		// collision on the bounding cube
		for (indPlan = 0; indPlan < 6; indPlan++) {
			// the plane is moved inward by R so that we can directly
			// compare the center with the plane
			for (indCoord = 0; indCoord < 3; indCoord++) {
				if (BBnormalVectors[indPlan][indCoord] > 0) {
					origin[indCoord]
						= BBnormalVectors[indPlan][indCoord] - _spheres[indSphere]._radius;
				}
				else if (BBnormalVectors[indPlan][indCoord] < 0) {
					origin[indCoord]
						= BBnormalVectors[indPlan][indCoord] + _spheres[indSphere]._radius;
				}
				else {
					origin[indCoord] = 0;
				}
			}

			// vector SO: from center to sphere
			// SO: sphere position - origin vector calculation
			for (indCoord = 0; indCoord < 3; indCoord++) {
				SO[indCoord] = origin[indCoord]
					- _spheres[indSphere]._coords[indCoord];
			}
			// dot product of SO with normal vector BBnormalVectors[indPlan]
			// dot product SO . n
			SOscalNormale = 0;
			for (indCoord = 0; indCoord < 3; indCoord++) {
				SOscalNormale += SO[indCoord] * BBnormalVectors[indPlan][indCoord];
			}
			// is S0 . n is negative, the sphere is outside the box
			// negative dot product -> elastic collision with this face
			if (SOscalNormale < 0) {
				// TODO symmetric velocity wrt normal: v' = v - 2v . n
				// the velocity after collision is a reflection of the
				// velocity before collision along the normal vector
				float vdotn = glm::dot(glm::vec3(2 * _spheres[indSphere]._velocity[0], 2 * _spheres[indSphere]._velocity[1], 2 * _spheres[indSphere]._velocity[2]),
					glm::vec3(BBnormalVectors[indPlan][0], BBnormalVectors[indPlan][1], BBnormalVectors[indPlan][2]));
				for (indCoord = 0; indCoord < 3; indCoord++) {
					_spheres[indSphere]._velocity[indCoord] = _spheres[indSphere]._velocity[indCoord] - vdotn;
				}
				// TODO relocation of sphere inside the cube
				// by symmetry wrt origin non null coordinate
				for (indCoord = 0; indCoord < 3; indCoord++) {
					if (origin[indCoord] != 0) {
						//_spheres[indSphere]._coords[indCoord] -= _spheres[indSphere]._velocity[indCoord];
					}
				}
			}
		}
		// TODO motion according to speed
		for (indCoord = 0; indCoord < 3; indCoord++) {
			_spheres[indSphere]._coords[indCoord] += _spheres[indSphere]._velocity[indCoord];
		}
	}
}


int main(void)
{

	/* initialize random seed: */
	srand(time(NULL));

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(screen_width, screen_height, "OpenGL Course Spheres", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// Set key callback function
	//glfwSetErrorCallback(error_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCharCallback(window, char_callback);

	//initialize glew AFTER bind to context
	if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;

	//create object
	//object.buildPolyeder(18, 1, 1, 1);
	//object.InitVBO();

	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

	setup_spheres();

	ShaderProgramSources source = ParseShader("spheres.shader");
	unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		// updates sphere positions according to mechanics
		update();

		// projection matrix
		glm::mat4 projectionMatrix; // Store the projection matrix
		glm::mat4 viewMatrix; // Store the view matrix
		glm::mat4 modelMatrix; // Store the model matrix

							   // Projection: Perspective or Ortho matrix
		if (perspective) {
			projectionMatrix
				= glm::perspective(45.0f, (float)screen_width / (float)screen_height, 1.0f, 200.0f);
		}
		else {
			projectionMatrix
				= glm::ortho(-2.0f*(float)screen_width / (float)screen_height,
					2.0f*(float)screen_width / (float)screen_height,
					-2.0f, 2.0f, -10.0f, 10.0f);
		}

		// Camera matrix
		viewMatrix
			= glm::lookAt(
				glm::vec3(eye[0], eye[1], eye[2]),   // defined in eye function, currently 2,2,2
				glm::vec3(0, 0, 0), // and looks at the origin
				glm::vec3(0, 0, 1)  // Head is up (set to 0,1,0)
			);

		
		// Model matrix : a varying rotation matrix (around Oz)
		GLfloat angle = glfwGetTime() * 2;
		//TODO Add rotation to modelMatrix
		modelMatrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 0.0f, 1.0f));

		// wipe the drawing surface clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader);
		glUniformMatrix4fv(uniform_proj, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
		glUniformMatrix4fv(uniform_view, 1, GL_FALSE, glm::value_ptr(viewMatrix));
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(modelMatrix));
		glUniformMatrix4fv(uniform_inverseModel, 1, GL_FALSE, glm::value_ptr(glm::inverse(modelMatrix)));
		glUniform3fv(uniform_light, 1, lightPosition);

		glUniform1i(uniform_texture, 0); //Texture unit 0 is for base images.
		glActiveTexture(GL_TEXTURE0 + 0);
		glBindTexture(GL_TEXTURE_2D, textureID);

		// draw triangle strips from the currently bound VAO
		// with current in-use shader
		for (int indSphere = 0; indSphere < NB_SPHERES; indSphere++) {
			int nbStackTriangles = (_spheres[indSphere].getSlices() + 1) * 2;
			// draw triangles from the currently bound VAO with current in-use shader
			glBindVertexArray(_spheres[indSphere]._vao);
			glm::vec3 center(_spheres[indSphere]._coords[0], _spheres[indSphere]._coords[2], _spheres[indSphere]._coords[3]);
			// TODO translate the spheres by the coordinates of their center
			modelMatrix = glm::translate(glm::mat4(1.0f), center);
			glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(modelMatrix));
			for (int i = 0; i < (int)_spheres[indSphere].getStacks(); i++) {
				glDrawArrays(GL_TRIANGLE_STRIP, i * nbStackTriangles,
					nbStackTriangles);
			}
		}

		glBindVertexArray(0); // Disable our Vertex Buffer Object

		/* Poll for and process events */
		glfwPollEvents();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

	}

	glDeleteProgram(shader);

	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode,
	int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void char_callback(GLFWwindow* window, unsigned int key)
{
	if (key == 'p' || key == 'P')
		perspective = true;
	if (key == 'o' || key == 'O')
		perspective = false;
	// TODO change rotation angle according to key stroke
}