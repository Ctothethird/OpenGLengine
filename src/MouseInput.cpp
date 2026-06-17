#include "include/MouseInput.h"

MouseInput::MouseInput(const Window& window)
    : window(window.getGLFWwindow())
{
    glfwSetInputMode(
        this->window,
        GLFW_CURSOR,
        GLFW_CURSOR_DISABLED);
}

void MouseInput::update(Camera& camera)
{
    double xpos;
    double ypos;

    glfwGetCursorPos(window, &xpos, &ypos);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset =
        static_cast<float>(xpos - lastX);

    float yoffset =
        static_cast<float>(lastY - ypos);

    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;

    xoffset *= sensitivity;
    yoffset *= sensitivity;

    camera.rotate(xoffset, yoffset);
}