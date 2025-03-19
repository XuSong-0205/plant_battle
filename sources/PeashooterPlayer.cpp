#include "PeashooterPlayer.h"
#include "Utils.h"
#include "Atlas.h"



extern Atlas atlas_peashooter_idle_left;		// 豌豆射手朝向左的默认动画图集
extern Atlas atlas_peashooter_idle_right;		// 豌豆射手朝向右的默认动画图集
extern Atlas atlas_peashooter_run_left;			// 豌豆射手朝向左的奔跑动画图集
extern Atlas atlas_peashooter_run_right;		// 豌豆射手朝向右的奔跑动画图集



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

	println("婉逗射手正在更新...");
}
