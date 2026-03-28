#ifndef SHADER_H
#define SHADER_H

#include <string>
#include "glad/glad.h"

class Shader {
private:
	GLuint id;
	GLuint compile_shader(GLenum type, const unsigned char *code, int len, const std::string& type_name);
public:
	Shader(const unsigned char *v_code, int v_len, const unsigned char *f_code, int f_len);
	
	void use();
};
#endif
