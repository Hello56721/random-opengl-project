#include <opengl-debug.hpp>
#include <glad/glad.h>
#include <iostream>

#include <shader-utils.hpp>

unsigned int ShaderUtils::createShader(const char* source, unsigned int type, std::string_view name) {
    unsigned int shader;
    shader = glCallR(glCreateShader, type);
    glCall(glShaderSource, shader, 1, &source, nullptr);
    glCall(glCompileShader, shader);
    
    // Check for compiliation errors
    int success;
    glCall(glGetShaderiv, shader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        int infoLogLength;
        glCall(glGetShaderiv, shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        char* infoLog = new char[infoLogLength];
        glCall(glGetShaderInfoLog, shader, infoLogLength, nullptr, infoLog);
        
        std::cerr << "[ERROR]: Failed to compile shader " << name << ":\n" << infoLog << "\n\n";
        
        delete[] infoLog;
    }
    
    return shader;
}

unsigned int ShaderUtils::createProgram(unsigned int vertex, unsigned int fragment, std::string_view name) {
    unsigned int program;
    program = glCallRN(glCreateProgram);
    glCall(glAttachShader, program, vertex);
    glCall(glAttachShader, program, fragment);
    glCall(glLinkProgram, program);
    
    // Check for linking errors
    int success;
    glCall(glGetProgramiv, program, GL_LINK_STATUS, &success);
    if (success == GL_FALSE) {
        int infoLogLength;
        glCall(glGetProgramiv, program, GL_INFO_LOG_LENGTH, &infoLogLength);
        char* infoLog = new char[infoLogLength];
        glCall(glGetProgramInfoLog, program, infoLogLength, nullptr, infoLog);
        
        std::cerr << "[ERROR]: Failed to link program " << name << ":\n" << infoLog << "\n\n";
        
        delete[] infoLog;
    }
    
    return program;
}