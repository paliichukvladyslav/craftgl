#include "World.h"

#include <GLFW/glfw3.h>

World::World() {

	glm::vec3 cube_color = {0.8f, 0.8f, 0.8f};
	glm::vec2 dummy_uv = {0.0f, 0.0f};
	float no_tex = -1.0f;

	std::vector<Vertex> vertices = {
		// Back face
		{{-0.5f, -0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f, -0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f,  0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f,  0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f,  0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f, -0.5f, -0.5f}, cube_color, dummy_uv, no_tex},

		// Front face
		{{-0.5f, -0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f, -0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f,  0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f,  0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f,  0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f, -0.5f,  0.5f}, cube_color, dummy_uv, no_tex},

		// Left face
		{{-0.5f,  0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f,  0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f, -0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f, -0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f, -0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f,  0.5f,  0.5f}, cube_color, dummy_uv, no_tex},

		// Right face
		{{ 0.5f,  0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f,  0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f, -0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f, -0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f, -0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f,  0.5f,  0.5f}, cube_color, dummy_uv, no_tex},

		// Bottom face
		{{-0.5f, -0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f, -0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f, -0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f, -0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f, -0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f, -0.5f, -0.5f}, cube_color, dummy_uv, no_tex},

		// Top face
		{{-0.5f,  0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f,  0.5f, -0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f,  0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{ 0.5f,  0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f,  0.5f,  0.5f}, cube_color, dummy_uv, no_tex},
		{{-0.5f,  0.5f, -0.5f}, cube_color, dummy_uv, no_tex}
	};

	meshes.push_back(new Mesh(vertices));
	auto_rotate = false;
}

World::~World() {
	for (Mesh *m : meshes) {
		delete m;
	}
}

void World::update() {
	if (!auto_rotate) return;
	float time = (float)glfwGetTime();
	for (Mesh *m : meshes) {
		m->set_rotation(glm::vec3(time * 0.2f, time * 0.4f, 0.0f));
	}
	return;
}
