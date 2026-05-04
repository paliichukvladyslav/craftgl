#include "World.h"

#include <GLFW/glfw3.h>

World::World() {
	Mesh *grass_block = MeshFactory::create_grass_block(2.0f, 1.0f, 0.0f);
	meshes.push_back(grass_block);
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
