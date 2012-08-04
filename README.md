##`pobp`

This project uses:

[GLFW](http://glfw.org)

[GLEW](http://glew.sourceforge.net)

[SOIL](http://http://lonesock.net/soil.html)

[GLM](http://glm.g-truc.net/)

##_Functions_

**buffer.hpp**

`obp_make_vao();`
* takes no paramters but returns a unique vertex array id.

`obp_make_buffer(GLenum target, GLsizei buffer_size, const void * buffer_data);`
* takes the target BUFFER, buffer size and the buffer data(ie the vertices, indices etc) and returns a unique buffer id

`obp_bind_buffer(GLenum target, GLuint buffer);`
* takes the buffer to rebind and its target BUFFER(used when drawing multiple meshes, models etc) and returns said buffer

`obp_bind_vao(GLuint vao)`
* takes the vertex array to rebind(ideal for multiple shaders)

**common.hpp**

`obp_gl_info(void)`
* returns graphics vendor, opengl major and minor version, glsl version and number of processors(thanks glfw)

**contio.hpp**

`getViewMatrix()`
* gets the view matrix of the current camera type and returns it

`getProjectionMatrix()`
* gets the projection matrix of the current camera type and returns it

`obp_fps()`
* creates a free moving fps style camera that can be used to navigate the scene, use mousewheel to adjust FoV, WASD to accelerate, decelerate and strafe, mouse to change direction

`obp_trackball_rot()`
* creates a 3d software type camera that looks at the object and rotates around it(axis locks at top and bottom)

`obp_accurate_3d()`
* creates a 3d software type camera that looks at the object in straight orthogonal directions, top, bottom, left, right etc [WIP]

`obp_camera_type()`
* master function of the header that is used to choose what camera type to use at runtime(this is the function to use in the mainloop)

**loader.hpp**

`obp_load_image(const char * file_path, GLenum active_texture)`
* accepts the path to _any_ valid image file and the active texture to map it to, returns the image after it has been binded and doctored

`obp_load_shaders_ff(const char * vertex_file_path, const char * fragment_file_path)`
* loads a vertex and fragment shader from (a) file(s) and doctors them, returns a shader program and also does error checking

`obp_load_shaders_fm(const char * vertex_file_path, const char * fragment_file_path)`
* loads a vertex and fragment shader from memory(a const GLchar var) and doctors them, returns a shader program and also does error checking

`obp_load_obj(const char * path, vector<vec3> & out_vertices, vector<vec2> & out_uvs, vector<vec3> & out_normals)`
* simple .obj parser, accepts a path and 3 holder variables, it returns the values back to the function parameters, also does a little smart checking[WIP]

