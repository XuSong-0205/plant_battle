#include "Timer.h"

void Timer::on_update(int delta)
{
	if (m_paused) return;

	m_pass_time += delta;
	if (m_pass_time >= m_wait_time)
	{
		if ((m_repeat || (!m_repeat && !m_shotted)) && m_callback)
		{
			m_callback();
		}

		m_shotted = true;
		m_pass_time = 0;
	}
}
