#include "PeaBullet.h"
#include "Utils.h"

extern IMAGE img_pea;
extern Atlas atlas_pea_break;



PeaBullet::PeaBullet()
{
	m_size = { 64, 64 };
	m_damage = 10;

	m_animation_break.set_atlas(&atlas_pea_break);
	m_animation_break.set_interval(100);
	m_animation_break.set_loop(false);
	m_animation_break.set_finished_callback([&]() { m_status = BulletStatus::CanRemove; });
}

void PeaBullet::on_collide()
{
	Bullet::on_collide();

	switch (rand() % 3)
	{
	case 0:
		MCI_MUSIC_PLAY("pea_break_1");
		break;
	case 1:
		MCI_MUSIC_PLAY("pea_break_2");
		break;
	case 2:
		MCI_MUSIC_PLAY("pea_break_3");
		break;
	}

}

void PeaBullet::on_update(int delta)
{
	m_pos += m_velocity * delta;

	if (is_invalid())
	{
		m_animation_break.on_update(delta);
	}

	if (check_if_exceeds_screen())
	{
		m_status = BulletStatus::CanRemove;
	}
}

void PeaBullet::on_draw(const Camera& camera)
{
	if (is_valid())
	{
		putimage_alpha(camera, m_pos, &img_pea);
	}
	else
	{
		m_animation_break.on_draw(camera, (int)m_pos.x, (int)m_pos.y);
	}

	Bullet::on_draw(camera);
}
