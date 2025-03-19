#include "Platform.h"
#include "Utils.h"

extern bool is_debug;				// 是否开启调试模式


void Platform::on_draw(const Camera& camera) const
{
	putimage_alpha(camera, m_render_pos, m_img);

	if (is_debug)
	{
		setlinecolor(RGB(255, 0, 0));
		line(camera, m_shape.left, m_shape.y, m_shape.right, m_shape.y);
	}
}
