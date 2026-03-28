#ifndef APP_H
#define APP_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "InputHandler.h"

class App {
private:
	GLFWwindow *window;
	int width, height;
	const char *title;

	InputHandler *input;

	void init_gl();
	void update();
	void render();
public:
	App(int width, int height, const char *title);
	~App();

	void run();
};

#endif
