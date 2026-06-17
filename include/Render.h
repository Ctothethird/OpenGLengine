#pragma once
#include "Model.h"
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"

class Render {
public:
	void clear();
	void draw(const Model& model, const Camera& camera);
};