#pragma once

#include <easyx.h>


// ״̬����
class StatusBar
{
public:

	void set_avatar(IMAGE* img) { m_img_avatar = img; }
	void set_position(const POINT& pos) { m_pos = pos; }
	void set_hp(int hp) { m_hp = hp; }
	void set_mp(int mp) { m_mp = mp; }

	void on_draw() const;

private:
	static constexpr int width = 275;	// ״̬�����

private:
	int m_hp = 0;						// ��Ҫ��ʾ������ֵ
	int m_mp = 0;						// ��Ҫ��ʾ������ֵ
	POINT m_pos{ 0, 0 };				// �ڴ�������ʾideλ��
	IMAGE* m_img_avatar = nullptr;		// ��ɫͷ��ͼƬ

};

