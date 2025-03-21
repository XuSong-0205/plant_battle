#include "Bullet.h"

extern bool g_is_debug;


void Bullet::on_draw(const Camera& camera)
{
	if (g_is_debug)
	{
		setfillcolor(RGB(255, 255, 255));
		setlinecolor(RGB(255, 255, 255));
		rectangle((int)m_pos.x, (int)m_pos.y, (int)m_pos.x + m_size.x, (int)m_pos.y + m_size.y);
		solidcircle((int)(m_pos.x + m_size.x / 2), (int)(m_pos.y + m_size.y / 2), 5);
	}

}

void Bullet::on_update(int delta)
{
}
