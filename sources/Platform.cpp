#include "Platform.h"
#include "Utils.h"

extern bool g_is_debug;				// 是否开启调试模式


void Platform::on_draw(const Camera& camera) const
{
	putimage_alpha(camera, m_render_pos, m_img);

	if (g_is_debug)
	{
		setlinecolor(RGB(255, 0, 0));
		line(camera, (int)m_shape.left, (int)m_shape.y, (int)m_shape.right, (int)m_shape.y);
	}
}
