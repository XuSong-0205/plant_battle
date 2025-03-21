#include "SunflowerPlayer.h"
#include "Utils.h"
#include "Atlas.h"
#include "SunBullet.h"
#include "SunBulletEx.h"


extern Atlas atlas_sunflower_idle_left;			// 龙日葵朝向左的默认动画图集
extern Atlas atlas_sunflower_idle_right;		// 龙日葵朝向右的默认动画图集
extern Atlas atlas_sunflower_run_left;			// 龙日葵朝向左的奔跑动画图集
extern Atlas atlas_sunflower_run_right;			// 龙日葵朝向右的奔跑动画图集
extern Atlas atlas_sunflower_attack_ex_left;	// 龙日葵朝向左的特殊攻击动画图集
extern Atlas atlas_sunflower_attack_ex_right;	// 龙日葵朝向右的特殊攻击动画图集
extern Atlas atlas_sun_text;					// “日”文本动画图集

extern std::vector<std::shared_ptr<Bullet>> g_bullet_list;

extern std::unique_ptr<Player> g_player_1;		// 玩家 1
extern std::unique_ptr<Player> g_player_2;		// 玩家 2


SunflowerPlayer::SunflowerPlayer()
{
	m_animation_idle_left.set_atlas(&atlas_sunflower_idle_left);
	m_animation_idle_right.set_atlas(&atlas_sunflower_idle_right);
	m_animation_run_left.set_atlas(&atlas_sunflower_run_left);
	m_animation_run_right.set_atlas(&atlas_sunflower_run_right);
	m_animation_attack_ex_left.set_atlas(&atlas_sunflower_attack_ex_left);
	m_animation_attack_ex_right.set_atlas(&atlas_sunflower_attack_ex_right);
	m_animation_sun_text.set_atlas(&atlas_sun_text);

	m_animation_idle_left.set_interval(75);
	m_animation_idle_right.set_interval(75);
	m_animation_run_left.set_interval(75);
	m_animation_run_right.set_interval(75);
	m_animation_attack_ex_left.set_interval(75);
	m_animation_attack_ex_right.set_interval(75);
	m_animation_sun_text.set_interval(75);

	m_animation_attack_ex_left.set_loop(false);
	m_animation_attack_ex_right.set_loop(false);
	m_animation_sun_text.set_loop(false);


	m_animation_attack_ex_left.set_finished_callback([&]()
		{
			m_is_attacking_ex = false;
			m_is_sun_text_visible = false;
		});
	m_animation_attack_ex_right.set_finished_callback([&]()
		{
			m_is_attacking_ex = false;
			m_is_sun_text_visible = false;
		});


	m_size = { 96, 96 };

	m_attack_cd = 250;
}

void SunflowerPlayer::on_update(int delta)
{
	Player::on_update(delta);

	if (m_is_sun_text_visible)
	{
		m_animation_sun_text.on_update(delta);
	}
}

void SunflowerPlayer::on_draw(const Camera& camera)
{
	Player::on_draw(camera);

	if (m_is_sun_text_visible)
	{
		Vector2 text_position;
		IMAGE* frame = m_animation_sun_text.get_frame();
		text_position.x = m_pos.x - (m_size.x - frame->getwidth()) / 2;
		text_position.y = m_pos.y - frame->getheight();
		m_animation_sun_text.on_draw(camera, (int)text_position.x, (int)text_position.y);
	}
}

void SunflowerPlayer::on_attack()
{
	std::shared_ptr<Bullet> bullet = std::make_shared<SunBullet>();
	g_bullet_list.push_back(bullet);

	Vector2 bullet_position;
	const Vector2& bullet_size = bullet->get_size();
	bullet_position.x = m_pos.x + (m_size.x - bullet_size.x) / 2;
	bullet_position.y = m_pos.y;

	bullet->set_position(bullet_position);
	bullet->set_velocity({ m_is_facing_right ? m_velocity_sun.x : -m_velocity_sun.x, m_velocity_sun.y });

	bullet->set_collide_target(m_id == PlayerID::P1 ? PlayerID::P2 : PlayerID::P1);
	bullet->set_callback([&]() { m_mp += 35; });
}

void SunflowerPlayer::on_attack_ex()
{
	m_is_attacking_ex = true;
	m_is_sun_text_visible = true;

	m_animation_sun_text.reset();
	m_is_facing_right ? m_animation_attack_ex_right.reset() : m_animation_attack_ex_left.reset();

	std::shared_ptr<Bullet> bullet = std::make_shared<SunBulletEx>();
	g_bullet_list.push_back(bullet);
	Player* target_player = m_id == PlayerID::P1 ? g_player_2.get() : g_player_1.get();

	Vector2 bullet_position;
	Vector2 bullet_velocity;
	const Vector2& bullet_size = bullet->get_size();
	const Vector2& target_size = target_player->get_size();
	const Vector2& target_pos = target_player->get_position();
	bullet_position.x = target_pos.x + (target_size.x - bullet_size.x) / 2;
	bullet_position.y = -m_size.y;
	bullet_velocity.x = 0;
	bullet_velocity.y = m_speed_sun_ex;

	bullet->set_position(bullet_position);
	bullet->set_velocity(bullet_velocity);

	bullet->set_collide_target(m_id == PlayerID::P1 ? PlayerID::P2 : PlayerID::P1);
	bullet->set_callback([&]() { m_mp += 50; });

	MCI_MUSIC_PLAY("sun_text");
}
