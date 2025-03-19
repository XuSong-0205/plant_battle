#pragma once

#include "Vector2.h"
#include "Timer.h"


// 摄像机类
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
	Vector2 m_pos;					// 摄像机位置
	Timer m_timer;					// 摄像机定时器
	bool m_is_shaking = false;		// 摄像机是否正在抖动
	double m_shaking_strength = 0;	// 摄像机抖动幅度
};

