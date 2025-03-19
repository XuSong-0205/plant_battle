#include "PeashooterPlayer.h"
#include "Utils.h"
#include "Atlas.h"



extern Atlas atlas_peashooter_idle_left;		// �㶹���ֳ������Ĭ�϶���ͼ��
extern Atlas atlas_peashooter_idle_right;		// �㶹���ֳ����ҵ�Ĭ�϶���ͼ��
extern Atlas atlas_peashooter_run_left;			// �㶹���ֳ�����ı��ܶ���ͼ��
extern Atlas atlas_peashooter_run_right;		// �㶹���ֳ����ҵı��ܶ���ͼ��



PeashooterPlayer::PeashooterPlayer()
{
	m_animation_idle_left.set_atlas(&atlas_peashooter_idle_left);
	m_animation_idle_right.set_atlas(&atlas_peashooter_idle_right);
	m_animation_run_left.set_atlas(&atlas_peashooter_run_left);
	m_animation_run_right.set_atlas(&atlas_peashooter_run_right);

	m_animation_idle_left.set_interval(75);
	m_animation_idle_right.set_interval(75);
	m_animation_run_left.set_interval(75);
	m_animation_run_right.set_interval(75);

	m_size = { 96, 96 };
}

void PeashooterPlayer::on_update(int delta)
{
	Player::on_update(delta);

	println("���������ڸ���...");
}
