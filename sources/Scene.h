#pragma once

#include <easyx.h>
#include "Camera.h"


// ≥°æ∞¿‡
class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;

public:
	virtual void on_enter() = 0;
	virtual void on_update(int delta) = 0;
	virtual void on_draw(const Camera& camera) = 0;
	virtual void on_input(const ExMessage& msg) = 0;
	virtual void on_exit() = 0;

private:

};

