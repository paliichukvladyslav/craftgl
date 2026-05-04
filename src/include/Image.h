#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image {
private:
	unsigned char *data;
	int width, height, channels;
public:
	Image(const std::string &path);
	~Image();

	Image(Image &) = delete;
	Image& operator=(Image &) = delete;

	unsigned char *get_data();
	int get_width();
	int get_height();
	int get_channels();
};

#endif
