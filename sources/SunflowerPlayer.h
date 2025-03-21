#pragma once

#include "Player.h"
#include "Animation.h"
#include "Camera.h"
#include "Vector2.h"


// ���տ������
class SunflowerPlayer : public Player
{
public:
	SunflowerPlayer();

	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;

	void on_attack() override;
	void on_attack_ex() override;


private:
	const double m_speed_sun_ex = 0.15;				// �����չ�ը�������ٶ�
	const Vector2 m_velocity_sun{ 0.25, -0.5 };		// С���չ�ը�������ٶ�

private:
	Animation m_animation_sun_text;		// ͷ���ı�����
	bool m_is_sun_text_visible = false;	// �Ƿ���ʾͷ���ı�

};

