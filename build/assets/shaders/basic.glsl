//@ vertex
#version 330 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec2 aTextureCoordinate;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 textureCoordinate;

void main() {
    gl_Position = projection * view * model * vec4(aPosition.x, aPosition.y, aPosition.z, 1.0);
    textureCoordinate = aTextureCoordinate;
}

//@ fragment
#version 330 core
out vec4 colour;

uniform sampler2D myTexture;

in vec2 textureCoordinate;

void main() {
    colour = texture(myTexture, textureCoordinate); //vec4(1.0, 1.0, 0.0, 1.0);
}
