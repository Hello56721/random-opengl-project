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
#include <glm/gtc/matrix_transform.hpp>
#include <camera.hpp>
#include <model-loader.hpp>
#include <texture.hpp>
#include <texture-manager.hpp>
#include <program.hpp>

static Mesh* mesh;

static Shader basicShader;

struct {
    double deltaTime;
    double startTime;
    double endTime;
} Time;

static Camera camera;

static Texture woodTexture;
static Texture earthTexture;

struct {
    double deltaTime;
} Time;

struct {
    double lastX;
    double lastY;
    bool firstMouse = true;
    double sensitivity;
} Cursor;

static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

static void handleInput();

Program::Program() {
    std::cout << "[INFO]: Hello!" << std::endl;
    
    Window::initWindow();
    
    basicShader = Shader("assets/shaders/basic.glsl");
    
    mesh = new Mesh({},{});
    *mesh = ModelLoader::loadModel("assets/models/sphere.obj");
    
    woodTexture = Texture("assets/textures/wood.jpg");
    earthTexture = Texture("assets/textures/earth.jpeg");
    
    camera.moveLocal(100.0, Camera::Direction::BACKWARD);
    
    glfwSetCursorPosCallback(Window::window, cursorPosCallback);
    glfwSetInputMode(Window::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    Cursor.sensitivity = 2.5;
    
    glCall(glEnable, GL_DEPTH_TEST);
    
    glfwShowWindow(Window::window);
}



void Program::update() {
    Time.startTime = glfwGetTime();
    
    handleInput();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    basicShader.use();
    
    basicShader.setUniform("model", glm::mat4(1.0));
    basicShader.setUniform("view", camera.getLookAtMatrix());
    basicShader.setUniform("projection", Window::getProjectionMatrix());
    
    basicShader.setUniform("myTexture", 0);
    
    Texture::setActiveTexture(0);
    earthTexture.bind();
    
    SimpleRenderer::renderMesh(*mesh, true);
    
    Window::update();
    
    double endTime = glfwGetTime();
    Time.deltaTime = endTime - Time.startTime;
    
    std::stringstream title;
    title << "Random OpenGL Project\tFPS: " << 1.0 / Time.deltaTime;
    glfwSetWindowTitle(Window::window, title.str().c_str());
}



Program::~Program() {
    delete mesh;
    delete TextureManager::getInstance();
    
    glfwTerminate();
}


static void handleInput() {
    if (glfwGetKey(Window::window, GLFW_KEY_W)) {
        camera.moveLocal(2.5f * Time.deltaTime, Camera::Direction::FORWARD);
    }
    if (glfwGetKey(Window::window, GLFW_KEY_S)) {
        camera.moveLocal(2.5f * Time.deltaTime, Camera::Direction::BACKWARD);
    }
    if (glfwGetKey(Window::window, GLFW_KEY_A)) {
        camera.moveLocal(2.5f * Time.deltaTime, Camera::Direction::LEFT);
    }
    if (glfwGetKey(Window::window, GLFW_KEY_D)) {
        camera.moveLocal(2.5f * Time.deltaTime, Camera::Direction::RIGHT);
    }
    
    if (glfwGetKey(Window::window, GLFW_KEY_SPACE)) {
        camera.moveLocal(2.5f * Time.deltaTime, Camera::Direction::UP);
    }
    if (glfwGetKey(Window::window, GLFW_KEY_LEFT_SHIFT)) {
        camera.moveLocal(2.5f * Time.deltaTime, Camera::Direction::DOWN);
    }
    
    if (glfwGetKey(Window::window, GLFW_KEY_ESCAPE)) {
        glfwSetInputMode(Window::window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
}



static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    if (Cursor.firstMouse) {
        Cursor.lastX = xpos;
        Cursor.lastY = ypos;
        Cursor.firstMouse = false;
    }
    
    double xoffset = xpos - Cursor.lastX;
    double yoffset = Cursor.lastY - ypos;
    Cursor.lastX = xpos;
    Cursor.lastY = ypos;
    
    xoffset *= Cursor.sensitivity * Time.deltaTime;
    yoffset *= Cursor.sensitivity * Time.deltaTime;
    
    camera.turnEuler(xoffset, yoffset);
}