#ifndef __EVENTS_HPP__
#define __EVENTS_HPP__

#include <GL/glfw.h>

extern bool running;

int obp_window_width = 800,
	obp_window_height  = 600,
	obp_window_handle = 0;

GLFWCALL void obp_window_size_callback (int width, int height) {
    
    glViewport(0, 0, width, height); 
    glfwGetWindowSize(&obp_window_width, &obp_window_height);   
}

GLFWCALL void obp_event_key_callback (int key, int action) {
    
    if(GLFW_PRESS && glfwGetWindowParam(GLFW_OPENED)) {
        
        if(glfwGetKey(GLFW_KEY_ESC)) {
            
            running = false; 
        }
    }
}

GLFWCALL void obp_event_mouse_callback (int character, int action) {
    
    if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_MIDDLE)) {
        
        running = false;
    }  
}

void obp_callbacks (bool key, bool mouse) {

	if (key)
		glfwSetKeyCallback(obp_event_key_callback);

	if (mouse)
		glfwSetMouseButtonCallback(obp_event_mouse_callback);

	glfwSetWindowSizeCallback(obp_window_size_callback);
}

#endif