#include <iostream>
#include <stdexcept>

#include "App.h"

void glfwError(int id, const char* description) {
	std::cerr << "GLFW Error " << id << ": " << description << "\n";
}

App::App(int width, int height, const char *title)  : width(width), height(height), title(title), window(nullptr) {}

void App::init_gl() {
	glfwSetErrorCallback(glfwError);
	if (!glfwInit()) throw std::runtime_error("Failed to init GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!window) throw std::runtime_error("Failed to create window");

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) throw std::runtime_error("Failed to initialize GLAD");

	glViewport(0, 0, width, height);
}

void App::run() {
	init_gl();
	input = new InputHandler();

	while(!glfwWindowShouldClose(window)) {
		update();
		render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void App::update() {
	input->handle_input(window);
};

void App::render() {
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	/* triangle begin */
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

#include "shaders/vertex_shader.h"
	const GLchar* vsource = reinterpret_cast<const GLchar*>(vertex_glsl);
	GLint vlength = static_cast<GLint>(vertex_glsl_len);
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vsource, &vlength);
	glCompileShader(vertex_shader);

#include "shaders/fragment_shader.h"
	const GLchar* fsource = reinterpret_cast<const GLchar*>(fragment_glsl);
	GLint flength = static_cast<GLint>(fragment_glsl_len);
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fsource, &flength);
	glCompileShader(fragment_shader);

	GLuint shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	glUseProgram(shader_program);

	GLuint vao;
	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);  

	glDrawArrays(GL_TRIANGLES, 0, 3);
	/* triangle end */

	return;
}

App::~App() {
	glfwTerminate();
	if (input) delete input;
}
