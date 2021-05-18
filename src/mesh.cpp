#include <glad/glad.h>
#include <opengl-debug.hpp>
#include <utility>

#include <mesh.hpp>

void Mesh::moveFrom(Mesh& src) {
    vao = src.vao;
    vbo = src.vbo;
    ebo = src.ebo;
    
    src.vao = 0;
    src.vbo = 0;
    src.ebo = 0;
}

void Mesh::destroy() {
    glCall(glDeleteVertexArrays, 1, &vao);
    glCall(glDeleteBuffers, 1, &vbo);
    glCall(glDeleteBuffers, 1, &ebo);
}

Mesh::Mesh(): vao(0), vbo(0), ebo(0) {
    
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices) {
    glCall(glGenVertexArrays, 1, &vao);
    glCall(glBindVertexArray, vao);
    
    glCall(glGenBuffers, 1, &vbo);
    glCall(glBindBuffer, GL_ARRAY_BUFFER, vbo);
    glCall(glBufferData, GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
    
    glCall(glGenBuffers, 1, &ebo);
    glCall(glBindBuffer, GL_ELEMENT_ARRAY_BUFFER, ebo);
    glCall(glBufferData, GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices), &indices[0], GL_STATIC_DRAW);
    
    glCall(glVertexAttribPointer, 0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glCall(glEnableVertexAttribArray, 0);
    
    glCall(glBindVertexArray, 0);
}

Mesh::Mesh(Mesh& src) {
    glCall(glGenVertexArrays, 1, &vao);
    glCall(glBindVertexArray, vao);
    
    
    
    glCall(glBindBuffer, GL_COPY_READ_BUFFER, src.vbo);
    int vboSize;
    glCall(glGetBufferParameteriv, GL_COPY_READ_BUFFER, GL_BUFFER_SIZE, &vboSize);
    
    glCall(glGenBuffers, 1, &vbo);
    glCall(glBindBuffer, GL_ARRAY_BUFFER, vbo);
    glCall(glBufferData, GL_ARRAY_BUFFER, vboSize, nullptr, GL_STATIC_DRAW);
    
    glCall(glCopyBufferSubData, GL_COPY_READ_BUFFER, GL_ARRAY_BUFFER, 0, 0, vboSize);
    
    glCall(glBindBuffer, GL_COPY_READ_BUFFER, 0);
    
    
    
    glCall(glBindBuffer, GL_COPY_READ_BUFFER, src.ebo);
    int eboSize;
    glCall(glGetBufferParameteriv, GL_COPY_READ_BUFFER, GL_BUFFER_SIZE, &eboSize);
    
    glCall(glGenBuffers, 1, &ebo);
    glCall(glBindBuffer, GL_ELEMENT_ARRAY_BUFFER, ebo);
    glCall(glBufferData, GL_ELEMENT_ARRAY_BUFFER, eboSize, nullptr, GL_STATIC_DRAW);
    
    glCall(glCopyBufferSubData, GL_COPY_READ_BUFFER, GL_ELEMENT_ARRAY_BUFFER, 0, 0, eboSize);
    
    glCall(glBindBuffer, GL_COPY_READ_BUFFER, 0);
    
    
    
    glCall(glVertexAttribPointer, 0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glCall(glEnableVertexAttribArray, 0);
    
    glCall(glBindVertexArray, 0);
}

Mesh& Mesh::operator=(Mesh& rhs) {
    Mesh tmp(rhs);
    swap(*this, tmp);
    return *this;
}

Mesh::Mesh(Mesh&& src) {
    moveFrom(src);
}

Mesh& Mesh::operator=(Mesh&& rhs) {
    destroy();
    moveFrom(rhs);
    return *this;
}

void Mesh::swap(Mesh& a, Mesh& b) {
    std::swap(a.vao, b.vao);
    std::swap(a.vbo, b.vbo);
    std::swap(a.ebo, b.ebo);
}

unsigned int Mesh::getVAO() {
    return vao;
}

unsigned int Mesh::getVBO() {
    return vbo;
}

unsigned int Mesh::getEBO() {
    return ebo;
}

Mesh::~Mesh() {
    destroy();
}