#ifndef APP_H
#define APP_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "InputHandler.h"
#include "World.h"
#include "Renderer.h"

class App;

void glfw_resize_cb(GLFWwindow *window, int width, int height);

class App {
private:
	GLFWwindow *window;
	int width, height;
	const char *title;

	void init_gl();
	void init_engine();
	void update();
	void render();
	void on_resize(int width, int height);

	friend void glfw_resize_cb(GLFWwindow* window, int width, int height);

	InputHandler *input;
	World *world;
	Renderer *renderer;
public:
	App(int width, int height, const char *title);
	~App();

	void run();
};

#endif
