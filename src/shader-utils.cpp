#include <opengl-debug.hpp>
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <utils.hpp>

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

ShaderUtils::ShaderSources ShaderUtils::processShader(std::string_view path) {
    std::ifstream file(path.data());
    if (!file) {
        std::cerr << "[ERROR]: Could not find or access " << path << std::endl;
        return { "", "" };
    }
    
    enum class Mode {
        Null, Vertex, Fragment
    } mode;
    
    std::string vertex;
    std::string fragment;
    
    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        
        // Check if it is a custom expression
        if (Utils::startsWith(line, "//@")) {
            if (line == "//@ vertex") {
                mode = Mode::Vertex;
            } else if (line == "//@ fragment") {
                mode = Mode::Fragment;
            }
        } else {
            switch (mode) {
            case Mode::Vertex:
                vertex += line += "\n";
                break;
            case Mode::Fragment:
                fragment += line += "\n";
                break;
            default:
                break;
            }
        }
    }
    
    return { vertex, fragment };
}