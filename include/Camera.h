#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f);

    float fov = 45.0f;
    float nearPlane = 0.1f;
    float farPlane = 100.0f;

    float yaw = -90.0f;
    float pitch = 0.0f;

    glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f);
public:
    Camera();

    void translate(glm::vec3 offset);
    void setPosition(glm::vec3 newPosition);

    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix(float aspectRatio) const;

    void moveForward(float amount);
    void moveBackward(float amount);
    void moveLeft(float amount);
    void moveRight(float amount);

    void rotate(float yawOffset, float pitchOffset);
    void updateVectors();
};