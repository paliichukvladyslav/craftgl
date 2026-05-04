#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include "Mesh.h"
#include "World.h"
#include "TextureArray.h"

class Renderer {
private:
	Shader *the_shader;
	TextureArray *block_textures;
public:
	Renderer();
	~Renderer();

	void render(World *world, int width, int height);
};
#endif
