#include <iostream>
#include <stdio.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>
#include <GL/glfw.h>

#include "obp/events.hpp"
#include "obp/common.hpp"
#include "obp/meshdt.hpp"
#include "obp/buffer.hpp"
#include "obp/loader.hpp"
#include "obp/shader.hpp"
#include "obp/contio.hpp"

bool running = true;

#define obp_window_title "obp"

int main (int argc, char * argvs[]) {

	glfwInit();

	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 4);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 0);
	glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	obp_window_handle = glfwOpenWindow(obp_window_width, obp_window_height, 0, 0, 0, 0, 32, 0, GLFW_WINDOW);
	glfwSetWindowTitle(obp_window_title);

	obp_gl_info();

	obp_callbacks(true, true);

	GLenum glewInitResult = glewInit();

	glfwEnable(GLFW_STICKY_KEYS);
	glfwEnable(GLFW_STICKY_MOUSE_BUTTONS);

	glEnable(GL_DEPTH_TEST);

	GLint posAttrib, colAttrib, uvAttrib, norAttrib;
	GLuint programId;  

	{	//create and allocate stuff here

	}  

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	while (running) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		{	// * calculate camera transformations here   

		}   

		{	// * call draw methods here  

		}

		glfwSwapBuffers();
	}

	{	//destroy resources here

	}

	glfwTerminate();
	return OBP_SUCCESS;
}
