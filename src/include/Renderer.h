#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include "Mesh.h"
#include "World.h"

class Renderer {
private:
	Shader *the_shader;
public:
	Renderer();
	~Renderer();

	void render(World *world);
};
#endif
