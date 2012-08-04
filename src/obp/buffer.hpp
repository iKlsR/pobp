#ifndef __BUFFER_HPP__
#define __BUFFER_HPP__

#include <GL/glew.h>

static struct {

	GLuint vertex_array;
	GLuint vertex_buffer, element_buffer, normal_buffer;
	GLuint texture;

} obp_resources;

GLuint obp_make_vao () {

	GLuint vertex_array;
	glGenVertexArrays(1, &vertex_array);
	glBindVertexArray(vertex_array);

	return vertex_array;
};

GLuint obp_make_buffer (GLenum target, GLsizei buffer_size, const void * buffer_data) {

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(target, buffer);
	glBufferData(target, buffer_size, buffer_data, GL_STATIC_DRAW);

	return buffer;
}

GLuint obp_bind_buffer (GLenum target, GLuint buffer) {

	glBindBuffer(target, buffer);

	return buffer;
}

GLuint obp_bind_vao (GLuint vao) {

	GLuint vaoId = vao;
	glBindVertexArray(vaoId);

	return vaoId;
}

#endif