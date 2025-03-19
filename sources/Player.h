#pragma once

#include <easyx.h>

#include "Camera.h"
#include "Vector2.h"
#include "Animation.h"
#include "PlayerID.h"



// ��һ���
class Player
{
public:
	Player();
	virtual ~Player();

	virtual void on_update(int delta);

	virtual void on_draw(const Camera& camera);

	virtual void on_input(const ExMessage& msg);

	virtual void on_run(double distance);

	virtual void on_jump();


	void set_id(PlayerID id) { m_id = id; }
	void set_position(const Vector2& pos) { m_pos = pos; }


protected:
	void move_and_collide(int delta);



protected:
	const double m_gravity = 1.6e-3;			// ����������ٶ�
	const double m_run_velocity = 0.55;			// ˮƽ�����ٶ�
	const double m_jump_velocity = -0.85;		// ��Ծ�ٶ�


protected:
	Vector2 m_size;								// ��ɫ�ߴ�
	Vector2 m_pos;								// ��ɫλ��
	Vector2 m_velocity;							// ��ɫ�ٶ�

	Animation m_animation_idle_left;			// �������Ĭ�϶���
	Animation m_animation_idle_right;			// �����ҵ�Ĭ�϶���
	Animation m_animation_run_left;				// ������ı��ܶ���
	Animation m_animation_run_right;			// �����ҵı��ܶ���
	Animation* m_current_animation = nullptr;	// ��ǰ���ŵĶ���

	PlayerID m_id = PlayerID::P1;				// ��� ID

	bool m_is_left_key_down = false;			// ������Ƿ���
	bool m_is_right_key_down = false;			// �ҷ�����Ƿ���

	bool m_is_facing_right = true;				// ��ɫ�Ƿ����Ҳ�
};

