#version 330 core

uniform sampler2D uTexture;
uniform sampler2D uSecondTexture;

//position du fragment sur l'écran
in  vec4 vFragPosition;
//normal du fragment
in  vec4 vFragNormal;
//coordonée u, v du fragment
in  vec2 vFragTexCoords;

out vec3 fFragColor;

void main() {	
	fFragColor = texture(uTexture, vFragTexCoords).xyz
			   + texture(uSecondTexture, vFragTexCoords).xyz;

	//fFragColor = normalize(vFragNormal.xyz);
};
