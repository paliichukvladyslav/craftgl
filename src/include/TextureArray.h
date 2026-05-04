#ifndef TEXTURE_ARRAY_H
#define TEXTURE_ARRAY_H

#include <vector>
#include <string>
#include "glad/glad.h"

class TextureArray {
private:
	GLuint id;
	int width, height, layer_count;
public:
	TextureArray(std::vector<std::string> &file_paths);
	~TextureArray();

	void bind(GLuint unit);
};

#endif
