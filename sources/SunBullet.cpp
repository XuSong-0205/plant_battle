#include "SunBullet.h"
#include "Utils.h"

extern Atlas atlas_sun;
extern Atlas atlas_sun_explode;

extern Camera g_main_camera;



SunBullet::SunBullet()
{
	m_size = { 96, 96 };
	m_damage = 20;

	m_animation_idle.set_atlas(&atlas_sun);
	m_animation_idle.set_interval(50);

	m_animation_explode.set_atlas(&atlas_sun_explode);
	m_animation_explode.set_interval(50);
	m_animation_explode.set_loop(false);
	m_animation_explode.set_finished_callback([&]() { m_status = BulletStatus::CanRemove; });

	IMAGE* frame_idle = m_animation_idle.get_frame();
	IMAGE* frame_explode = m_animation_explode.get_frame();
	m_explode_render_offset.x = (frame_idle->getwidth() - frame_explode->getwidth()) / 2.0;
	m_explode_render_offset.y = (frame_idle->getheight() - frame_explode->getheight()) / 2.0;
}

void SunBullet::on_collide()
{
	Bullet::on_collide();

	g_main_camera.shake(5, 250);

	MCI_MUSIC_PLAY("sun_explode");
}

void SunBullet::on_update(int delta)
{
	if (is_valid())
	{
		m_velocity.y += m_gravity * delta;
		m_pos += m_velocity * delta;
	}

	if (is_invalid())
	{
		m_animation_explode.on_update(delta);
	}
	else
	{
		m_animation_idle.on_update(delta);
	}

	if (check_if_exceeds_screen())
	{
		m_status = BulletStatus::CanRemove;
	}
}

void SunBullet::on_draw(const Camera& camera)
{
	if (is_valid())
	{
		m_animation_idle.on_draw(camera, (int)m_pos.x, (int)m_pos.y);
	}
	else
	{
		m_animation_explode.on_draw(camera, 
			(int)m_pos.x - m_explode_render_offset.x, 
			(int)m_pos.y - m_explode_render_offset.y);
	}

	Bullet::on_draw(camera);
}
