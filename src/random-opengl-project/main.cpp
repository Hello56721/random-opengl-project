#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <opengl-debug.hpp>
#include <window.hpp>

// The class that will represent the whole program
class Program {
public:
    Program();
    
    void update();
    
    ~Program();
};

// And of course, the main function
int main() {
    Program program;
    
    while (!glfwWindowShouldClose(Window::window)) {
        program.update();
    }
    
    return 0;
}


Program::Program() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    Window::initWindow();
    
    glfwShowWindow(Window::window);
}



void Program::update() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(Window::window);
    glfwPollEvents();
}



Program::~Program() {
    glfwTerminate();
}