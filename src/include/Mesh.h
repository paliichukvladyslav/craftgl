#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glad/glad.h"

struct Vertex {
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 tex_coords;
	float tex_index; // -1 if none
};

class Mesh {
private:
	GLuint vao, vbo;
	int vertex_count;
	glm::vec3 position, rotation, scale;
public:
	Mesh(std::vector<Vertex> &vertices);
	~Mesh();
	glm::mat4 get_model_matrix();
	void draw();

	glm::vec3 &get_position();
	glm::vec3 &get_rotation();
	glm::vec3 &get_scale();

	void set_position(glm::vec3 pos);
	void set_rotation(glm::vec3 rot);
	void set_scale(glm::vec3 scl);
};

#endif
