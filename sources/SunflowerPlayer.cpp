#include "SunflowerPlayer.h"
#include "Utils.h"
#include "Atlas.h"


extern Atlas atlas_sunflower_idle_left;			// 龙日葵朝向左的默认动画图集
extern Atlas atlas_sunflower_idle_right;		// 龙日葵朝向右的默认动画图集
extern Atlas atlas_sunflower_run_left;			// 龙日葵朝向左的奔跑动画图集
extern Atlas atlas_sunflower_run_right;			// 龙日葵朝向右的奔跑动画图集



SunflowerPlayer::SunflowerPlayer()
{
	m_animation_idle_left.set_atlas(&atlas_sunflower_idle_left);
	m_animation_idle_right.set_atlas(&atlas_sunflower_idle_right);
	m_animation_run_left.set_atlas(&atlas_sunflower_run_left);
	m_animation_run_right.set_atlas(&atlas_sunflower_run_right);

	m_animation_idle_left.set_interval(75);
	m_animation_idle_right.set_interval(75);
	m_animation_run_left.set_interval(75);
	m_animation_run_right.set_interval(75);

	m_size = { 96, 96 };
}

void SunflowerPlayer::on_update(int delta)
{
	Player::on_update(delta);

	println("龙日葵正在更新...");
}
