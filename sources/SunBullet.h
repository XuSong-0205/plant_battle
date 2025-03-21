#pragma once

#include "Bullet.h"
#include "Animation.h"
#include "Camera.h"
#include "Vector2.h"


// 龙日葵日光炸弹类
class SunBullet : public Bullet
{
public:
	SunBullet();

	void on_collide() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;

private:
	const double m_gravity = 1e-3;		// 日光炸弹重力加速度

private:
	Animation m_animation_idle;			// 日光炸弹默认动画
	Animation m_animation_explode;		// 日光炸弹爆炸动画
	Vector2 m_explode_render_offset;	// 爆炸动画渲染偏移

};

