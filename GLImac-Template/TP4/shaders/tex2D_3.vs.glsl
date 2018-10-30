#version 330 core
#define M_PI 3.1415926535897932384626433832795

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aVertexCoordinate;

out vec2 vFragCoordinate;
out vec2 vFragPosition;

uniform mat3 uModelMatrix;

mat3 translate(float tx, float ty) {
	return mat3(vec3(1,0,0),vec3(0,1,0),vec3(tx,ty,1));
}

mat3 scale(float sx, float sy){
	return mat3(vec3(sx,0,0),vec3(0,sy,0),vec3(0,0,1));	
}

mat3 rotate(float teta){
	return mat3(vec3(cos(teta),sin(teta),0),vec3(-sin(teta),cos(teta),0),vec3(0,0,1));	
}

void main() {
  vFragCoordinate = aVertexCoordinate;
  vFragPosition = aVertexPosition;

  gl_Position = vec4((uModelMatrix * vec3(aVertexPosition, 1)).xy, 0, 1);
  
};