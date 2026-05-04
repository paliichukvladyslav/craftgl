#include "TextureArray.h"
#include "Image.h"
#include <iostream>

TextureArray::TextureArray(std::vector<std::string> &file_paths) {
	layer_count = file_paths.size();

	std::vector<Image *> images;
	for (const auto &path : file_paths) {
		images.push_back(new Image(path));
	}

	width = images[0]->get_width();
	height = images[0]->get_height();

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D_ARRAY, id);

	glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA8, width, height, layer_count, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

	for (int i = 0; i < layer_count; i++) {
		glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, width, height, 1, GL_RGBA, GL_UNSIGNED_BYTE, images[i]->get_data());
	}

	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glGenerateMipmap(GL_TEXTURE_2D_ARRAY);

	for (auto img : images) delete img;

	glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

TextureArray::~TextureArray() {
	if (id != 0) {
		glDeleteTextures(1, &id);
	}
}

void TextureArray::bind(GLuint unit) {
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D_ARRAY, id);
}
