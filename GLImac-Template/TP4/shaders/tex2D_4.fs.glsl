#version 330 core

in vec3 vFragCoordinate;
in vec2 vFragPosition;

out vec3 fFragColor;
uniform vec3 uColor;

const float alpha = 1;
const float beta = 100;

void main() {
	fFragColor = uColor;
};
