#include <glad/glad.h>
#include <iostream>

#include <window.hpp>

GLFWwindow* Window::createWindow(int width, int height, std::string_view title) {
    GLFWwindow* window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "[FATAL ERROR]: Failed to create GLFW window." << std::endl;
        glfwTerminate();
        throw -1;
    }
    glfwMakeContextCurrent(window);
    
    return window;
}



void Window::initGLFW(unsigned int glVersionMajor, unsigned int glVersionMinor) {
    if (!glfwInit()) {
        std::cerr << "[FATAL ERROR]: Failed to initialize GLFW." << std::endl;
        throw -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glVersionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glVersionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
}



void Window::initWindow() {
    initGLFW(3, 3);
    
    const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    
    window = createWindow(videoMode->width / 1.25, videoMode->height / 1.25, "Random OpenGL Project");
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "[FATAL ERROR]: Failed to initialize GLAD." << std::endl;
        glfwTerminate();
        throw -1;
    }
}