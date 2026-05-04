#include "MeshFactory.h"

Mesh* MeshFactory::create_block(float tex_top, float tex_side, float tex_bottom) {
	glm::vec3 c = {1.0f, 1.0f, 1.0f};

	std::vector<Vertex> vertices = {
		/* back face (z = -0.5) */
		{{-0.5f, -0.5f, -0.5f}, c, {0.0f, 0.0f}, tex_side},
		{{ 0.5f, -0.5f, -0.5f}, c, {1.0f, 0.0f}, tex_side},
		{{ 0.5f,  0.5f, -0.5f}, c, {1.0f, 1.0f}, tex_side},
		{{ 0.5f,  0.5f, -0.5f}, c, {1.0f, 1.0f}, tex_side},
		{{-0.5f,  0.5f, -0.5f}, c, {0.0f, 1.0f}, tex_side},
		{{-0.5f, -0.5f, -0.5f}, c, {0.0f, 0.0f}, tex_side},

		/* front face (z = 0.5) */
		{{-0.5f, -0.5f,  0.5f}, c, {0.0f, 0.0f}, tex_side},
		{{ 0.5f, -0.5f,  0.5f}, c, {1.0f, 0.0f}, tex_side},
		{{ 0.5f,  0.5f,  0.5f}, c, {1.0f, 1.0f}, tex_side},
		{{ 0.5f,  0.5f,  0.5f}, c, {1.0f, 1.0f}, tex_side},
		{{-0.5f,  0.5f,  0.5f}, c, {0.0f, 1.0f}, tex_side},
		{{-0.5f, -0.5f,  0.5f}, c, {0.0f, 0.0f}, tex_side},

		/* left face (x = -0.5) */
		{{-0.5f,  0.5f,  0.5f}, c, {1.0f, 1.0f}, tex_side},
		{{-0.5f,  0.5f, -0.5f}, c, {0.0f, 1.0f}, tex_side},
		{{-0.5f, -0.5f, -0.5f}, c, {0.0f, 0.0f}, tex_side},
		{{-0.5f, -0.5f, -0.5f}, c, {0.0f, 0.0f}, tex_side},
		{{-0.5f, -0.5f,  0.5f}, c, {1.0f, 0.0f}, tex_side},
		{{-0.5f,  0.5f,  0.5f}, c, {1.0f, 1.0f}, tex_side},

		/* right face (x = 0.5) */
		{{ 0.5f,  0.5f,  0.5f}, c, {0.0f, 1.0f}, tex_side},
		{{ 0.5f,  0.5f, -0.5f}, c, {1.0f, 1.0f}, tex_side},
		{{ 0.5f, -0.5f, -0.5f}, c, {1.0f, 0.0f}, tex_side},
		{{ 0.5f, -0.5f, -0.5f}, c, {1.0f, 0.0f}, tex_side},
		{{ 0.5f, -0.5f,  0.5f}, c, {0.0f, 0.0f}, tex_side},
		{{ 0.5f,  0.5f,  0.5f}, c, {0.0f, 1.0f}, tex_side},

		/* bottom face (y = -0.5) */
		{{-0.5f, -0.5f, -0.5f}, c, {0.0f, 1.0f}, tex_bottom},
		{{ 0.5f, -0.5f, -0.5f}, c, {1.0f, 1.0f}, tex_bottom},
		{{ 0.5f, -0.5f,  0.5f}, c, {1.0f, 0.0f}, tex_bottom},
		{{ 0.5f, -0.5f,  0.5f}, c, {1.0f, 0.0f}, tex_bottom},
		{{-0.5f, -0.5f,  0.5f}, c, {0.0f, 0.0f}, tex_bottom},
		{{-0.5f, -0.5f, -0.5f}, c, {0.0f, 1.0f}, tex_bottom},

		/* top face (y = 0.5) */
		{{-0.5f,  0.5f, -0.5f}, c, {0.0f, 1.0f}, tex_top},
		{{ 0.5f,  0.5f, -0.5f}, c, {1.0f, 1.0f}, tex_top},
		{{ 0.5f,  0.5f,  0.5f}, c, {1.0f, 0.0f}, tex_top},
		{{ 0.5f,  0.5f,  0.5f}, c, {1.0f, 0.0f}, tex_top},
		{{-0.5f,  0.5f,  0.5f}, c, {0.0f, 0.0f}, tex_top},
		{{-0.5f,  0.5f, -0.5f}, c, {0.0f, 1.0f}, tex_top}
	};

	return new Mesh(vertices);
}

Mesh* MeshFactory::create_grass_block(float tex_top, float tex_side, float tex_bottom) {
	glm::vec3 c_white = {1.0f, 1.0f, 1.0f}; 
	glm::vec3 c_green = {0.55f, 0.77f, 0.35f}; 

	std::vector<Vertex> vertices = {
		/* back face (z = -0.5) */
		{{-0.5f, -0.5f, -0.5f}, c_white, {0.0f, 0.0f}, tex_side},
		{{ 0.5f, -0.5f, -0.5f}, c_white, {1.0f, 0.0f}, tex_side},
		{{ 0.5f,  0.5f, -0.5f}, c_white, {1.0f, 1.0f}, tex_side},
		{{ 0.5f,  0.5f, -0.5f}, c_white, {1.0f, 1.0f}, tex_side},
		{{-0.5f,  0.5f, -0.5f}, c_white, {0.0f, 1.0f}, tex_side},
		{{-0.5f, -0.5f, -0.5f}, c_white, {0.0f, 0.0f}, tex_side},

		/* front face (z = 0.5) */
		{{-0.5f, -0.5f,  0.5f}, c_white, {0.0f, 0.0f}, tex_side},
		{{ 0.5f, -0.5f,  0.5f}, c_white, {1.0f, 0.0f}, tex_side},
		{{ 0.5f,  0.5f,  0.5f}, c_white, {1.0f, 1.0f}, tex_side},
		{{ 0.5f,  0.5f,  0.5f}, c_white, {1.0f, 1.0f}, tex_side},
		{{-0.5f,  0.5f,  0.5f}, c_white, {0.0f, 1.0f}, tex_side},
		{{-0.5f, -0.5f,  0.5f}, c_white, {0.0f, 0.0f}, tex_side},

		/* left face (x = -0.5) */
		{{-0.5f,  0.5f,  0.5f}, c_white, {1.0f, 1.0f}, tex_side},
		{{-0.5f,  0.5f, -0.5f}, c_white, {0.0f, 1.0f}, tex_side},
		{{-0.5f, -0.5f, -0.5f}, c_white, {0.0f, 0.0f}, tex_side},
		{{-0.5f, -0.5f, -0.5f}, c_white, {0.0f, 0.0f}, tex_side},
		{{-0.5f, -0.5f,  0.5f}, c_white, {1.0f, 0.0f}, tex_side},
		{{-0.5f,  0.5f,  0.5f}, c_white, {1.0f, 1.0f}, tex_side},

		/* right face (x = 0.5) */
		{{ 0.5f,  0.5f,  0.5f}, c_white, {0.0f, 1.0f}, tex_side},
		{{ 0.5f,  0.5f, -0.5f}, c_white, {1.0f, 1.0f}, tex_side},
		{{ 0.5f, -0.5f, -0.5f}, c_white, {1.0f, 0.0f}, tex_side},
		{{ 0.5f, -0.5f, -0.5f}, c_white, {1.0f, 0.0f}, tex_side},
		{{ 0.5f, -0.5f,  0.5f}, c_white, {0.0f, 0.0f}, tex_side},
		{{ 0.5f,  0.5f,  0.5f}, c_white, {0.0f, 1.0f}, tex_side},

		/* bottom face (y = -0.5) */
		{{-0.5f, -0.5f, -0.5f}, c_white, {0.0f, 1.0f}, tex_bottom},
		{{ 0.5f, -0.5f, -0.5f}, c_white, {1.0f, 1.0f}, tex_bottom},
		{{ 0.5f, -0.5f,  0.5f}, c_white, {1.0f, 0.0f}, tex_bottom},
		{{ 0.5f, -0.5f,  0.5f}, c_white, {1.0f, 0.0f}, tex_bottom},
		{{-0.5f, -0.5f,  0.5f}, c_white, {0.0f, 0.0f}, tex_bottom},
		{{-0.5f, -0.5f, -0.5f}, c_white, {0.0f, 1.0f}, tex_bottom},

		/* top face (y = 0.5) */
		{{-0.5f,  0.5f, -0.5f}, c_green, {0.0f, 1.0f}, tex_top},
		{{ 0.5f,  0.5f, -0.5f}, c_green, {1.0f, 1.0f}, tex_top},
		{{ 0.5f,  0.5f,  0.5f}, c_green, {1.0f, 0.0f}, tex_top},
		{{ 0.5f,  0.5f,  0.5f}, c_green, {1.0f, 0.0f}, tex_top},
		{{-0.5f,  0.5f,  0.5f}, c_green, {0.0f, 0.0f}, tex_top},
		{{-0.5f,  0.5f, -0.5f}, c_green, {0.0f, 1.0f}, tex_top}
	};

	return new Mesh(vertices);
}
