#version 330 core

uniform sampler2D uTexture;

//position du fragment sur l'écran
in  vec4 vFragPosition;
//normal du fragment
in  vec4 vFragNormal;
//coordonée u, v du fragment
in  vec2 vFragTexCoords;

out vec3 fFragColor;

void main() {	
	fFragColor = texture(uTexture, vFragTexCoords).xyz;

	//fFragColor = normalize(vFragNormal.xyz);
};
