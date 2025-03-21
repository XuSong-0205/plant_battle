#pragma once

#include "Bullet.h"
#include "Animation.h"
#include "Camera.h"
#include "Vector2.h"


// ���տ��չ�ը����
class SunBullet : public Bullet
{
public:
	SunBullet();

	void on_collide() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;

private:
	const double m_gravity = 1e-3;		// �չ�ը���������ٶ�

private:
	Animation m_animation_idle;			// �չ�ը��Ĭ�϶���
	Animation m_animation_explode;		// �չ�ը����ը����
	Vector2 m_explode_render_offset;	// ��ը������Ⱦƫ��

};

