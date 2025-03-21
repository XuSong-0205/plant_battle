#pragma once

#include <easyx.h>

#include "Camera.h"
#include "Vector2.h"
#include "Animation.h"
#include "PlayerID.h"
#include "Timer.h"



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

	virtual void on_attack() { }
	virtual void on_attack_ex() { }


	void set_id(PlayerID id) { m_id = id; }
	void set_position(const Vector2& pos) { m_pos = pos; }

	const Vector2& get_position() const { return m_pos; }
	const Vector2& get_size() const { return m_size; }
	int get_hp() const { return m_hp; }
	int get_mp() const { return m_mp; }


protected:
	void move_and_collide(int delta);
	void make_invulnerable();



protected:
	const double m_gravity = 1.6e-3;			// ����������ٶ�
	const double m_run_velocity = 0.55;			// ˮƽ�����ٶ�
	const double m_jump_velocity = -0.85;		// ��Ծ�ٶ�


protected:
	int m_mp = 0;								// ��ɫ����
	int m_hp = 100;								// ��ɫ����ֵ

	Vector2 m_size;								// ��ɫ�ߴ�
	Vector2 m_pos;								// ��ɫλ��
	Vector2 m_velocity;							// ��ɫ�ٶ�

	Animation m_animation_idle_left;			// �������Ĭ�϶���
	Animation m_animation_idle_right;			// �����ҵ�Ĭ�϶���
	Animation m_animation_run_left;				// ������ı��ܶ���
	Animation m_animation_run_right;			// �����ҵı��ܶ���
	Animation m_animation_attack_ex_left;		// ����������⹥������
	Animation m_animation_attack_ex_right;		// �����ҵ����⹥������
	Animation* m_current_animation = nullptr;	// ��ǰ���ŵĶ���

	PlayerID m_id = PlayerID::P1;				// ��� ID

	bool m_is_left_key_down = false;			// ������Ƿ���
	bool m_is_right_key_down = false;			// �ҷ�����Ƿ���

	bool m_is_facing_right = true;				// ��ɫ�Ƿ����Ҳ�

	int m_attack_cd = 500;						// ��ͨ������ȴʱ�䣬��λ����
	bool m_can_attack = true;					// ����Ƿ�����ͷ���ͨ����
	Timer m_timer_attack_cd;					// ��ͨ������ȴ��ʱ��

	bool m_is_attacking_ex = false;				// �Ƿ������ͷ����⹥��

	IMAGE m_img_sketch;							// ����֡��ӰͼƬ
	bool m_is_invulnerable = false;				// ��ɫ�Ƿ����޵�״̬
	bool m_is_showing_sketch_frame = false;		// �ǵ�ǰ֡�Ƿ�Ӧ����ʾ��Ӱ
	Timer m_timer_invulnerable;					// �޵�״̬��ʱ��
	Timer m_timer_invulnerable_blink;			// �޵�״̬��˸��ʱ��
};

