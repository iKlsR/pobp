#ifndef __COMMON_HPP__
#define __COMMON_HPP__

#include <cstdio>

#include <GL/glew.h>
#include <GL/glfw.h>

#define OBP_SUCCESS  0
#define OBP_FAILURE -1
#define OBP_NULL	 NULL

#define TRI_FACE	 6
float size = 1.0f;

void obp_gl_info (void) {

	const GLubyte * renderer = glGetString(GL_RENDERER);
	const GLubyte * vendor = glGetString(GL_VENDOR);
	const GLubyte * ogl_version = glGetString(GL_VERSION);
	const GLubyte * glsl_version = glGetString(GL_SHADING_LANGUAGE_VERSION);
	int num_cores = glfwGetNumberOfProcessors();

	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);

	fprintf(stdout, "INFO: Vendor   - %s\n", vendor);
	fprintf(stdout, "INFO: Renderer - %s\n", renderer);
	fprintf(stdout, "INFO: GLSL Version : %s\n", glsl_version);
	fprintf(stdout, "INFO: OpenGL Version <str> - %s\n", ogl_version);
	fprintf(stdout, "INFO: OpenGL Version <int> - %d.%d\n", major, minor);
	fprintf(stdout, "INFO: Cores - %d\n", num_cores);
}

#endif