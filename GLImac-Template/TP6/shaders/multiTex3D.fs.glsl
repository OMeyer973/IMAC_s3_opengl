#version 330 core

uniform sampler2D uEarthTexture;
uniform sampler2D uCloudTexture;

//position du fragment sur l'écran
in  vec4 vFragPosition;
//normal du fragment
in  vec4 vFragNormal;
//coordonée u, v du fragment
in  vec2 vFragTexCoords;

out vec3 fFragColor;

void main() {	
	fFragColor = texture(uEarthTexture, vFragTexCoords).xyz
			   + texture(uCloudTexture, vFragTexCoords).xyz;

	//fFragColor = normalize(vFragNormal.xyz);
};
