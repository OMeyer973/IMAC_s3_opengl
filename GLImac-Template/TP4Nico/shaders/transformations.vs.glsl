#version 330 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;

mat3 translate(float tx, float ty){
	return mat3(vec3(1, 0, 0), vec3(0, 1, 0), vec3(tx, ty, 1));
};

mat3 scale(float sx, float sy){
	return mat3(vec3(sx, 0, 0), vec3(0, sy, 0), vec3(0, 0, 1));
};

mat3 rotate(float a){
	float rad = radians(a);
	return mat3(vec3(cos(rad), sin(rad), 0), vec3(-sin(rad), cos(rad), 0), vec3(0, 0, 1));
};

void main() {
	vFragColor = aVertexColor;
	//gl_Position = vec4(aVertexPosition*2 + vec2(0.5,0.5), 0, 1);
	//gl_Position = vec4(aVertexPosition*vec2(2,0.5), 0, 1);

	//vec2 transformed = (translate(0.5,0.5) * scale(2,0.5) * vec3(aVertexPosition, 1)).xy;
	// POURQUOI DEFORMEE ? //vec2 transformed = (rotate(45) * vec3(aVertexPosition, 1)).xy;
	vec2 transformed = (rotate(45) * translate(0.5,0.) * scale(0.5,0.5)  * rotate(-45) * vec3(aVertexPosition, 1)).xy;
	gl_Position = vec4(transformed, 0, 1);

};