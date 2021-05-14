#include <glad/glad.h>
#include <opengl-debug.hpp>
#include <iostream>

#include <window.hpp>

GLFWwindow* Window::window;

static unsigned int width;
static unsigned int height;

static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glCall(glViewport, 0, 0, width, height);
    ::width = width;
    ::height = height;
}

GLFWwindow* Window::createWindow(int width, int height, std::string_view title) {
    GLFWwindow* window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "[FATAL ERROR]: Failed to create GLFW window." << std::endl;
        glfwTerminate();
        throw -1;
    }
    glfwMakeContextCurrent(window);
    
    ::width = width;
    ::height = height;
    
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
    
    window = createWindow(1, 1, "Random OpenGL Project");
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "[FATAL ERROR]: Failed to initialize GLAD." << std::endl;
        glfwTerminate();
        throw -1;
    }
    
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    
    glfwMaximizeWindow(window);
}