#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex> &vertices) {
	vertex_count = vertices.size();
	position = glm::vec3(0.0f);
	rotation = glm::vec3(0.0f);
	scale = glm::vec3(1.0f);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, position));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, color));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, tex_coords));
	glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, tex_index));
	glEnableVertexAttribArray(0); /* pos */
	glEnableVertexAttribArray(1); /* color */
	glEnableVertexAttribArray(2); /* uv */
	glEnableVertexAttribArray(3); /* tex index */

	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glBindVertexArray(0);
}

void Mesh::draw() {
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, vertex_count);
	glBindVertexArray(0);
}

glm::mat4 Mesh::get_model_matrix() {
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, scale);
	return model;
}

glm::vec3 &Mesh::get_position() { return position; }
glm::vec3 &Mesh::get_rotation() { return rotation; }
glm::vec3 &Mesh::get_scale() { return scale; }

void Mesh::set_position(glm::vec3 pos) { position = pos; }
void Mesh::set_rotation(glm::vec3 rot) { rotation = rot; }
void Mesh::set_scale(glm::vec3 scl) { scale = scl; }

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}
