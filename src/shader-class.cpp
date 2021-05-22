#include <shader-class.hpp>

#include <shader-utils.hpp>
#include <glad/glad.h>
#include <opengl-debug.hpp>
#include <shader-manager.hpp>

Shader::Shader(): program(0) {
    
}

Shader::Shader(std::string_view path) {
    ShaderUtils::ShaderSources sources = ShaderUtils::processShader(path);
    unsigned int vertex = ShaderUtils::createShader(sources.vertex.c_str(), GL_VERTEX_SHADER, path);
    unsigned int fragment = ShaderUtils::createShader(sources.fragment.c_str(), GL_FRAGMENT_SHADER, path);
    program = ShaderUtils::createProgram(vertex, fragment, path);
    
    // Delete the shaders because they are already linked to the shader program and are therefore uneeded.
    glCall(glDeleteShader, vertex);
    glCall(glDeleteShader, fragment);
    
    // Add this object to the whole list
    ShaderManager& manager = ShaderManager::getInstance();
    manager.shaders.push_back(*this);
}

void Shader::use() const {
    glCall(glUseProgram, program);
}

void Shader::setUniform(std::string_view name, float value) const {
    glCall(glUniform1f, glCallR(glGetUniformLocation, program, name.data()), value);
}