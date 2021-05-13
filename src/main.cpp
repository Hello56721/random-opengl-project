#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <opengl-debug.hpp>
#include <window.hpp>
#include <program.hpp>

// And of course, the main function
int main() {
    Program program;
    
    while (!glfwWindowShouldClose(Window::window)) {
        program.update();
    }
    
    return 0;
}