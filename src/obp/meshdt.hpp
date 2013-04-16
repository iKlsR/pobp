#ifndef __MESHDT_HPP__
#define __MESHDT_HPP__

#include <GL/glew.h>

#include "common.hpp"

#define OBP_GC 0.420

static const GLfloat obp_triangle_vertices[] = {

    //XYZ                   RGB
     0.0f,  1.0f, 0.0f,     1.0, 0.0, 0.0,
    -1.0f, -1.0f, 0.0f,     0.0, 1.0, 0.0,
     1.0f, -1.0f, 0.0f,     0.0, 0.0, 1.0
};

static const GLushort obp_triangle_elements[] = {

    0, 1, 2
};

static const GLfloat obp_gplane_vertices[] = {

    //XYZ                   RGB                 UV
    -6.0f, 0.0f,  6.0f,     0.5, 0.5, 0.5,      0.0, 0.0,
    -6.0f, 0.0f, -6.0f,     0.5, 0.5, 0.5,      1.0, 0.0,
     6.0f, 0.0f,  6.0f,     0.5, 0.5, 0.5,      0.0, 1.0,
     6.0f, 0.0f, -6.0f,     0.5, 0.5, 0.5,      1.0, 1.0
};

static const GLushort obp_gplane_elements[] = {

    0, 1, 2,
    2, 1, 3
};

static const GLfloat obp_rect_vertices[] = {

    //XYZ                   RGB                 UV
    -1.0f,  1.0f, 0.0f,     1.0, 0.0, 0.0,      0.0, 0.0,
    -1.0f, -1.0f, 0.0f,     0.0, 1.0, 0.0,      1.0, 0.0,     
     1.0f,  1.0f, 0.0f,     0.0, 0.0, 1.0,      0.0, 1.0,
     1.0f, -1.0f, 0.0f,     1.0, 1.0, 1.0,      1.0, 1.0

};

static const GLushort obp_rect_elements[] = {

    0, 1, 2,
    2, 1, 3
};

static const GLfloat obp_cube_vertices[] = {

    //XYZ                   RGB                 UV
    -size,  size, size,     1.0, 0.0, 0.0,      0.0, 0.0,
    -size, -size, size,     1.0, 0.0, 0.0,      1.0, 0.0,     
     size,  size, size,     1.0, 0.0, 0.0,      0.0, 1.0,
     size, -size, size,     1.0, 0.0, 0.0,      1.0, 1.0,

    -size,  size,  size,    0.0, 1.0, 0.0,      0.0, 0.0,
    -size, -size,  size,    0.0, 1.0, 0.0,      1.0, 0.0,
    -size,  size, -size,    0.0, 1.0, 0.0,      0.0, 1.0,
    -size, -size, -size,    0.0, 1.0, 0.0,      1.0, 1.0,

    -size, -size,  size,    0.0, 0.0, 1.0,      0.0, 0.0,
    -size, -size, -size,    0.0, 0.0, 1.0,      1.0, 0.0,
     size, -size,  size,    0.0, 0.0, 1.0,      0.0, 1.0,
     size, -size, -size,    0.0, 0.0, 1.0,      1.0, 1.0,

    -size,  size, -size,    1.0, 0.0, 1.0,      0.0, 0.0,
    -size, -size, -size,    1.0, 0.0, 1.0,      1.0, 0.0,     
     size,  size, -size,    1.0, 0.0, 1.0,      0.0, 1.0,
     size, -size, -size,    1.0, 0.0, 1.0,      1.0, 1.0,

     size,  size,  size,    1.0, 1.0, 0.0,      0.0, 0.0,
     size, -size,  size,    1.0, 1.0, 0.0,      1.0, 0.0,
     size,  size, -size,    1.0, 1.0, 0.0,      0.0, 1.0,
     size, -size, -size,    1.0, 1.0, 0.0,      1.0, 1.0,

    -size,  size,  size,    0.0, 1.0, 1.0,      0.0, 0.0,
    -size,  size, -size,    0.0, 1.0, 1.0,      1.0, 0.0,
     size,  size,  size,    0.0, 1.0, 1.0,      0.0, 1.0,
     size,  size, -size,    0.0, 1.0, 1.0,      1.0, 1.0

};

static const GLushort obp_cube_elements[] = {

    0, 1, 2,
    2, 1, 3,

    4, 5, 6,
    6, 5, 7,

    8,  9, 10,
    10, 9, 11,

    12, 13, 14,
    14, 13, 15,

    16, 17, 18,
    18, 17, 19,

    20, 21, 22,
    22, 21, 23
};

static const GLfloat obp_grid_vertices[] = {

    //XYZ                   RGB                 
    -4.0f,  0.0f, -5.0f,    OBP_GC, OBP_GC, OBP_GC,
    -4.0f,  0.0f,  5.0f,    OBP_GC, OBP_GC, OBP_GC,

    -3.0f,  0.0f, -5.0f,    OBP_GC, OBP_GC, OBP_GC, 
    -3.0f,  0.0f,  5.0f,    OBP_GC, OBP_GC, OBP_GC,

    -2.0f,  0.0f, -5.0f,    OBP_GC, OBP_GC, OBP_GC, 
    -2.0f,  0.0f,  5.0f,    OBP_GC, OBP_GC, OBP_GC,

    -1.0f,  0.0f, -5.0f,    OBP_GC, OBP_GC, OBP_GC, 
    -1.0f,  0.0f,  5.0f,    OBP_GC, OBP_GC, OBP_GC, 

     0.0f,  0.0f, -5.0f,    0.0, OBP_GC, 0.0,   
     0.0f,  0.0f,  5.0f,    0.0, OBP_GC, 0.0,

     1.0f,  0.0f, -5.0f,    OBP_GC, OBP_GC, OBP_GC,
     1.0f,  0.0f,  5.0f,    OBP_GC, OBP_GC, OBP_GC,

     2.0f,  0.0f, -5.0f,    OBP_GC, OBP_GC, OBP_GC, 
     2.0f,  0.0f,  5.0f,    OBP_GC, OBP_GC, OBP_GC,

     3.0f,  0.0f, -5.0f,    OBP_GC, OBP_GC, OBP_GC, 
     3.0f,  0.0f,  5.0f,    OBP_GC, OBP_GC, OBP_GC,

     4.0f,  0.0f, -5.0f,    OBP_GC, OBP_GC, OBP_GC,
     4.0f,  0.0f,  5.0f,    OBP_GC, OBP_GC, OBP_GC,

    -5.0f,  0.0f, -4.0f,    OBP_GC, OBP_GC, OBP_GC,
     5.0f,  0.0f, -4.0f,    OBP_GC, OBP_GC, OBP_GC,

    -5.0f,  0.0f, -3.0f,    OBP_GC, OBP_GC, OBP_GC,
     5.0f,  0.0f, -3.0f,    OBP_GC, OBP_GC, OBP_GC,

    -5.0f,  0.0f, -2.0f,    OBP_GC, OBP_GC, OBP_GC,
     5.0f,  0.0f, -2.0f,    OBP_GC, OBP_GC, OBP_GC,

    -5.0f,  0.0f, -1.0f,    OBP_GC, OBP_GC, OBP_GC, 
     5.0f,  0.0f, -1.0f,    OBP_GC, OBP_GC, OBP_GC,

    -5.0f,  0.0f,  0.0f,    OBP_GC, 0.0, 0.0,   
     5.0f,  0.0f,  0.0f,    OBP_GC, 0.0, 0.0,

    -5.0f,  0.0f,  4.0f,    OBP_GC, OBP_GC, OBP_GC, 
     5.0f,  0.0f,  4.0f,    OBP_GC, OBP_GC, OBP_GC,

    -5.0f,  0.0f,  3.0f,    OBP_GC, OBP_GC, OBP_GC, 
     5.0f,  0.0f,  3.0f,    OBP_GC, OBP_GC, OBP_GC,

    -5.0f,  0.0f,  2.0f,    OBP_GC, OBP_GC, OBP_GC, 
     5.0f,  0.0f,  2.0f,    OBP_GC, OBP_GC, OBP_GC,

    -5.0f,  0.0f,  1.0f,    OBP_GC, OBP_GC, OBP_GC,
     5.0f,  0.0f,  1.0f,    OBP_GC, OBP_GC, OBP_GC,

     //borders
    -5.0f,  0.0f, -5.0f,    OBP_GC, OBP_GC, OBP_GC,
    -5.0f,  0.0f,  5.0f,    OBP_GC, OBP_GC, OBP_GC,

     5.0f,  0.0f, -5.0f,    OBP_GC, OBP_GC, OBP_GC, 
     5.0f,  0.0f,  5.0f,    OBP_GC, OBP_GC, OBP_GC,

    -5.0f,  0.0f,  -5.0f,   OBP_GC, OBP_GC, OBP_GC, 
     5.0f,  0.0f,  -5.0f,   OBP_GC, OBP_GC, OBP_GC,

    -5.0f,  0.0f,   5.0f,   OBP_GC, OBP_GC, OBP_GC, 
     5.0f,  0.0f,   5.0f,   OBP_GC, OBP_GC, OBP_GC,

};

static const GLushort obp_grid_elements[] = {

    //
};

#endif