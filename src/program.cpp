#include <glad/glad.h>
#include <opengl-debug.hpp>
#include <window.hpp>
#include <iostream>
#include <shader-utils.hpp>

#include <program.hpp>

static unsigned int shaderProgram;

Program::Program() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    Window::initWindow();
    
    // Initialize the Shaders
    ShaderUtils::ShaderSources shaderSources = ShaderUtils::processShader("shaders/basic.glsl");
    unsigned int vertexShader = ShaderUtils::createShader(shaderSources.vertex.c_str(), GL_VERTEX_SHADER, "shaders/basic.glsl");
    unsigned int fragmentShader = ShaderUtils::createShader(shaderSources.fragment.c_str(), GL_FRAGMENT_SHADER, "shaders/fragment.glsl");
    shaderProgram = ShaderUtils::createProgram(vertexShader, fragmentShader, "shaders/basic.glsl");
    // We don't need the shaders anymore, since they are linked to the program
    glCall(glDeleteShader, vertexShader);
    glCall(glDeleteShader, fragmentShader);
    
    glfwShowWindow(Window::window);
}



void Program::update() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glCall(glUseProgram, shaderProgram);
    
    glfwSwapBuffers(Window::window);
    glfwPollEvents();
}



Program::~Program() {
    glfwTerminate();
}