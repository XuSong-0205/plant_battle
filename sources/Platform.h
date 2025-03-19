#pragma once

#include "Camera.h"


// 平台类
class Platform
{
public:
	void on_draw(const Camera& camera) const;

public:
	struct CollisionShape
	{
		double y;
		double left;
		double right;
	};

public:
	CollisionShape m_shape;			// 平台形状
	IMAGE* m_img = nullptr;			// 平台图片
	POINT m_render_pos{ 0, 0 };		// 平台渲染位置

};

