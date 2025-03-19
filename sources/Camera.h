#pragma once

#include "Vector2.h"
#include "Timer.h"


// �������
class Camera
{
public:
	Camera();

	const Vector2& get_pos() const { return m_pos; }
	void reset() { m_pos.x = 0; m_pos.y = 0; }
	Vector2 get_window_pos(const Vector2& world_pos) const;

	void shake(double strength, int duration);
	void on_update(int delta);

private:
	Vector2 m_pos;					// �����λ��
	Timer m_timer;					// �������ʱ��
	bool m_is_shaking = false;		// ������Ƿ����ڶ���
	double m_shaking_strength = 0;	// �������������
};

