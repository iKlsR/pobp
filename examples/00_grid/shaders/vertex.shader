#version 400

in vec3 in_Color;
//in vec2 in_Uvs;
in vec3 in_Position;

out vec3 color;
//out vec2 uvs;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

mat4 ModelViewProjection;

void main() {
	
	ModelViewProjection = projection * view * model;
	gl_Position = ModelViewProjection * vec4(in_Position, 1.0);

	color = in_Color;
	//uvs   = in_Uvs;   
}