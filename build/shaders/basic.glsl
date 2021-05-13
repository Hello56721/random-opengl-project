//@ vertex
#version 330 core
layout (location = 0) in vec3 position;

void main() {
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
}

//@ fragment
#version 330 core
out vec4 colour;

void main() {
    colour = vec4(1.0, 1.0, 0.0, 1.0);
}
