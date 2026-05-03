#include <iostream>
#include <stdexcept>
#include <vector>

#include "Shader.h"
#include "Mesh.h"

#include "App.h"

void glfw_err_cb(int id, const char *description) {
	std::cerr << "GLFW Error " << id << ": " << description << "\n";
}

void glfw_resize_cb(GLFWwindow *window, int width, int height) {
	App *app = static_cast<App*>(glfwGetWindowUserPointer(window));

	if (app) {
		app->on_resize(width, height);
	} else {
		std::cerr << "Failed to resize! No App? (" << width << ", " << height << ")\n";
	}
}

App::App(int width, int height, const char *title)  : window(nullptr), width(width), height(height), title(title) {}

void App::init_gl() {
	glfwSetErrorCallback(glfw_err_cb);
	if (!glfwInit()) throw std::runtime_error("Failed to init GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!window) throw std::runtime_error("Failed to create window");

	glfwSetWindowUserPointer(window, this);
	glfwSetFramebufferSizeCallback(window, glfw_resize_cb);
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
	renderer->render(world, width, height);
}

void App::on_resize(int width, int height) {
	this->width = width;
	this->height = height;
	glViewport(0, 0, width, height);
}

App::~App() {
	glfwTerminate();
	if (input) delete input;
	if (world) delete world;
	if (renderer) delete renderer;
}
