#include "GLmain.h"
#include "td1_utils.h"
#include "GeoObject.h"

// perspective vs ortho projection
bool perspective = false;

GeoObject object;

// shader variable pointers
GLint uniform_model;
GLint uniform_inverseModel;
GLint uniform_view;
GLint uniform_proj;
GLint uniform_texture;
GLint uniform_light;

// rotation angle
GLfloat rotation_angle = 0.0f;

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

	return { ss[0].str(), ss[1].str() };
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

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(screen_width, screen_height, "OpenGL Course", NULL, NULL);
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

	// Qustion 2.1
	object.buildPolyeder(18, 1, 1, 1);
	float colors_18[] = { 
		0, 1, 1,   0, 1, 1,    0, 1, 1,
		1, 0, 1,   1, 0, 1,    1, 0, 1,
		1, 1, 0,   1, 1, 0,    1, 1, 0,
		1, 0, 0,   0, 1, 0,    0, 0, 1,
		1, 1, 1,   1, 1, 1,    1, 1, 1,
		1, 1, 1,   1, 1, 1,    1, 1, 1 };
	object.setColors(colors_18);
	object.InitVBO();
	// Question 2.1

	ShaderProgramSources source = ParseShader("res/shaders/Basic.shader");
	unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);

	double rad = 0;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		rad += glfwGetTime() / 10;
		double c = std::cos(rad);
		double s = std::sin(rad);
		float* new_vertices = new float[object.getSize() * 3];
		for (size_t i = 0; i < object.getSize() * 3; i += 3) {
			new_vertices[i] = object.getVertices()[i] * s + object.getVertices()[i + 1] * c;
			new_vertices[i + 1] = object.getVertices()[i + 1] * s - object.getVertices()[i] * c;
			new_vertices[i + 2] = object.getVertices()[i + 2];
		}
		object.setVertices(new_vertices);
		delete[] new_vertices;
		object.updateVBO();
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
				glm::vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
				glm::vec3(0, 0, 0), // and looks at the origin
				glm::vec3(0, 0, 1)  // Head is up (set to 0,1,0)
			);

		// Model matrix : a varying rotation matrix (around Oz)
		//TODO Add rotation to modelMatrix
		modelMatrix = glm::mat4(1.0f);

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		glUseProgram(shader);
		glBindVertexArray(object._vao);
		glUniformMatrix4fv(uniform_proj, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
		glUniformMatrix4fv(uniform_view, 1, GL_FALSE, glm::value_ptr(viewMatrix));
		glUniformMatrix4fv(uniform_model, 1, GL_FALSE, glm::value_ptr(modelMatrix));
		glUniformMatrix4fv(uniform_inverseModel, 1, GL_FALSE, glm::value_ptr(glm::inverse(modelMatrix)));
		glUniform3fv(uniform_light, 1, lightPosition);

		glUniform1i(uniform_texture, 0); //Texture unit 0 is for base images.
		glActiveTexture(GL_TEXTURE0 + 0);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glActiveTexture(GL_TEXTURE0 + 0);
		glBindTexture(GL_TEXTURE_2D, textureID);

		// draw points from the currently bound VAO with current in-use shader
		// TODO define primitive for glDrawArrays
	
		glDrawArrays(GL_TRIANGLES, 12, 3); // BASE
		glDrawArrays(GL_TRIANGLES, 15, 3); // BASE
		glDrawArrays(GL_TRIANGLES, 0, 3); // face
		glDrawArrays(GL_TRIANGLES, 3, 3);
		glDrawArrays(GL_LINE_LOOP, 6, 3);
		glDrawArrays(GL_LINE_LOOP, 9, 3);
		
		

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
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
	if (key == '<' || key == '>') {
		double rad = 0;
		if (key == '<')
			rad = 0.1;
		else
			rad = -0.1;
		double c = std::cos(rad);
		double s = std::sin(rad);
		float* new_vertices = new float[object.getSize() * 3];
		for (size_t i = 0; i < object.getSize() * 3; i += 3) {
			new_vertices[i] = object.getVertices()[i] * s + object.getVertices()[i + 1] * c;
			new_vertices[i + 1] = object.getVertices()[i + 1] * s - object.getVertices()[i] * c;
			new_vertices[i + 2] = object.getVertices()[i + 2];
		}
		object.setVertices(new_vertices);
		delete[] new_vertices;
		object.updateVBO();
	}
	if (key == 'q' || key == 'Q') {
		float* new_vertices = new float[object.getSize() * 3];
		for (size_t i = 0; i < object.getSize() * 3; i += 3) {
			new_vertices[i] = object.getVertices()[i] - 0.1;
			new_vertices[i + 1] = object.getVertices()[i + 1];
			new_vertices[i + 2] = object.getVertices()[i + 2];
		}
		object.setVertices(new_vertices);
		delete[] new_vertices;
		object.updateVBO();
	}
	if (key == 'D' || key == 'd') {
		float* new_vertices = new float[object.getSize() * 3];
		for (size_t i = 0; i < object.getSize() * 3; i += 3) {
			new_vertices[i] = object.getVertices()[i] + 0.1;
			new_vertices[i + 1] = object.getVertices()[i + 1];
			new_vertices[i + 2] = object.getVertices()[i + 2];
		}
		object.setVertices(new_vertices);
		delete[] new_vertices;
		object.updateVBO();
	}
	if (key == 'z' || key == 'Z') {
		float* new_vertices = new float[object.getSize() * 3];
		for (size_t i = 0; i < object.getSize() * 3; i += 3) {
			new_vertices[i] = object.getVertices()[i];
			new_vertices[i + 1] = object.getVertices()[i + 1] + 0.1;
			new_vertices[i + 2] = object.getVertices()[i + 2];
		}
		object.setVertices(new_vertices);
		delete[] new_vertices;
		object.updateVBO();
	}
	if (key == 's' || key == 'S') {
		float* new_vertices = new float[object.getSize() * 3];
		for (size_t i = 0; i < object.getSize() * 3; i += 3) {
			new_vertices[i] = object.getVertices()[i];
			new_vertices[i + 1] = object.getVertices()[i + 1] - 0.1;
			new_vertices[i + 2] = object.getVertices()[i + 2];
		}
		object.setVertices(new_vertices);
		delete[] new_vertices;
		object.updateVBO();
	}

}