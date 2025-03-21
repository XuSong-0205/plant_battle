#pragma once

#include <functional>
#include "easyx.h"

#include "Vector2.h"
#include "PlayerID.h"
#include "Camera.h"


// 子弹基类
class Bullet
{
public:
	enum class BulletStatus
	{
		Normal,			// 正常状态
		Invalid,		// 无效状态
		CanRemove,		// 可被回收状态
	};

public:
	void set_damage(int damage) { m_damage = damage; }
	int get_damage() const { return m_damage; }
	void set_position(const Vector2& pos) { m_pos = pos; }
	const Vector2& get_position() const { return m_pos; }
	void set_velocity(const Vector2& vel) { m_velocity = vel; }
	const Vector2& get_velocity() const { return m_velocity; }
	const Vector2& get_size() const { return m_size; }
	void set_collide_target(PlayerID target_id) { m_target_id = target_id; }
	PlayerID get_collide_target() const { return m_target_id; }
	void set_callback(const std::function<void()>& callback) { m_callback = callback; }
	void set_valid(bool valid) { m_status = valid ? BulletStatus::Normal : BulletStatus::Invalid; }
	bool is_valid() const { return m_status == BulletStatus::Normal; }
	bool is_invalid() const { return m_status == BulletStatus::Invalid; }
	bool check_can_remove() const { return m_status == BulletStatus::CanRemove; }

public:
	// 子弹碰撞时调用的函数
	virtual void on_collide() { if (m_callback) m_callback(); }

	// 检查子弹碰撞
	virtual bool check_collide(const Vector2& pos, const Vector2& size) const
	{
		return m_pos.x + m_size.x / 2 >= pos.x
			&& m_pos.x + m_size.x / 2 <= pos.x + size.x
			&& m_pos.y + m_size.y / 2 >= pos.y
			&& m_pos.y + m_size.y / 2 <= pos.y + size.y;
	}

	virtual void on_draw(const Camera& camera);

	virtual void on_update(int delta);


protected:
	// 检查子弹是否超出屏幕范围
	bool check_if_exceeds_screen() const
	{
		return (m_pos.x + m_size.x <= 0 || m_pos.x >= getwidth()
			||  m_pos.y + m_size.y <= 0 || m_pos.y >= getheight());
	}

protected:
	Vector2 m_size;			// 子弹尺寸
	Vector2 m_pos;			// 子弹位置
	Vector2 m_velocity;		// 子弹速度
	int m_damage;			// 子弹伤害
	BulletStatus m_status = BulletStatus::Normal;	// 子弹状态
	PlayerID m_target_id = PlayerID::P1;			// 子弹目标玩家ID
	std::function<void()> m_callback;				// 子弹碰撞回调函数
};