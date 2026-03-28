#include <iostream>

#include "App.h"

const char *asdf = "123";

int main(void) {
	App app(800, 600, asdf);
	app.run();
	return 0;
}
