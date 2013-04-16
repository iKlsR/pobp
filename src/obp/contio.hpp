#ifndef __CONTIO_HPP__
#define __CONTIO_HPP__

#include <GL/glfw.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "events.hpp"

#define PI 3.14159

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix () {

    return ViewMatrix;
}

glm::mat4 getProjectionMatrix () {

    return ProjectionMatrix;
}

glm::vec3 position = glm::vec3(0.0f, 0.0f, 10.0f); 

float horizontalAngle = PI;
float verticalAngle = 0.0f;

float initial_fov = 45.0f;

float speed = 3.0f; 
float mouseSpeed = 0.00059f;
float mouseRotateSpeed = 0.05f;

void obp_fps () {

    static double lastTime = glfwGetTime();

    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);

    int xpos, ypos;
    glfwGetMousePos(&xpos, &ypos);

    glfwSetMousePos(obp_window_width /2, obp_window_height /2);

    horizontalAngle += mouseSpeed * float(obp_window_width  /2 - xpos);
    verticalAngle   += mouseSpeed * float(obp_window_height /2 - ypos);

    glm::vec3 direction(

        cos(verticalAngle) * sin(horizontalAngle), 
        sin(verticalAngle),
        cos(verticalAngle) * cos(horizontalAngle)
    );
    
    glm::vec3 right = glm::vec3(
        sin(horizontalAngle - (PI /2.0f)), 
        0.0f,
        cos(horizontalAngle - (PI /2.0f))
    );
    
    glm::vec3 up = glm::cross(right, direction);

    if (glfwGetKey('W') == GLFW_PRESS) {

        position += direction * deltaTime * speed;
    }

    if (glfwGetKey('S') == GLFW_PRESS) {

        position -= direction * deltaTime * speed;
    }

    if (glfwGetKey('D') == GLFW_PRESS) {

        position += right * deltaTime * speed;
    }

    if (glfwGetKey('A') == GLFW_PRESS) {

        position -= right * deltaTime * speed;
    }
    
    if (glfwGetKey(GLFW_KEY_LSHIFT) == GLFW_PRESS) {

        speed = 10.0f;

    } else {

        speed = 3.0f;
    }

    float fov = initial_fov - 5 * glfwGetMouseWheel();

    ProjectionMatrix = glm::perspective(fov, float(obp_window_width) / float(obp_window_height), 0.1f, 100.0f);
    ViewMatrix       = glm::lookAt(
        position,           
        position + direction, 
        up                  
    );

    lastTime = currentTime;
}

void obp_trackball_rot () {

    int xpos, ypos;
    glfwGetMousePos(&xpos, &ypos);

    glfwSetMousePos(obp_window_width /2, obp_window_height /2);

    verticalAngle   += mouseRotateSpeed * float(obp_window_width  /2 - xpos);
    horizontalAngle += mouseRotateSpeed * float(obp_window_height /2 - ypos);
        
    if (horizontalAngle >=  89.99) horizontalAngle =  89.99;
    if (horizontalAngle <= -89.99) horizontalAngle = -89.99;

    float initial_distance = 10;

    float distance = initial_distance - 1.0f * glfwGetMouseWheel();

    float camX =  distance * -sinf(verticalAngle     * (PI / 180)) * cosf((horizontalAngle) * (PI / 180));
    float camY =  distance * -sinf((horizontalAngle) * (PI / 180));
    float camZ = -distance *  cosf((verticalAngle)   * (PI / 180)) * cosf((horizontalAngle) * (PI / 180));

    ProjectionMatrix = glm::perspective(initial_fov, float(obp_window_width) / float(obp_window_height), 0.1f, 100.0f);

    ViewMatrix       = glm::lookAt(
                            glm::vec3(camX, camY, camZ),           
                            glm::vec3(0.0f, 0.0f, 0.0f), 
                            glm::vec3(0.0f, 1.0f, 0.0f));            
}

void obp_accurate_3d () {

    //work in progress

    float camX =  0.0f;
    float camY =  15.0f;
    float camZ =  0.1f;

    ProjectionMatrix = glm::perspective(initial_fov, float(obp_window_width) / float(obp_window_height), 0.1f, 100.0f);

    ViewMatrix       = glm::lookAt(
                            glm::vec3(camX, camY, camZ),           
                            glm::vec3(0.0f, 0.0f, 0.0f), 
                            glm::vec3(0.0f, 1.0f, 0.0f));            
}

bool obp_camera_type (int cam_type) {

    switch (cam_type) {

        case 1:
        
            obp_fps();
            break;
            
        case 2:
        
            obp_trackball_rot();
            break;
            
        case 3:
        
            obp_accurate_3d();
            break;
        }
}

#endif