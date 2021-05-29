#include <glad/glad.h>
#include <opengl-debug.hpp>
#include <window.hpp>
#include <iostream>
#include <shader-utils.hpp>
#include <vector>
#include <mesh.hpp>
#include <simple-renderer.hpp>
#include <shader-class.hpp>
#include <sstream>

#include <program.hpp>

static Mesh* mesh;

static Shader* basicShader;

struct {
    double deltaTime;
    double startTime;
    double endTime;
} Time;

Program::Program() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    Window::initWindow();
    
    basicShader = new Shader("shaders/basic.glsl");
    
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
    Time.startTime = glfwGetTime();
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    basicShader->use();
    SimpleRenderer::renderMesh(*mesh, true);
    
    std::stringstream title;
    title << "Random OpenGL Project\tFPS: " << 1.0 / Time.deltaTime;
    glfwSetWindowTitle(Window::window, title.str().c_str());
    
    glfwSwapBuffers(Window::window);
    glfwPollEvents();
    
    Time.endTime = glfwGetTime();
    Time.deltaTime = Time.endTime - Time.startTime;
}



Program::~Program() {
    delete mesh;
    delete basicShader;
    
    glfwTerminate();
}