#include "PeashooterPlayer.h"
#include "Utils.h"
#include "Atlas.h"
#include "PeaBullet.h"

#include <memory>



extern Atlas atlas_peashooter_idle_left;		// 豌豆射手朝向左的默认动画图集
extern Atlas atlas_peashooter_idle_right;		// 豌豆射手朝向右的默认动画图集
extern Atlas atlas_peashooter_run_left;			// 豌豆射手朝向左的奔跑动画图集
extern Atlas atlas_peashooter_run_right;		// 豌豆射手朝向右的奔跑动画图集
extern Atlas atlas_peashooter_attack_ex_left;	// 豌豆射手朝向左的攻击特效动画图集
extern Atlas atlas_peashooter_attack_ex_right;	// 豌豆射手朝向右的攻击特效动画图集

extern std::vector<std::shared_ptr<Bullet>> g_bullet_list;

extern Camera g_main_camera;



PeashooterPlayer::PeashooterPlayer()
{
	m_animation_idle_left.set_atlas(&atlas_peashooter_idle_left);
	m_animation_idle_right.set_atlas(&atlas_peashooter_idle_right);
	m_animation_run_left.set_atlas(&atlas_peashooter_run_left);
	m_animation_run_right.set_atlas(&atlas_peashooter_run_right);
	m_animation_attack_ex_left.set_atlas(&atlas_peashooter_attack_ex_left);
	m_animation_attack_ex_right.set_atlas(&atlas_peashooter_attack_ex_right);

	m_animation_idle_left.set_interval(75);
	m_animation_idle_right.set_interval(75);
	m_animation_run_left.set_interval(75);
	m_animation_run_right.set_interval(75);
	m_animation_attack_ex_left.set_interval(75);
	m_animation_attack_ex_right.set_interval(75);

	m_size = { 96, 96 };

	m_timer_attack_ex.set_wait_time(m_attack_ex_duration);
	m_timer_attack_ex.set_repeat(false);
	m_timer_attack_ex.set_callback([&]()
		{
			m_is_attacking_ex = false;
		});

	m_timer_spwan_pea_ex.set_wait_time(100);
	m_timer_spwan_pea_ex.set_repeat(true);
	m_timer_spwan_pea_ex.set_callback([&]()
		{
			spawn_pea_bullet(m_spped_pea_ex);
		});

	m_attack_cd = 100;
}

void PeashooterPlayer::on_update(int delta)
{
	Player::on_update(delta);

	if (m_is_attacking_ex)
	{
		g_main_camera.shake(5, 100);
		m_timer_attack_ex.on_update(delta);
		m_timer_spwan_pea_ex.on_update(delta);
	}
}

void PeashooterPlayer::on_attack()
{
	spawn_pea_bullet(m_speed_pea);

	switch (rand() % 2)
	{
	case 0:
		MCI_MUSIC_PLAY("pea_shoot_1");
		break;
	case 1:
		MCI_MUSIC_PLAY("pea_shoot_2");
		break;
	}
}

void PeashooterPlayer::on_attack_ex()
{
	m_is_attacking_ex = true;
	m_timer_attack_ex.restart();

	m_is_facing_right ? m_animation_attack_ex_right.reset() : m_animation_attack_ex_left.reset();

	MCI_MUSIC_PLAY("pea_shoot_ex");
}

void PeashooterPlayer::spawn_pea_bullet(double speed)
{
	std::shared_ptr<PeaBullet> bullet = std::make_shared<PeaBullet>();
	g_bullet_list.push_back(bullet);


	Vector2 bullet_position;
	Vector2 bullet_velocity;
	const Vector2& bullet_size = bullet->get_size();
	bullet_position.x = m_is_facing_right
		? m_pos.x + m_size.x - bullet_size.x / 2
		: m_pos.x - bullet_size.x / 2;
	bullet_position.y = m_pos.y;
	bullet_velocity.x = m_is_facing_right ? speed : -speed;
	bullet_velocity.y = 0;

	bullet->set_position(bullet_position);
	bullet->set_velocity(bullet_velocity);
	bullet->set_collide_target(m_id == PlayerID::P1 ? PlayerID::P2 : PlayerID::P1);
	bullet->set_callback([&]() { m_mp += 25; });
}
