#pragma once

#include <easyx.h>

#include "Camera.h"
#include "Vector2.h"
#include "Animation.h"
#include "PlayerID.h"
#include "Timer.h"



// 玩家基类
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
	const double m_gravity = 1.6e-3;			// 玩家重力加速度
	const double m_run_velocity = 0.55;			// 水平奔跑速度
	const double m_jump_velocity = -0.85;		// 跳跃速度


protected:
	int m_mp = 0;								// 角色能量
	int m_hp = 100;								// 角色生命值

	Vector2 m_size;								// 角色尺寸
	Vector2 m_pos;								// 角色位置
	Vector2 m_velocity;							// 角色速度

	Animation m_animation_idle_left;			// 朝向左的默认动画
	Animation m_animation_idle_right;			// 朝向右的默认动画
	Animation m_animation_run_left;				// 朝向左的奔跑动画
	Animation m_animation_run_right;			// 朝向右的奔跑动画
	Animation m_animation_attack_ex_left;		// 朝向左的特殊攻击动画
	Animation m_animation_attack_ex_right;		// 朝向右的特殊攻击动画
	Animation* m_current_animation = nullptr;	// 当前播放的动画

	PlayerID m_id = PlayerID::P1;				// 玩家 ID

	bool m_is_left_key_down = false;			// 左方向键是否按下
	bool m_is_right_key_down = false;			// 右方向键是否按下

	bool m_is_facing_right = true;				// 角色是否朝向右侧

	int m_attack_cd = 500;						// 普通攻击冷却时间，单位毫秒
	bool m_can_attack = true;					// 玩家是否可以释放普通攻击
	Timer m_timer_attack_cd;					// 普通攻击冷却定时器

	bool m_is_attacking_ex = false;				// 是否正在释放特殊攻击

	IMAGE m_img_sketch;							// 动画帧剪影图片
	bool m_is_invulnerable = false;				// 角色是否处理无敌状态
	bool m_is_showing_sketch_frame = false;		// 是当前帧是否应该显示剪影
	Timer m_timer_invulnerable;					// 无敌状态定时器
	Timer m_timer_invulnerable_blink;			// 无敌状态闪烁定时器
};

