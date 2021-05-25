#include <glad/glad.h>
#include <opengl-debug.hpp>
#include <window.hpp>
#include <iostream>
#include <shader-utils.hpp>
#include <vector>
#include <mesh.hpp>
#include <simple-renderer.hpp>
#include <shader-class.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <program.hpp>

static Mesh* mesh;

static Shader basicShader;

static glm::mat4 view;

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
    
    view = glm::mat4(1.0);
    view = glm::translate(view, glm::vec3(0.0, 0.0, -3.0));
    
    glfwShowWindow(Window::window);
}



void Program::update() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    basicShader.use();
    
    basicShader.setUniform("model", glm::mat4(1.0));
    basicShader.setUniform("view", view);
    basicShader.setUniform("projection", Window::getProjectionMatrix());
    
    SimpleRenderer::renderMesh(*mesh, true);
    
    Window::update();
}



Program::~Program() {
    delete mesh;
    
    glfwTerminate();
}