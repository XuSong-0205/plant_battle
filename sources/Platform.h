#pragma once

#include "Camera.h"


// ƽ̨��
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
	CollisionShape m_shape;			// ƽ̨��״
	IMAGE* m_img = nullptr;			// ƽ̨ͼƬ
	POINT m_render_pos{ 0, 0 };		// ƽ̨��Ⱦλ��

};

