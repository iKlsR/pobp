#version 400

in vec3 color;
//in vec2 uvs;

out vec4 out_Color;

//uniform sampler2D texture;

void main() {

	out_Color = vec4(color, 1.0);
	//out_Color = texture2D(texture, uvs);
}