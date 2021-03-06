#ifndef C6D19E01_8636_4183_90DA_0ACBA4778316
#define C6D19E01_8636_4183_90DA_0ACBA4778316

#include <GLFW/glfw3.h>
#include <string_view>
#include <glm/glm.hpp>

namespace Window {
    extern GLFWwindow* window;

    // Create and check if the window is valid
    GLFWwindow* createWindow(int width, int height, std::string_view title);

    // Initialize GLFW with a OpenGL version
    void initGLFW(unsigned int glVersionMajor, unsigned int glVersionMinor);

    // Everything having to do with initializing window
    void initWindow();
    
    // Update the window
    void update();
    
    // Get the projection matrix
    glm::mat4& getProjectionMatrix();
}

#endif /* C6D19E01_8636_4183_90DA_0ACBA4778316 */
