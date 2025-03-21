#include "StatusBar.h"
#include "Utils.h"

void StatusBar::on_draw() const
{
	putimage_alpha(m_pos, m_img_avatar);

	setfillcolor(RGB(5, 5, 5));
	solidroundrect(m_pos.x + 100, m_pos.y + 10, m_pos.x + 100 + width + 3 * 2, m_pos.y + 36, 8, 8);
	solidroundrect(m_pos.x + 100, m_pos.y + 45, m_pos.x + 100 + width + 3 * 2, m_pos.y + 71, 8, 8);
	setfillcolor(RGB(67, 47, 47));
	solidroundrect(m_pos.x + 100, m_pos.y + 10, m_pos.x + 100 + width + 3, m_pos.y + 33, 8, 8);
	solidroundrect(m_pos.x + 100, m_pos.y + 45, m_pos.x + 100 + width + 3, m_pos.y + 68, 8, 8);

	double hp_bar_width = width * (std::max)(0, m_hp) / 100.0;
	double mp_bar_width = width * (std::min)(100, m_mp) / 100.0;
	setfillcolor(RGB(197, 61, 67));
	solidroundrect(m_pos.x + 100, m_pos.y + 10, m_pos.x + 100 + (int)hp_bar_width + 3, m_pos.y + 33, 8, 8);
	setfillcolor(RGB(83, 131, 195));
	solidroundrect(m_pos.x + 100, m_pos.y + 45, m_pos.x + 100 + (int)mp_bar_width + 3, m_pos.y + 68, 8, 8);
}
