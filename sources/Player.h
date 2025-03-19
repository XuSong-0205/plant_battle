#pragma once

#include <easyx.h>

#include "Camera.h"
#include "Vector2.h"
#include "Animation.h"
#include "PlayerID.h"



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


	void set_id(PlayerID id) { m_id = id; }
	void set_position(const Vector2& pos) { m_pos = pos; }


protected:
	void move_and_collide(int delta);



protected:
	const double m_gravity = 1.6e-3;			// 玩家重力加速度
	const double m_run_velocity = 0.55;			// 水平奔跑速度
	const double m_jump_velocity = -0.85;		// 跳跃速度


protected:
	Vector2 m_size;								// 角色尺寸
	Vector2 m_pos;								// 角色位置
	Vector2 m_velocity;							// 角色速度

	Animation m_animation_idle_left;			// 朝向左的默认动画
	Animation m_animation_idle_right;			// 朝向右的默认动画
	Animation m_animation_run_left;				// 朝向左的奔跑动画
	Animation m_animation_run_right;			// 朝向右的奔跑动画
	Animation* m_current_animation = nullptr;	// 当前播放的动画

	PlayerID m_id = PlayerID::P1;				// 玩家 ID

	bool m_is_left_key_down = false;			// 左方向键是否按下
	bool m_is_right_key_down = false;			// 右方向键是否按下

	bool m_is_facing_right = true;				// 角色是否朝向右侧
};

