#pragma once

#include "Player.h"
#include "Timer.h"


// �����������
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
	const double m_speed_pea = 0.75;		// �չ��ӵ��ٶ�
	const double m_spped_pea_ex = 1.5;		// ���⹥���ӵ��ٶ�
	const int m_attack_ex_duration = 2500;	// ���⹥������ʱ��, ��λ����

private:
	Timer m_timer_attack_ex;				// ���⹥��״̬��ʱ��
	Timer m_timer_spwan_pea_ex;				// ���ӵ����䶨ʱ��
};

