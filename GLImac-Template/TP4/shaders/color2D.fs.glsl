#version 330 core

in vec3 vFragColor;
in vec2 vFragPosition;

out vec3 fFragColor;

const float alpha = 1;
const float beta = 100;

void main() {
	//particule
	//float d = distance(vec2(0,0), vFragPosition);
	//fFragColor = vFragColor * alpha * exp(-beta*d*d);

	//textures procédurales
	//fFragColor = vFragColor *length(fract(5.0 * vFragPosition));
	//fFragColor = vFragColor *length(abs(fract(5.0 * vFragPosition) * 2.0 - 1.0));
	//fFragColor = vFragColor *mod(floor(10.0 * vFragPosition.x) + floor(10.0 * vFragPosition.y), 2.0);
	//fFragColor = vFragColor *smoothstep(0.3, 0.32, length(fract(5.0 * vFragPosition) - 0.5));
	//fFragColor = vFragColor *smoothstep(0.4, 0.5, max(abs(fract(8.0 * vFragPosition.x - 0.5 * mod(floor(8.0 * vFragPosition.y), 2.0)) - 0.5), abs(fract(8.0 * vFragPosition.y) - 0.5)));
	fFragColor = vFragColor;
};
