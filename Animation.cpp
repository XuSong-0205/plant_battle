#include "Animation.h"
#include "Utils.h"


void Animation::reset()
{
	m_timer = 0;
	m_idx_frame = 0;
}

void Animation::set_atlas(Atlas* atlas)
{
	reset();
	m_atlas = atlas;
}

bool Animation::check_finished() const
{
	if (m_is_loop) return false;
	return m_idx_frame == (int)m_atlas->get_size() - 1;
}

void Animation::on_update(int delta)
{
	m_timer += delta;
	if (m_timer >= m_interval)
	{
		m_timer = 0;
		++m_idx_frame;
		if (m_idx_frame >= (int)m_atlas->get_size())
		{
			m_idx_frame = m_is_loop ? 0 : (int)m_atlas->get_size() - 1;
			if (!m_is_loop && m_finished_callback)
			{
				m_finished_callback();
			}
		}
	}


}

void Animation::on_draw(int x, int y) const
{
	putimage_alpha(x, y, m_atlas->get_image(m_idx_frame));
}

void Animation::on_draw(const Camera& camera, int x, int y) const
{
	putimage_alpha(camera, { x, y }, m_atlas->get_image(m_idx_frame));
}

