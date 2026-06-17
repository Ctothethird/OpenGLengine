#pragma once

#include "Window.h"
#include "Camera.h"

class MouseInput
{
private:
    GLFWwindow* window;

    double lastX = 400;
    double lastY = 400;

    bool firstMouse = true;

public:
    MouseInput(const Window& window);

    void update(Camera& camera);
};