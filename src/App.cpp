#include <iostream>
#include <stdexcept>
#include <vector>

#include "Shader.h"
#include "Mesh.h"

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

void App::init_engine() {
	input = new InputHandler();
	world = new World();
	renderer = new Renderer();
}

void App::run() {
	init_gl();
	init_engine();

	while(!glfwWindowShouldClose(window)) {
		update();
		render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void App::update() {
	input->handle_input(window);
	world->update();
};

void App::render() {
	renderer->render(world);
}

App::~App() {
	glfwTerminate();
	if (input) delete input;
	if (world) delete world;
	if (renderer) delete renderer;
}
