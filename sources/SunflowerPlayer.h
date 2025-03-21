#pragma once

#include "Player.h"
#include "Animation.h"
#include "Camera.h"
#include "Vector2.h"


// 龙日葵玩家类
class SunflowerPlayer : public Player
{
public:
	SunflowerPlayer();

	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;

	void on_attack() override;
	void on_attack_ex() override;


private:
	const double m_speed_sun_ex = 0.15;				// 大型日光炸弹下落速度
	const Vector2 m_velocity_sun{ 0.25, -0.5 };		// 小型日光炸弹抛射速度

private:
	Animation m_animation_sun_text;		// 头顶文本动画
	bool m_is_sun_text_visible = false;	// 是否显示头顶文本

};

