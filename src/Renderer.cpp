#include "Renderer.h"

#include "shaders/vertex_shader.h"
#include "shaders/fragment_shader.h"

#include <GLFW/glfw3.h>

Renderer::Renderer() {
	the_shader = new Shader(vertex_glsl, vertex_glsl_len, fragment_glsl, fragment_glsl_len);

	std::vector<std::string> textures = {
		"assets/dirt.png",
		"assets/grass_side.png",
		"assets/grass_top.png"
	};
	block_textures = new TextureArray(textures);

	glEnable(GL_DEPTH_TEST);
}

void Renderer::render(World *the_world, int width, int height) {
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	the_shader->use();
	the_shader->set_int("u_texture_array", 0);
	block_textures->bind(0);

	float aspect = (float)width / (float)height;

	glm::mat4 projection = glm::perspective(glm::radians(45.0f), aspect, 0.1f, 100.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));

	the_shader->set_mat4("projection", projection);
	the_shader->set_mat4("view", view);

	for (Mesh* mesh : the_world->meshes) {
		the_shader->set_mat4("model", mesh->get_model_matrix());
		mesh->draw();
	}
}

Renderer::~Renderer() {
	delete the_shader;
	delete block_textures;
}
