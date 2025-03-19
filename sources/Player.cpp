#include "Player.h"
#include "Platform.h"


extern std::vector<Platform> g_platform_list;	// 游戏中的平台列表



Player::Player()
{
	m_current_animation = &m_animation_idle_right;
}

Player::~Player()
{
}

void Player::on_update(int delta)
{
	const int direction = m_is_right_key_down - m_is_left_key_down;

	if (direction != 0)
	{
		m_is_facing_right = direction > 0;
		m_current_animation = m_is_facing_right ? &m_animation_run_right : &m_animation_run_left;
		const double distance = direction * m_run_velocity * delta;
		on_run(distance);
	}
	else
	{
		m_current_animation = m_is_facing_right ? &m_animation_idle_right : &m_animation_idle_left;
	}

	m_current_animation->on_update(delta);

	move_and_collide(delta);
}

void Player::on_draw(const Camera& camera)
{
	m_current_animation->on_draw(camera, (int)m_pos.x, (int)m_pos.y);
}

void Player::on_input(const ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (m_id)
		{
		case PlayerID::P1:
			switch (msg.vkcode)
			{
				// 'A'
			case 0x41:
				m_is_left_key_down = true;
				break;
				// 'D'
			case 0x44:
				m_is_right_key_down = true;
				break;
				// 'W'
			case 0x57:
				on_jump();
				break;
			}
			break;

		case PlayerID::P2:
			switch (msg.vkcode)
			{
				// '←'
			case VK_LEFT:
				m_is_left_key_down = true;
				break;
				// '→'
			case VK_RIGHT:
				m_is_right_key_down = true;
				break;
				// '↑'
			case VK_UP:
				on_jump();
				break;
			}
			break;
		}
		break;

	case WM_KEYUP:
		switch (m_id)
		{
		case PlayerID::P1:
			switch (msg.vkcode)
			{
				// 'A'
			case 0x41:
				m_is_left_key_down = false;
				break;
				// 'D'
			case 0x44:
				m_is_right_key_down = false;
				break;
			}
			break;

		case PlayerID::P2:
			switch (msg.vkcode)
			{
				// '←'
			case VK_LEFT:
				m_is_left_key_down = false;
				break;
				// '→'
			case VK_RIGHT:
				m_is_right_key_down = false;
				break;
			}
			break;
		}
		break;

	default:
		break;
	}

}

void Player::on_run(double distance)
{
	m_pos.x += distance;
}

void Player::on_jump()
{
	if (m_velocity.y != 0)
	{
		return;
	}

	m_velocity.y += m_jump_velocity;
}

void Player::move_and_collide(int delta)
{
	m_velocity.y += m_gravity * delta;
	m_pos += m_velocity * (double)delta;

	if (m_velocity.y > 0)
	{
		for (const Platform& platform : g_platform_list)
		{
			const auto& shape = platform.m_shape;
			const bool is_collide_x = ((std::max)(m_pos.x + m_size.x, shape.right) - (std::min)(m_pos.x, shape.left)
				<= m_size.x + (shape.right - shape.left));
			const bool is_collide_y = (m_pos.y <= shape.y && shape.y <= m_pos.y + m_size.y);

			// 碰撞检测，只有水平和竖直两个方向都发生碰撞才算发生碰撞
			if (is_collide_x && is_collide_y)
			{
				// 计算上一帧移动的距离
				const double delta_y = m_velocity.y * delta;
				// 计算上一帧角色脚底的位置
				const double last_tick_font_pos_y = m_pos.y + m_size.y - delta_y;
				// 只有上一帧角色脚底的位置在平台的上方，才进行位置矫正
				if (last_tick_font_pos_y <= shape.y)
				{
					m_pos.y = shape.y - m_size.y;
					m_velocity.y = 0;

					break;
				}
			}
		}
	}


}
