#version 330 core

//coordonée u, v du fragment
in vec2 vFragCoordinate;
//position u fragment sue l'écran
in vec2 vFragPosition;

out vec3 fFragColor;
uniform vec3 uColor;
uniform sampler2D uTexture;

const float alpha = 1;
const float beta = 100;

void main() {
	fFragColor = texture(uTexture, vFragCoordinate).xyz;
};
