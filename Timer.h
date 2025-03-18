#pragma once

#include <functional>


// ��ʱ����
class Timer
{
public:
	Timer() = default;


	// ������ʱ��
	void restart() { m_pass_time = 0; m_shotted = false; }
	void set_wait_time(int wait_time) {  m_wait_time = wait_time; }
	void set_repeat(bool repeat) {  m_repeat = repeat; }
	void set_callback(const std::function<void()>& callback) {  m_callback = callback; }

	// ��ͣ��ʱ��
	void pause() { m_paused = true; }
	// �ָ���ʱ��
	void resume() { m_paused = false; }

	// ���¶�ʱ��
	void on_update(int delta);


private:
	int m_pass_time = 0;				// �ѹ�ʱ�䣬��λ����
	int m_wait_time = 0;				// �ȴ�ʱ�䣬��λ����
	bool m_paused = false;;				// �Ƿ���ͣ
	bool m_shotted = false;;			// �Ƿ񱻴���
	bool m_repeat = false;;				// �Ƿ��ظ�����
	std::function<void()> m_callback;	// �ص�����
};

