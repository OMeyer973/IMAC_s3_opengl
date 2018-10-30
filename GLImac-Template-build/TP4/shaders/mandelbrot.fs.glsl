#version 330

in vec3 vColor;
in vec2 vFragPosition;

out vec3 fFragColor;

void main() {
    fFragColor = vec3(1, 0, 0);
    //fFragColor = vec3(vFragPosition, 0);
}
