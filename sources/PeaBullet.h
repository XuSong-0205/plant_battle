#pragma once

#include "Bullet.h"
#include "Animation.h"


// 婉逗射手子弹类
class PeaBullet : public Bullet
{
public:
	PeaBullet();

	void on_collide() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;


private:
	Animation m_animation_break;		// 子弹破碎动画

};

