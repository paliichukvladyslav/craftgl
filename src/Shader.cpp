#include <iostream>

#include "Shader.h"

GLuint Shader::compile_shader(GLenum type, const unsigned char *code, int len, const std::string& type_name) {
	const GLchar* source = reinterpret_cast<const GLchar*>(code);
	GLint length = static_cast<GLint>(len);

	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, &length);
	glCompileShader(shader);

	int success;
	char info_log[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(shader, 512, NULL, info_log);
		std::cout << "ERROR::SHADER::" << type_name << "::COMPILATION_FAILED\n" << info_log << "\n";
	}

	return shader;
}

Shader::Shader(const unsigned char *v_code, int v_len, const unsigned char *f_code, int f_len) {

	GLuint vertex_s = compile_shader(GL_VERTEX_SHADER, v_code, v_len, "VERTEX");
	GLuint fragment_s = compile_shader(GL_FRAGMENT_SHADER, f_code, f_len, "FRAGMENT");

	id = glCreateProgram();
	glAttachShader(id, vertex_s);
	glAttachShader(id, fragment_s);
	glLinkProgram(id);

	int success;
	char info_log[512];
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if(!success) {
		glGetProgramInfoLog(id, 512, NULL, info_log);
		std::cout << "ERROR::SHADER::VERTEX::LINKAGE_FAILED\n" << info_log << "\n";
	}

	glDeleteShader(vertex_s);
	glDeleteShader(fragment_s);
}

void Shader::use() {
	glUseProgram(id);
}


