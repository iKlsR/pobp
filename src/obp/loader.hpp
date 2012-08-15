#ifndef __LOADER_HPP__
#define __LOADER_HPP__

#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>

#include <SOIL/SOIL.h>

#include <glm/glm.hpp>

#include <GL/glew.h>

using namespace std;
typedef string str;

GLuint obp_load_image (const char * file_path, GLenum active_texture) {

	GLuint textureId;
	glGenTextures(1, &textureId);

    glActiveTexture(active_texture);
	glBindTexture(GL_TEXTURE_2D, textureId);
		
	int width, height;
	unsigned char * image = SOIL_load_image(file_path, &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);
		
	return textureId;	
}

GLuint obp_load_shaders_ff (const char * vertex_file_path, const char * fragment_file_path) {
	
	GLuint vertexShaderId   = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	GLuint programId        = glCreateProgram();

	GLint result = GL_FALSE;
	int infoLogLength;
	str line = "";
	
	str vertexShaderCode = "";
	ifstream vertexShaderStream(vertex_file_path, ios::in);
	if(vertexShaderStream.is_open()) {
		
		while(getline(vertexShaderStream, line))
			vertexShaderCode += line + "\n";
		vertexShaderStream.close();
	}
	
	str fragmentShaderCode = "";
	ifstream fragmentShaderStream(fragment_file_path, ios::in);
	if(fragmentShaderStream.is_open()) {
		
		while(getline(fragmentShaderStream, line))
			fragmentShaderCode += line + "\n";
		fragmentShaderStream.close();
	}

	const char * vertexSourcePointer = vertexShaderCode.c_str();	
	glShaderSource(vertexShaderId, 1, &vertexSourcePointer, NULL);
	glCompileShader(vertexShaderId);

	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
	std::vector<char> vertexShaderErrorMessage(infoLogLength);
	glGetShaderInfoLog(vertexShaderId, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &vertexShaderErrorMessage[0]);
	
	const char * fragmentSourcePointer = fragmentShaderCode.c_str();	
	glShaderSource(fragmentShaderId, 1, &fragmentSourcePointer, NULL);
	glCompileShader(fragmentShaderId);

	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragmentShaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
	std::vector<char> fragmentShaderErrorMessage(infoLogLength);
	glGetShaderInfoLog(fragmentShaderId, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &fragmentShaderErrorMessage[0]);
	
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glLinkProgram(programId);
	
	glGetProgramiv(programId, GL_LINK_STATUS, &result);
	glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
	std::vector<char> programErrorMessage(max(infoLogLength, int(1)));
	glGetProgramInfoLog(programId, infoLogLength, NULL, &programErrorMessage[0]);
	fprintf(stdout, "%s\n", &programErrorMessage[0]);
 
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);
 
	return programId;
}

GLuint obp_load_shaders_fm (const GLchar * vertex_shader, const GLchar * fragment_shader) {
    
    GLuint vertexShaderId   = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    GLuint programId        = glCreateProgram();

    GLint result = GL_FALSE;
    char buffer[512 + 1];

    glShaderSource(vertexShaderId, 1, &vertex_shader, NULL);
    glCompileShader(vertexShaderId);

    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &result);
    //glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH, buffer);
    glGetShaderInfoLog(vertexShaderId, 512, NULL, buffer);
    fprintf(stdout, "%s\n", buffer);
    
    glShaderSource(fragmentShaderId, 1, &fragment_shader, NULL);
    glCompileShader(fragmentShaderId);

    glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &result);
    //glGetShaderiv(fragmentShaderId, GL_INFO_LOG_LENGTH, buffer);
    glGetShaderInfoLog(fragmentShaderId, 512, NULL, buffer);
    fprintf(stdout, "%s\n", buffer);
    
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);
    
    glGetProgramiv(programId, GL_LINK_STATUS, &result);
    //glGetProgramiv(programId, GL_INFO_LOG_LENGTH, buffer);
    glGetProgramInfoLog(programId, 512, NULL, buffer);
    fprintf(stdout, "%s\n", buffer);
 
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
 
    return programId;
}

GLuint obp_load_cmap (const char * xpos, const char * xneg, const char * ypos, const char * yneg, const char * zpos, const char * zneg, GLenum active_texture) {

    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);
    
    glEnable(GL_TEXTURE_CUBE_MAP);
    glActiveTexture(active_texture);
    
    int xpos_width, xpos_height, ypos_width, ypos_height, zpos_width, zpos_height;
    int xneg_width, xneg_height, yneg_width, yneg_height, zneg_width, zneg_height;

    unsigned char * xpos_image = SOIL_load_image(xpos, &xpos_width, &xpos_height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, xpos_width, xpos_height, 0, GL_RGB, GL_UNSIGNED_BYTE, xpos_image);
    SOIL_free_image_data(xpos_image);
    unsigned char * xneg_image = SOIL_load_image(xneg, &xneg_width, &xneg_height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, xneg_width, xneg_height, 0, GL_RGB, GL_UNSIGNED_BYTE, xneg_image);
    SOIL_free_image_data(xneg_image);
    unsigned char * ypos_image = SOIL_load_image(ypos, &ypos_width, &ypos_height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, ypos_width, ypos_height, 0, GL_RGB, GL_UNSIGNED_BYTE, ypos_image);
    SOIL_free_image_data(ypos_image);
    unsigned char * yneg_image = SOIL_load_image(yneg, &yneg_width, &yneg_height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, yneg_width, yneg_height, 0, GL_RGB, GL_UNSIGNED_BYTE, yneg_image);
    SOIL_free_image_data(yneg_image);
    unsigned char * zpos_image = SOIL_load_image(zpos, &zpos_width, &zpos_height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, zpos_width, zpos_height, 0, GL_RGB, GL_UNSIGNED_BYTE, zpos_image);
    SOIL_free_image_data(zpos_image);
    unsigned char * zneg_image = SOIL_load_image(zneg, &zneg_width, &zneg_height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, zneg_width, zneg_height, 0, GL_RGB, GL_UNSIGNED_BYTE, zneg_image);
    SOIL_free_image_data(zneg_image);
    
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
   
    return textureId;   
}

bool obp_load_obj (const char * path, std::vector<glm::vec3> & out_vertices, std::vector<glm::vec2> & out_uvs, std::vector<glm::vec3> & out_normals) {
    
    printf("INFO: Loading OBJ file %s.\n", path);

    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    
    std::vector<glm::vec3> temp_vertices; 
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;

    bool uvsfound = false;

    FILE * file = fopen(path, "r");
    if (file == NULL) {

        printf("ERROR: File could not be loaded! Are you in the right path?\n");
        return false;
    }

    while (true) {

        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break;
        
        if (strcmp(lineHeader, "v") == 0 ) {

            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            temp_vertices.push_back(vertex);

        } else if (strcmp(lineHeader, "vt") == 0 ) {

            uvsfound = true;

            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y );
            temp_uvs.push_back(uv);

        } else if (strcmp( lineHeader, "vn") == 0) {

            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            temp_normals.push_back(normal);

        } else if (strcmp(lineHeader, "f") == 0) {

            if (!uvsfound) {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[4], normalIndex[4];
            int matches = fscanf(file, "%d//%d %d//%d %d//%d\n", &vertexIndex[0], &normalIndex[0], 
                                                                 &vertexIndex[1], &normalIndex[1], 
                                                                 &vertexIndex[2], &normalIndex[2], 
                                                                 &vertexIndex[3], &normalIndex[3]);
             
            if (matches != 6) {

                printf("ERROR: File could not be read!\n");
                return false;
            }
            
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);

        } else {

            //uvs found!
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], 
                                                                       &vertexIndex[1], &uvIndex[1], &normalIndex[1], 
                                                                       &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

            if (matches != 9) {

                printf("ERROR: File could not be read!\n");
                return false;

            }

            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices    .push_back(uvIndex[0]);
            uvIndices    .push_back(uvIndex[1]);
            uvIndices    .push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
            }    
        }
    }

    if (uvsfound) {
    
        printf("INFO: UVs were found!\n");

    for (unsigned int i = 0; i < vertexIndices.size(); i++) {

        unsigned int vertexIndex = vertexIndices[i];
        unsigned int uvIndex = uvIndices[i];
        unsigned int normalIndex = normalIndices[i];
        
        glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
        glm::vec2 uv = temp_uvs[ uvIndex-1 ];
        glm::vec3 normal = temp_normals[ normalIndex-1 ];
        
        out_vertices.push_back(vertex);
        out_uvs     .push_back(uv);
        out_normals .push_back(normal);
        
        }
        
    } else {

        printf("INFO: No UVs were found!\n");

        for (unsigned int i = 0; i < vertexIndices.size(); i++) {

            unsigned int vertexIndex = vertexIndices[i];
            unsigned int normalIndex = normalIndices[i];
            
            glm::vec3 vertex = temp_vertices[vertexIndex - 1];
            glm::vec3 normal = temp_normals[normalIndex - 1];
            
            out_vertices.push_back(vertex);
            out_normals.push_back(normal);
        }
    }
    
    printf("INFO: Loaded file %s successfully.\n", path);
    return true;
}

#endif