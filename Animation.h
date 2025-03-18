#pragma once

#include <functional>

#include "Atlas.h"
#include "Camera.h"


// ������
class Animation
{
public:
	void reset();
	void set_atlas(Atlas* atlas);;
	void set_loop(bool loop) { m_is_loop = loop; }
	void set_interval(int interval) {  m_interval = interval; }

	int get_idx_frame() const {  return m_idx_frame; }
	IMAGE* get_frame() { return m_atlas->get_image(m_idx_frame); }
	bool check_finished() const;
	void set_finished_callback(std::function<void()> callback) { m_finished_callback = callback; }

public:
	void on_update(int delta);
	void on_draw(int x, int y) const;
	void on_draw(const Camera& camera, int x, int y) const;

private:
	int m_timer = 0;			// ��ʱ��
	int m_interval = 0;			// ֡���
	int m_idx_frame = 0;		// ֡����
	bool m_is_loop = true;		// �Ƿ�ѭ��

private:
	Atlas* m_atlas = nullptr;					// ����ͼ��ָ��
	std::function<void()> m_finished_callback;	// ���������ص�����
};

