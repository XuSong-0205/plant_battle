#include "Player.h"
#include "Platform.h"
#include "Bullet.h"
#include "Utils.h"


extern bool g_is_debug;

extern std::vector<std::shared_ptr<Bullet>> g_bullet_list;
extern std::vector<Platform> g_platform_list;	// 游戏中的平台列表



Player::Player()
{
	m_current_animation = &m_animation_idle_right;

	m_timer_attack_cd.set_wait_time(m_attack_cd);
	m_timer_attack_cd.set_repeat(false);
	m_timer_attack_cd.set_callback([&]()
		{
			m_can_attack = true;
		});

	m_timer_invulnerable.set_wait_time(750);
	m_timer_invulnerable.set_repeat(false);
	m_timer_invulnerable.set_callback([&]()
		{
			m_is_invulnerable = false;
		});

	m_timer_invulnerable_blink.set_wait_time(75);
	m_timer_invulnerable_blink.set_repeat(true);
	m_timer_invulnerable_blink.set_callback([&]()
		{
			m_is_showing_sketch_frame = !m_is_showing_sketch_frame;
		});

}

Player::~Player()
{
}

void Player::on_update(int delta)
{
	const int direction = m_is_right_key_down - m_is_left_key_down;

	if (direction != 0)
	{
		if (!m_is_attacking_ex)
		{
			m_is_facing_right = direction > 0;
		}
		m_current_animation = m_is_facing_right ? &m_animation_run_right : &m_animation_run_left;
		const double distance = direction * m_run_velocity * delta;
		on_run(distance);
	}
	else
	{
		m_current_animation = m_is_facing_right ? &m_animation_idle_right : &m_animation_idle_left;
	}

	if (m_is_attacking_ex)
	{
		m_current_animation = m_is_facing_right ? &m_animation_attack_ex_right : &m_animation_attack_ex_left;
	}

	m_current_animation->on_update(delta);

	m_timer_attack_cd.on_update(delta);
	m_timer_invulnerable.on_update(delta);
	m_timer_invulnerable_blink.on_update(delta);

	if (m_is_showing_sketch_frame)
	{
		sketch_image(m_current_animation->get_frame(), &m_img_sketch);
	}

	move_and_collide(delta);
}

void Player::on_draw(const Camera& camera)
{
	if (m_hp > 0 && m_is_invulnerable && m_is_showing_sketch_frame)
	{
		putimage_alpha(camera, m_pos, &m_img_sketch);
	}
	else
	{
		m_current_animation->on_draw(camera, (int)m_pos.x, (int)m_pos.y);
	}

	if (g_is_debug)
	{
		setlinecolor(RGB(0, 125, 255));
		rectangle((int)m_pos.x, (int)m_pos.y, (int)(m_pos.x + m_size.x), (int)(m_pos.y + m_size.y));
	}
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
				// 'F'
			case 0x46:
				if (m_can_attack)
				{
					on_attack();
					m_can_attack = false;
					m_timer_attack_cd.restart();
				}
				break;
				// 'G'
			case 0x47:
				if (m_mp >= 100)
				{
					on_attack_ex();
					m_mp = 0;
				}
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
				// '.'
			case VK_OEM_PERIOD:
				if (m_can_attack)
				{
					on_attack();
					m_can_attack = false;
					m_timer_attack_cd.restart();
				}
				break;
				// '/'
			case VK_OEM_2:
				if (m_mp >= 100)
				{
					on_attack_ex();
					m_mp = 0;
				}
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
	if (m_is_attacking_ex)
	{
		return;
	}

	m_pos.x += distance;
}

void Player::on_jump()
{
	if (m_is_attacking_ex)
	{
		return;
	}

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

	if (!m_is_invulnerable)
	{
		for (auto& bullet : g_bullet_list)
		{
			if (!bullet->is_valid() || bullet->get_collide_target() != m_id)
			{
				continue;
			}

			if (bullet->check_collide(m_pos, m_size))
			{
				make_invulnerable();
				bullet->on_collide();
				bullet->set_valid(false);
				m_hp -= bullet->get_damage();
			}

		}
	}

}

void Player::make_invulnerable()
{
	m_is_invulnerable = true;
	m_timer_invulnerable.restart();
}
