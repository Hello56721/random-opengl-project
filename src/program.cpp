#include <glad/glad.h>
#include <opengl-debug.hpp>
#include <window.hpp>
#include <iostream>
#include <shader-utils.hpp>
#include <vector>

#include <program.hpp>

static unsigned int shaderProgram;

static unsigned int vao;
static unsigned int vbo;
static unsigned int ebo;

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
    
    glCall(glGenVertexArrays, 1, &vao);
    glCall(glBindVertexArray, vao);
    
    float vertices[] =  {
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };
    
    glCall(glGenBuffers, 1, &vbo);
    glCall(glBindBuffer, GL_ARRAY_BUFFER, vbo);
    glCall(glBufferData, GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    unsigned int indices[] {
        0, 1, 2,
        0, 3, 2
    };
    
    glCall(glGenBuffers, 1, &ebo);
    glCall(glBindBuffer, GL_ELEMENT_ARRAY_BUFFER, ebo);
    glCall(glBufferData, GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glCall(glVertexAttribPointer, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glCall(glEnableVertexAttribArray, 0);
    
    glfwShowWindow(Window::window);
}



void Program::update() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glCall(glUseProgram, shaderProgram);
    
    glCall(glBindVertexArray, vao);
    glCall(glDrawElements, GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    
    glfwSwapBuffers(Window::window);
    glfwPollEvents();
}



Program::~Program() {
    glCall(glDeleteProgram, shaderProgram);
    glCall(glDeleteBuffers, 1, &vbo);
    glCall(glDeleteBuffers, 1, &ebo);
    glCall(glDeleteVertexArrays, 1, &vao);
    
    glfwTerminate();
}