#include "stdafx.h"
#include "GLmain.h"
#include "Avatar.h"


#define ANGULAR_SPEED_SCALE  1.5f
#define LINEAR_SPEED_SCALE   1.f

// initial animation time
double initial_time = 0.f;

enum part { LEFT = 0, RIGHT = 1 };

// avatar
Avatar *avatar;
Spheres s;

// perspective vs ortho projection
bool perspective = true;

// shader variable pointers
GLint uniform_model;
GLint uniform_inverseModel;
GLint uniform_view;
GLint uniform_proj;
GLint uniform_texture;
GLint uniform_light;

// eye & light
float eye[3] = { 20.0f , 20.0f , 20.0f };
float light[3] = { 50.0f , 0.0f , 50.0f };

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


// initial setup function
void setup(void) {
	initial_time = glfwGetTime();
	avatar = new Avatar();
	s.buildSphere(1.5, 20, 20);
}

// update function
void update(void) {
	double current_time = glfwGetTime() - initial_time;
	avatar->update(current_time);
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
	window = glfwCreateWindow(screen_width, screen_height, "OpenGL Course Avatar", NULL, NULL);
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

	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

	setup();

	ShaderProgramSources source = ParseShader("avatar.shader");
	unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		update();

		// projection matrix
		glm::mat4 projectionMatrix; // Store the projection matrix
		glm::mat4 viewMatrix; // Store the view matrix
		glm::mat4 torsoModelMatrix; // Store the model matrix
		glm::mat4 headModelMatrix;
		glm::mat4 armModelMatrix;
		glm::mat4 forearmModelMatrix;
		glm::mat4 thighModelMatrix;
		glm::mat4 legModelMatrix;
		glm::vec3 rotationAxis(1, 0, 0);

		// for forearm, thigh, leg models
		glm::mat4 reshapeMatrix = glm::mat4(glm::vec4(-1, 0, 0, 0),
			glm::vec4(0, -1, 0, 0), glm::vec4(0, 0, -1, 0), glm::vec4(0, 0, 0, 1));

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

		// wipe the drawing surface clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader);
		glUniformMatrix4fv(uniform_proj, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
		glUniformMatrix4fv(uniform_view, 1, GL_FALSE, glm::value_ptr(viewMatrix));
		glUniform1i(uniform_texture, 0); //Texture unit 0 is for base images.
		glUniform3fv(uniform_light, 1, light);

		glActiveTexture(GL_TEXTURE0 + 0);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glUniformMatrix4fv(uniform_inverseModel, 1, GL_FALSE, glm::value_ptr(glm::inverse(glm::mat4(1.0f))));

		// walk translation of the avatar
		torsoModelMatrix = glm::translate(glm::mat4(1.0f),
			glm::vec3(avatar->_torso->_coords[0],
				avatar->_torso->_coords[1], avatar->_torso->_coords[2]));
		// model matrix of the component
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(torsoModelMatrix));
		avatar->_torso->draw();

		// Head
		headModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(avatar->_head->_coords[0],
			avatar->_head->_coords[1], avatar->_head->_coords[2]));
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(headModelMatrix));
		avatar->_head->draw();

		// Right Arm
		armModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(avatar->_arm[RIGHT]->_coords[0],
			avatar->_arm[RIGHT]->_coords[1], avatar->_arm[RIGHT]->_coords[2])) * reshapeMatrix;
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(armModelMatrix));
		avatar->_arm[RIGHT]->draw();
		// Left Arm
		armModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(avatar->_arm[LEFT]->_coords[0],
			avatar->_arm[LEFT]->_coords[1], avatar->_arm[LEFT]->_coords[2])) * reshapeMatrix;
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(armModelMatrix));
		avatar->_arm[LEFT]->draw();

		// Right Forearm
		forearmModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(avatar->_forearm[RIGHT]->_coords[0],
			avatar->_forearm[RIGHT]->_coords[1], avatar->_forearm[RIGHT]->_coords[2])) * reshapeMatrix;
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(forearmModelMatrix));
		avatar->_forearm[RIGHT]->draw();
		// Left Forearm
		forearmModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(avatar->_forearm[LEFT]->_coords[0],
			avatar->_forearm[LEFT]->_coords[1], avatar->_forearm[LEFT]->_coords[2])) * reshapeMatrix;
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(forearmModelMatrix));
		avatar->_forearm[LEFT]->draw();

		// Right Thigh
		thighModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(avatar->_thigh[RIGHT]->_coords[0],
			avatar->_thigh[RIGHT]->_coords[1], avatar->_thigh[RIGHT]->_coords[2])) * reshapeMatrix;
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(thighModelMatrix));
		avatar->_thigh[RIGHT]->draw();
		// Left Thigh
		thighModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(avatar->_thigh[LEFT]->_coords[0],
			avatar->_thigh[LEFT]->_coords[1], avatar->_thigh[LEFT]->_coords[2])) * reshapeMatrix;
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(thighModelMatrix));
		avatar->_thigh[LEFT]->draw();

		// Right Thigh
		legModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(avatar->_leg[RIGHT]->_coords[0],
			avatar->_leg[RIGHT]->_coords[1], avatar->_leg[RIGHT]->_coords[2])) 
			* glm::rotate(glm::mat4(1.0f), avatar->_thighsAngle, rotationAxis)
			* reshapeMatrix;
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(legModelMatrix));
		avatar->_leg[RIGHT]->draw();
		// Left Thigh
		legModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(avatar->_leg[LEFT]->_coords[0],
			avatar->_leg[LEFT]->_coords[1], avatar->_leg[LEFT]->_coords[2])) * reshapeMatrix;
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(legModelMatrix));
		avatar->_leg[LEFT]->draw();
		//s.draw();

		// TODO as for the torso exemplified above,
		// define the model matrix of each primitive
		// and draw it by calling its draw function

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
	if (key == 'q')
		eye[0] -= 0.5;
	if (key == 'd')
		eye[0] += 0.5;
	if (key == 'z')
		eye[1] += 0.5;
	if (key == 's')
		eye[1] -= 0.5;
	if (key == 'n')
		eye[2] += 0.5;
	if (key == 'm')
		eye[2] -= 0.5;
	if (key == '8')
		avatar->_velocity[1] += 0.1f;
	if(key == '2')
		avatar->_velocity[1] -= 0.1f;
	if (key == '4')
		avatar->_velocity[0] += 0.1f;
	if (key == '6')
		avatar->_velocity[0] -= 0.1f;
}