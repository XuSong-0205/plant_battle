#pragma once

#include <functional>
#include "easyx.h"

#include "Vector2.h"
#include "PlayerID.h"
#include "Camera.h"


// �ӵ�����
class Bullet
{
public:
	enum class BulletStatus
	{
		Normal,			// ����״̬
		Invalid,		// ��Ч״̬
		CanRemove,		// �ɱ�����״̬
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
	// �ӵ���ײʱ���õĺ���
	virtual void on_collide() { if (m_callback) m_callback(); }

	// ����ӵ���ײ
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
	// ����ӵ��Ƿ񳬳���Ļ��Χ
	bool check_if_exceeds_screen() const
	{
		return (m_pos.x + m_size.x <= 0 || m_pos.x >= getwidth()
			||  m_pos.y + m_size.y <= 0 || m_pos.y >= getheight());
	}

protected:
	Vector2 m_size;			// �ӵ��ߴ�
	Vector2 m_pos;			// �ӵ�λ��
	Vector2 m_velocity;		// �ӵ��ٶ�
	int m_damage;			// �ӵ��˺�
	BulletStatus m_status = BulletStatus::Normal;	// �ӵ�״̬
	PlayerID m_target_id = PlayerID::P1;			// �ӵ�Ŀ�����ID
	std::function<void()> m_callback;				// �ӵ���ײ�ص�����
};