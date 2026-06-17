#include "GLengine.h"

GLengine::GLengine()
    : keyboard(*window), mouse(*window)
{
}

GLengine::~GLengine()
{
    delete render;
    delete window;
    delete camera;
}

void GLengine::clear()
{
    render->clear();
}

void GLengine::draw(Model& model)
{
    render->draw(model, *camera);
}

Camera& GLengine::getCamera() const
{
    return *camera;
}

void GLengine::swapAndPool()
{
    window->swapBuffer();
    window->pollEvent();
}

Window& GLengine::getWindow() const
{
    return *window;
}

void GLengine::update()
{
    keyboard.update(*camera);
    mouse.update(*camera);
}