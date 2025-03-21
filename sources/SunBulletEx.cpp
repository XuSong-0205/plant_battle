#include "SunBulletEx.h"
#include "Utils.h"

extern Atlas atlas_sun_ex;
extern Atlas atlas_sun_ex_explode;

extern Camera g_main_camera;


SunBulletEx::SunBulletEx()
{
	m_size = { 288, 288 };
	m_damage = 30;

	m_animation_idle.set_atlas(&atlas_sun_ex);
	m_animation_idle.set_interval(50);

	m_animation_explode.set_atlas(&atlas_sun_ex_explode);
	m_animation_explode.set_interval(50);
	m_animation_explode.set_loop(false);
	m_animation_explode.set_finished_callback([&]() { m_status = BulletStatus::CanRemove; });

	IMAGE* frame_idle = m_animation_idle.get_frame();
	IMAGE* frame_explode = m_animation_explode.get_frame();
	m_explode_render_offset.x = (frame_idle->getwidth() - frame_explode->getwidth()) / 2.0;
	m_explode_render_offset.y = (frame_idle->getheight() - frame_explode->getheight()) / 2.0;

}

void SunBulletEx::on_collide()
{
	Bullet::on_collide();

	g_main_camera.shake(20, 350);

	MCI_MUSIC_PLAY("sun_explode_ex");

}

void SunBulletEx::on_update(int delta)
{
	if (is_valid())
	{
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

void SunBulletEx::on_draw(const Camera& camera)
{
	if (is_valid())
	{
		m_animation_idle.on_draw(camera,(int)m_pos.x, (int)m_pos.y);
	}
	else
	{
		m_animation_explode.on_draw(camera, 
			(int)m_pos.x - m_explode_render_offset.x, 
			(int)m_pos.y - m_explode_render_offset.y);
	}

	Bullet::on_draw(camera);
}

bool SunBulletEx::check_collide(const Vector2& pos, const Vector2& size) const
{
	bool is_collide_x = ((std::max)(m_pos.x + m_size.x, pos.x + size.x)
		- (std::min)(m_pos.x, pos.x)) <= m_size.x + size.x;
	bool is_collide_y = ((std::max)(m_pos.y + m_size.y, pos.y + size.y)
		- (std::min)(m_pos.y, pos.y)) <= m_size.y + size.y;

	return is_collide_x && is_collide_y;
}
