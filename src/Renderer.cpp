#include "Renderer.h"

#include "shaders/vertex_shader.h"
#include "shaders/fragment_shader.h"

Renderer::Renderer() {
	the_shader = new Shader(vertex_glsl, vertex_glsl_len, fragment_glsl, fragment_glsl_len);
}

void Renderer::render(World* the_world) {
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	the_shader->use();

	for (Mesh* mesh : the_world->meshes) {
		mesh->draw();
	}
}

Renderer::~Renderer() {
	delete the_shader;
}
