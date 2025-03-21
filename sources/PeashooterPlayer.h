#pragma once

#include "Player.h"
#include "Timer.h"


// 婉逗射手玩家类
class PeashooterPlayer : public Player
{
public:
	PeashooterPlayer();

	void on_update(int delta) override;

	void on_attack() override;
	void on_attack_ex() override;

private:
	void spawn_pea_bullet(double speed);

private:
	const double m_speed_pea = 0.75;		// 普攻子弹速度
	const double m_spped_pea_ex = 1.5;		// 特殊攻击子弹速度
	const int m_attack_ex_duration = 2500;	// 特殊攻击持续时间, 单位毫秒

private:
	Timer m_timer_attack_ex;				// 特殊攻击状态定时器
	Timer m_timer_spwan_pea_ex;				// 婉逗子弹发射定时器
};

