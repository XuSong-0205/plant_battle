#include <ctime>

#include "Camera.h"


Camera::Camera()
{
	m_timer.set_repeat(false);
	m_timer.set_callback([&]()
		{
			m_is_shaking = false;
			reset();
		});
}

Vector2 Camera::get_window_pos(const Vector2& world_pos) const
{
	return Vector2(world_pos.x - m_pos.x, world_pos.y - m_pos.y);
}

void Camera::shake(double strength, int duration)
{
	m_is_shaking = true;
	m_shaking_strength = strength;

	m_timer.set_wait_time(duration);
	m_timer.restart();
}

void Camera::on_update(int delta)
{
	m_timer.on_update(delta);

	if (m_is_shaking)
	{
		m_pos.x = (-50 + rand() % 100) / 50.0 * m_shaking_strength;
		m_pos.y = (-50 + rand() % 100) / 50.0 * m_shaking_strength;
	}
}
