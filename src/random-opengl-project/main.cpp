#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <opengl-debug.hpp>

static GLFWwindow* window;

// Create and check if the window is valid
static GLFWwindow* createWindow(int width, int height, std::string_view title);

// Initialize GLFW with a OpenGL version
static void initGLFW(unsigned int glVersionMajor, unsigned int glVersionMinor);

// Everything having to do with initializing window
static void initWindow();

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
    
    while (!glfwWindowShouldClose(window)) {
        program.update();
    }
    
    return 0;
}



static GLFWwindow* createWindow(int width, int height, std::string_view title) {
    GLFWwindow* window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "[FATAL ERROR]: Failed to create GLFW window." << std::endl;
        glfwTerminate();
        throw -1;
    }
    glfwMakeContextCurrent(window);
    
    return window;
}



static void initGLFW(unsigned int glVersionMajor, unsigned int glVersionMinor) {
    if (!glfwInit()) {
        std::cerr << "[FATAL ERROR]: Failed to initialize GLFW." << std::endl;
        throw -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glVersionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glVersionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
}



static void initWindow() {
    initGLFW(3, 3);
    
    const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    
    window = createWindow(videoMode->width / 1.25, videoMode->height / 1.25, "Random OpenGL Project");
    
    // Maximize the window
    glfwMaximizeWindow(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "[FATAL ERROR]: Failed to initialize GLAD." << std::endl;
        glfwTerminate();
        throw -1;
    }
}



Program::Program() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    initWindow();
    
    glfwShowWindow(window);
}



void Program::update() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
}



Program::~Program() {
    glfwTerminate();
}