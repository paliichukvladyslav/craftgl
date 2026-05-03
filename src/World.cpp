#include "World.h"

World::World() {
	std::vector<float> vertices = {
		-0.5f, -0.5f, -0.5f,   0.5f, -0.5f, -0.5f,   0.5f,  0.5f, -0.5f,
		0.5f,  0.5f, -0.5f,  -0.5f,  0.5f, -0.5f,  -0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,   0.5f, -0.5f,  0.5f,   0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,  -0.5f,  0.5f,  0.5f,  -0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,  -0.5f,  0.5f, -0.5f,  -0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,  -0.5f, -0.5f,  0.5f,  -0.5f,  0.5f,  0.5f,

		0.5f,  0.5f,  0.5f,   0.5f,  0.5f, -0.5f,   0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,   0.5f, -0.5f,  0.5f,   0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,   0.5f, -0.5f, -0.5f,   0.5f, -0.5f,  0.5f,
		0.5f, -0.5f,  0.5f,  -0.5f, -0.5f,  0.5f,  -0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,   0.5f,  0.5f, -0.5f,   0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,  -0.5f,  0.5f,  0.5f,  -0.5f,  0.5f, -0.5f
	};
	meshes.push_back(new Mesh(vertices));
}

World::~World() {
	for (Mesh* m : meshes) {
		delete m;
	}
}

void World::update() {
	return;
}
