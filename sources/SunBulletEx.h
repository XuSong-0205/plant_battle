#pragma once

#include "Bullet.h"
#include "Animation.h"
#include "Camera.h"
#include "Vector2.h"


// �޴��չ�ը���ӵ���
class SunBulletEx : public Bullet
{
public:
	SunBulletEx();


	void on_collide() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;
	
	bool check_collide(const Vector2& pos, const Vector2& size) const override;

private:
	Animation m_animation_idle;			// �޴��չ�ը��Ĭ�϶���
	Animation m_animation_explode;		// �޴��չ�ը����ը����
	Vector2 m_explode_render_offset;	// ��ը������Ⱦƫ��

};

