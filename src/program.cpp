#include <glad/glad.h>
#include <opengl-debug.hpp>
#include <window.hpp>
#include <iostream>
#include <shader-utils.hpp>
#include <vector>
#include <mesh.hpp>
#include <simple-renderer.hpp>
#include <shader-class.hpp>

#include <program.hpp>

static Mesh* mesh;

static Shader basicShader;

Program::Program() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    Window::initWindow();
    
    basicShader = Shader("shaders/basic.glsl");
    
    mesh = new Mesh(
        {
            {{ 0.5f,  0.5f, 0.0f}},
            {{ 0.5f, -0.5f, 0.0f}},
            {{-0.5f, -0.5f, 0.0f}},
            {{-0.5f,  0.5f, 0.0f}}
        },
        {
            0, 1, 2,
            0, 3, 2
        }
    );
    
    glfwShowWindow(Window::window);
}



void Program::update() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    basicShader.use();
    SimpleRenderer::renderMesh(*mesh, true);
    
    glfwSwapBuffers(Window::window);
    glfwPollEvents();
}



Program::~Program() {
    delete mesh;
    
    glfwTerminate();
}