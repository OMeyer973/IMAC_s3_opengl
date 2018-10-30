#version 330 core
#define M_PI 3.1415926535897932384626433832795

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;
out vec2 vFragPosition;

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
  vFragColor = aVertexColor;
  vFragPosition = aVertexPosition;

	//pas de transformation
  //gl_Position = vec4(aVertexPosition, 0, 1);
 	
  //exemple de transformations manuelles
  //gl_Position = vec4(aVertexPosition + vec2(0.5, 0.5), 0, 1);
  //gl_Position = vec4(aVertexPosition * 2, 0, 1);
  //gl_Position = vec4(aVertexPosition * vec2(2, 0.5), 0, 1);
  
  //exemples de transformations avec les matrices
  //gl_Position = vec4((translate(0.5,0.5) * vec3(aVertexPosition, 1)).xy, 0, 1);
  //gl_Position = vec4((scale(2,2) * vec3(aVertexPosition, 1)).xy, 0, 1);
  //gl_Position = vec4((scale(2,0.5) * vec3(aVertexPosition, 1)).xy, 0, 1);
  
  //3 transformations à la suite
  //gl_Position = vec4((translate(0.5,0) * rotate(M_PI/4) * scale(0.5,0.5) * vec3(aVertexPosition, 1)).xy, 0, 1);
  
  gl_Position = vec4(vec3(aVertexPosition, 1).xy, 0, 1);

};