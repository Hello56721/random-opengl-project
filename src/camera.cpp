#include <camera.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(): Camera(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -90.0, 0.0) {
    
}

Camera::Camera(glm::vec3 position, glm::vec3 worldUp, double yaw, double pitch): position(position), worldUp(worldUp), yaw(yaw),
pitch(pitch) {
    recalculate();
}

Camera::Camera(double posX, double posY, double posZ, double wUpX, double wUpY, double wUpZ, double yaw, double pitch):
Camera(glm::vec3(posX, posY, posZ), glm::vec3(wUpX, wUpY, wUpZ), yaw, pitch) {
    
}

glm::mat4 Camera::getLookAtMatrix() {
    return glm::lookAt(position, position + direction, up);
}

void Camera::moveLocal(float amount, Direction dir) {
    switch(dir) {
    case Direction::FORWARD:
        position += direction * amount;
        break;
    case Direction::BACKWARD:
        position -= direction * amount;
        break;
    case Direction::LEFT:
        position += right * amount;
        break;
    case Direction::RIGHT:
        position -= right * amount;
        break;
    case Direction::UP:
        position += up * amount;
        break;
    case Direction::DOWN:
        position -= up * amount;
        break;
    }
}

void Camera::moveGlobal(float amount, Direction dir) {
    switch(dir) {
    case Direction::FORWARD:
        position.z += amount;
        break;
    case Direction::BACKWARD:
        position.z -= amount;
        break;
    case Direction::LEFT:
        position.x -= amount;
        break;
    case Direction::RIGHT:
        position.x += amount;
        break;
    case Direction::UP:
        position.y += amount;
        break;
    case Direction::DOWN:
        position.y -= amount;
        break;
    }
}

void Camera::turnEuler(double yaw, double pitch) {
    this->yaw += yaw;
    this->pitch += pitch;
    
    recalculate();
}

void Camera::recalculate() {
    glm::vec3 newDirection;
    newDirection.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newDirection.y = sin(glm::radians(pitch));
    newDirection.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction = glm::normalize(newDirection);
    
    right = glm::normalize(glm::cross(worldUp, direction));
    up = glm::normalize(glm::cross(direction, right));
}