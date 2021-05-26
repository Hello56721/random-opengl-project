#ifndef B3AE28A5_360B_49FC_A6AD_6C87C5674236
#define B3AE28A5_360B_49FC_A6AD_6C87C5674236

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Camera {
private:
    glm::vec3 position;
    glm::vec3 direction;
    glm::vec3 right;
    glm::vec3 up;
    glm::vec3 worldUp;
    
    double yaw;
    double pitch;
    
public:
    // Camera Direction
    enum class Direction {
        FORWARD, BACKWARD, LEFT, RIGHT, UP, DOWN
    };
    
    // Default Constructor
    Camera();
    
    // Constructor
    Camera(glm::vec3 position, glm::vec3 worldUp, double yaw, double pitch);
    
    // Constructor from scalars
    Camera(double posX, double posY, double posZ, double wUpX, double wUpY, double wUpZ, double yaw, double pitch);
    
    // Return the look at matrix
    glm::mat4 getLookAtMatrix();
    
    // Move the camera locally in a specific direction
    void moveLocal(float amount, Direction direction);
    
    // Move the camera globally in a specific direction
    void moveGlobal(float amount, Direction direction);
    
    // Turn the camera with a yaw and pitch
    void turnEuler(double yaw, double pitch);
    
private:
    // Recalculate the vectors
    void recalculate();
};

#endif /* B3AE28A5_360B_49FC_A6AD_6C87C5674236 */
