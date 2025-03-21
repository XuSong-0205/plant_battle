#pragma once

#include <easyx.h>


// 状态条类
class StatusBar
{
public:

	void set_avatar(IMAGE* img) { m_img_avatar = img; }
	void set_position(const POINT& pos) { m_pos = pos; }
	void set_hp(int hp) { m_hp = hp; }
	void set_mp(int mp) { m_mp = mp; }

	void on_draw() const;

private:
	static constexpr int width = 275;	// 状态条宽度

private:
	int m_hp = 0;						// 需要显示的生命值
	int m_mp = 0;						// 需要显示的能量值
	POINT m_pos{ 0, 0 };				// 在窗口中显示ide位置
	IMAGE* m_img_avatar = nullptr;		// 角色头像图片

};

