#include "KeyboardInput.h"
#include "Window.h"

KeyboardInput::KeyboardInput(const Window& window) :
	window(window.getGLFWwindow())
{
}

void KeyboardInput::update(Camera& camera)
{
    float speed = 0.1f;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.moveForward(speed);

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.moveBackward(speed);

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.moveLeft(speed);

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.moveRight(speed);

    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}