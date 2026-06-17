#pragma once

#include "Window.h"
#include "Shader.h"
#include "Render.h"
#include "Model.h"
#include "Camera.h"
#include "KeyboardInput.h"
#include "MouseInput.h"

class GLengine {
private:
    Window* window = new Window(800, 800, "SDF");
    Render* render = new Render();
    Camera* camera = new Camera();
    KeyboardInput keyboard;
    MouseInput mouse;

public:

    GLengine();
    ~GLengine();

    void clear();
    void draw(Model& model);
    Camera& getCamera() const;
    void swapAndPool();

    Window& getWindow() const;

    void update();
};