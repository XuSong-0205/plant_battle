#pragma once

#include <functional>


// 定时器类
class Timer
{
public:
	Timer() = default;


	// 重启定时器
	void restart() { m_pass_time = 0; m_shotted = false; }
	void set_wait_time(int wait_time) {  m_wait_time = wait_time; }
	void set_repeat(bool repeat) {  m_repeat = repeat; }
	void set_callback(const std::function<void()>& callback) {  m_callback = callback; }

	// 暂停计时器
	void pause() { m_paused = true; }
	// 恢复计时器
	void resume() { m_paused = false; }

	// 更新定时器
	void on_update(int delta);


private:
	int m_pass_time = 0;				// 已过时间，单位毫秒
	int m_wait_time = 0;				// 等待时间，单位毫秒
	bool m_paused = false;;				// 是否暂停
	bool m_shotted = false;;			// 是否被触发
	bool m_repeat = false;;				// 是否重复触发
	std::function<void()> m_callback;	// 回调函数
};

