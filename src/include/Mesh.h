#ifndef MESH_H
#define MESH_H

#include <vector>
#include "glad/glad.h"

class Mesh {
private:
	GLuint vao, vbo;
	int vertex_count;
public:
	Mesh(const std::vector<float> &vertices);
	~Mesh();
	void draw();
};

#endif
