#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Image.h"
#include <iostream>
#include <stdexcept>

Image::Image(const std::string &path) {
	stbi_set_flip_vertically_on_load(true);

	data = stbi_load(path.c_str(), &width, &height, &channels, 4);
	if (!data) {
		throw std::runtime_error("Image: Failed to load " + path);
	}
}

Image::~Image() {
	if (data) {
		stbi_image_free(data);
	}
}

unsigned char *Image::get_data() { return data; }
int Image::get_width() { return width; }
int Image::get_height() { return height; }
int Image::get_channels() { return channels; }
