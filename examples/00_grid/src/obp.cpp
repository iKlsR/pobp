
#include <iostream>
#include <cstdio>

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

    {
        glfwSetMousePos(obp_window_width /2, obp_window_height /2);
        glfwDisable(GLFW_MOUSE_CURSOR);
    }   

    GLint posAttrib, colAttrib, uvAttrib, norAttrib;
    GLuint programId;  

    {
        obp_resources.vertex_array   = obp_make_vao();
        obp_resources.vertex_buffer  = obp_make_buffer(GL_ARRAY_BUFFER, sizeof(obp_grid_vertices), obp_grid_vertices);

        {
            programId = obp_load_shaders_ff("shaders\\vertex.shader", "shaders\\frag.shader");
            glUseProgram(programId);

            glBindFragDataLocation(programId, 0, "out_Color");

            posAttrib = glGetAttribLocation(programId, "in_Position");
            colAttrib = glGetAttribLocation(programId, "in_Color");
            //uvAttrib  = glGetAttribLocation(programId, "in_Uvs");

            glEnableVertexAttribArray(posAttrib);
            glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);

            glEnableVertexAttribArray(colAttrib);
            glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
        } 
	}  


    glClearColor(0.1f, 0.1, 0.1f, 1.0f);

	while (running) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        {   
    		obp_camera_type(2);

            GLint uniProjection, uniView, uniModel;
            glm::mat4 projection, view, model;

            uniProjection = glGetUniformLocation(programId, "projection");
            uniView       = glGetUniformLocation(programId, "view");
            uniModel      = glGetUniformLocation(programId, "model");

    		projection = getProjectionMatrix();
    		view       = getViewMatrix();
            model      = glm::mat4(1.0f);

            glUniformMatrix4fv(uniProjection, 1, GL_FALSE, glm::value_ptr(projection));
            glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(model));
        }   

        {   
            glDrawArrays(GL_LINES, 0, 44);
        }

		glfwSwapBuffers();
	}

	{  

	}

	glfwTerminate();
	return OBP_SUCCESS;
}