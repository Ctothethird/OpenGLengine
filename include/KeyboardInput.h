#pragma once
#include "Window.h"
#include "Camera.h"

class KeyboardInput {
	//const Window& window;
	GLFWwindow* window;

public:
	KeyboardInput(const Window& windwo);
	void update(Camera& camera);
};