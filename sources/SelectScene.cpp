#include "SelectScene.h"
#include "Utils.h"
#include "Player.h"
#include "PeashooterPlayer.h"
#include "SunflowerPlayer.h"
#include "PlayerID.h"

///////////////////////////////////////////


extern IMAGE img_VS;
extern IMAGE img_1P;
extern IMAGE img_2P;
extern IMAGE img_1P_desc;
extern IMAGE img_2P_desc;
extern IMAGE img_gravestone_left;
extern IMAGE img_gravestone_right;
extern IMAGE img_selector_tip;
extern IMAGE img_selector_background;
extern IMAGE img_1P_selector_btn_idle_left;
extern IMAGE img_1P_selector_btn_idle_right;
extern IMAGE img_1P_selector_btn_down_left;
extern IMAGE img_1P_selector_btn_down_right;
extern IMAGE img_2P_selector_btn_idle_left;
extern IMAGE img_2P_selector_btn_idle_right;
extern IMAGE img_2P_selector_btn_down_left;
extern IMAGE img_2P_selector_btn_down_right;
extern IMAGE img_peashooter_selector_background_left;
extern IMAGE img_peashooter_selector_background_right;
extern IMAGE img_sunflower_selector_background_left;
extern IMAGE img_sunflower_selector_background_right;

extern Atlas atlas_peashooter_idle_right;
extern Atlas atlas_sunflower_idle_right;

extern IMAGE img_avatar_peashooter;
extern IMAGE img_avatar_sunflower;

extern std::unique_ptr<Player> g_player_1;
extern std::unique_ptr<Player> g_player_2;

///////////////////////////////////////////


void S_SelectScene::on_enter()
{
	m_animation_peashooter.set_atlas(&atlas_peashooter_idle_right);
	m_animation_sunflower.set_atlas(&atlas_sunflower_idle_right);
	m_animation_peashooter.set_interval(100);
	m_animation_sunflower.set_interval(100);

	static constexpr int OFFSET_X = 50;

	m_pos_img_VS.x = (getwidth() - img_VS.getwidth()) / 2;
	m_pos_img_VS.y = (getheight() - img_VS.getheight()) / 2;
	m_pos_img_tip.x = (getwidth() - img_selector_tip.getwidth()) / 2;
	m_pos_img_tip.y = getheight() - 125;
	m_pos_img_1P.x = (getwidth() / 2 - img_1P.getwidth()) / 2 - OFFSET_X;
	m_pos_img_1P.y = 35;
	m_pos_img_2P.x = getwidth() / 2 + (getwidth() / 2 - img_2P.getwidth()) / 2 + OFFSET_X;
	m_pos_img_2P.y = m_pos_img_1P.y;
	m_pos_img_1P_desc.x = (getwidth() / 2 - img_1P_desc.getwidth()) / 2 - OFFSET_X;
	m_pos_img_1P_desc.y = getheight() - 150;
	m_pos_img_2P_desc.x = getwidth() / 2 + (getwidth() / 2 - img_2P_desc.getwidth()) / 2 + OFFSET_X;
	m_pos_img_2P_desc.y = m_pos_img_1P_desc.y;
	m_pos_img_1P_gravestone.x = (getwidth() / 2 - img_gravestone_right.getwidth()) / 2 - OFFSET_X;
	m_pos_img_1P_gravestone.y = m_pos_img_1P.y + img_1P.getheight() + 35;
	m_pos_img_2P_gravestone.x = getwidth() / 2 + (getwidth() / 2 - img_gravestone_left.getwidth()) / 2 + OFFSET_X;
	m_pos_img_2P_gravestone.y = m_pos_img_1P_gravestone.y;
	m_pos_aninmation_1P.x = (getwidth() / 2 - atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 - OFFSET_X;
	m_pos_aninmation_1P.y = m_pos_img_1P_gravestone.y + 80;
	m_pos_aninmation_2P.x = getwidth() / 2 + (getwidth() / 2 - atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 + OFFSET_X;
	m_pos_aninmation_2P.y = m_pos_aninmation_1P.y;
	m_pos_img_1P_name.y = m_pos_aninmation_1P.y + 155;
	m_pos_img_2P_name.y = m_pos_img_1P_name.y;
	m_pos_1P_selector_btn_left.x = m_pos_img_1P_gravestone.x - img_1P_selector_btn_idle_left.getwidth();
	m_pos_1P_selector_btn_left.y = m_pos_img_1P_gravestone.y + (img_gravestone_right.getheight() - img_1P_selector_btn_idle_left.getheight()) / 2;
	m_pos_1P_selector_btn_right.x = m_pos_img_1P_gravestone.x + img_gravestone_right.getwidth();
	m_pos_1P_selector_btn_right.y = m_pos_1P_selector_btn_left.y;
	m_pos_2P_selector_btn_left.x = m_pos_img_2P_gravestone.x - img_2P_selector_btn_idle_left.getwidth();
	m_pos_2P_selector_btn_left.y = m_pos_1P_selector_btn_left.y;
	m_pos_2P_selector_btn_right.x = m_pos_img_2P_gravestone.x + img_gravestone_left.getwidth();
	m_pos_2P_selector_btn_right.y = m_pos_2P_selector_btn_left.y;
}

void S_SelectScene::on_update(int delta)
{
	m_animation_peashooter.on_update(delta);
	m_animation_sunflower.on_update(delta);

	m_selector_background_scorll_offset_x += 5;
	if (m_selector_background_scorll_offset_x >= img_peashooter_selector_background_left.getwidth())
	{
		m_selector_background_scorll_offset_x = 0;
	}
}

void S_SelectScene::on_draw(const Camera& camera)
{
	IMAGE* img_p1_selector_background = nullptr;
	IMAGE* img_p2_selector_background = nullptr;

	switch (m_player_type_1p)
	{
		case PlayerType::Peashooter:
			img_p2_selector_background = &img_peashooter_selector_background_left;
			break;
		case PlayerType::Sunflower:
			img_p2_selector_background = &img_sunflower_selector_background_left;
			break;
		default:
			img_p2_selector_background = &img_peashooter_selector_background_left;
			break;
	}

	switch (m_player_type_2p)
	{
		case PlayerType::Peashooter:
			img_p1_selector_background = &img_peashooter_selector_background_right;
			break;
		case PlayerType::Sunflower:
			img_p1_selector_background = &img_sunflower_selector_background_right;
			break;
		default:
			img_p1_selector_background = &img_peashooter_selector_background_right;
			break;
	}


	putimage(0, 0, &img_selector_background);

	putimage_alpha(m_selector_background_scorll_offset_x - img_p1_selector_background->getwidth(), 0, img_p1_selector_background);
	putimage_alpha(m_selector_background_scorll_offset_x, 0,
		img_p1_selector_background->getwidth() - m_selector_background_scorll_offset_x, 0,
		img_p1_selector_background, 0, 0);
	putimage_alpha(getwidth() - img_p2_selector_background->getwidth(), 0,
		img_p2_selector_background->getwidth() - m_selector_background_scorll_offset_x, 0,
		img_p2_selector_background, m_selector_background_scorll_offset_x, 0);
	putimage_alpha(getwidth() - m_selector_background_scorll_offset_x, 0, img_p2_selector_background);

	putimage_alpha(m_pos_img_VS.x, m_pos_img_VS.y, &img_VS);

	putimage_alpha(m_pos_img_1P.x, m_pos_img_1P.y, &img_1P);
	putimage_alpha(m_pos_img_2P.x, m_pos_img_2P.y, &img_2P);
	putimage_alpha(m_pos_img_1P_gravestone.x, m_pos_img_1P_gravestone.y, &img_gravestone_right);
	putimage_alpha(m_pos_img_2P_gravestone.x, m_pos_img_2P_gravestone.y, &img_gravestone_left);


	switch (m_player_type_1p)
	{
		case PlayerType::Peashooter:
			m_animation_peashooter.on_draw(camera, m_pos_aninmation_1P.x, m_pos_aninmation_1P.y);
			m_pos_img_1P_name.x = m_pos_img_1P_gravestone.x + (img_gravestone_right.getwidth() - textwidth(m_str_peashooter_name)) / 2;
			outtextxy_shaded(m_pos_img_1P_name.x, m_pos_img_1P_name.y, m_str_peashooter_name);
			break;
		case PlayerType::Sunflower:
			m_animation_sunflower.on_draw(camera, m_pos_aninmation_1P.x, m_pos_aninmation_1P.y);
			m_pos_img_1P_name.x = m_pos_img_1P_gravestone.x + (img_gravestone_right.getwidth() - textwidth(m_str_sunflower_name)) / 2;
			outtextxy_shaded(m_pos_img_1P_name.x, m_pos_img_1P_name.y, m_str_sunflower_name);
			break;
	}

	switch (m_player_type_2p)
	{
		case PlayerType::Peashooter:
			m_animation_peashooter.on_draw(camera, m_pos_aninmation_2P.x, m_pos_aninmation_2P.y);
			m_pos_img_2P_name.x = m_pos_img_2P_gravestone.x + (img_gravestone_left.getwidth() - textwidth(m_str_peashooter_name)) / 2;
			outtextxy_shaded(m_pos_img_2P_name.x, m_pos_img_2P_name.y, m_str_peashooter_name);
			break;
		case PlayerType::Sunflower:
			m_animation_sunflower.on_draw(camera, m_pos_aninmation_2P.x, m_pos_aninmation_2P.y);
			m_pos_img_2P_name.x = m_pos_img_2P_gravestone.x + (img_gravestone_left.getwidth() - textwidth(m_str_sunflower_name)) / 2;
			outtextxy_shaded(m_pos_img_2P_name.x, m_pos_img_2P_name.y, m_str_sunflower_name);
			break;
	}


	putimage_alpha(m_pos_1P_selector_btn_left.x, m_pos_1P_selector_btn_left.y,
		m_is_btn_1P_left_down ? &img_1P_selector_btn_down_left : &img_1P_selector_btn_idle_left);
	putimage_alpha(m_pos_1P_selector_btn_right.x, m_pos_1P_selector_btn_right.y,
		m_is_btn_1P_right_down ? &img_1P_selector_btn_down_right : &img_1P_selector_btn_idle_right);
	putimage_alpha(m_pos_2P_selector_btn_left.x, m_pos_2P_selector_btn_left.y,
		m_is_btn_2P_left_down ? &img_2P_selector_btn_down_left : &img_2P_selector_btn_idle_left);
	putimage_alpha(m_pos_2P_selector_btn_right.x, m_pos_2P_selector_btn_right.y,
		m_is_btn_2P_right_down ? &img_2P_selector_btn_down_right : &img_2P_selector_btn_idle_right);

	
	putimage_alpha(m_pos_img_1P_desc.x, m_pos_img_1P_desc.y, &img_1P_desc);
	putimage_alpha(m_pos_img_2P_desc.x, m_pos_img_2P_desc.y, &img_2P_desc);

	putimage_alpha(m_pos_img_tip.x, m_pos_img_tip.y, &img_selector_tip);
}

void S_SelectScene::on_input(const ExMessage& msg)
{
	static auto change_player_type = [](PlayerType& player_type, int offset)
		{
			player_type = (PlayerType)(((int)PlayerType::Invalid + (int)player_type + offset) % (int)PlayerType::Invalid);
			MCI_MUSIC_PLAY("ui_switch");
		};

	switch (msg.message)
	{
		case WM_KEYDOWN:
			switch (msg.vkcode)
			{
				// 'A'
			case 0x41:
				m_is_btn_1P_left_down = true;
				break;
				// 'D'
			case 0x44:
				m_is_btn_1P_right_down = true;
				break;
				// '¡û'
			case VK_LEFT:
				m_is_btn_2P_left_down = true;
				break;
				// '¡ú'
			case VK_RIGHT:
				m_is_btn_2P_right_down = true;
				break;
			}
			break;

		case WM_KEYUP:
			switch (msg.vkcode)
			{
				// 'A'
			case 0x41:
				m_is_btn_1P_left_down = false;
				change_player_type(m_player_type_1p, -1);
				break;
				// 'D'
			case 0x44:
				m_is_btn_1P_right_down = false;
				change_player_type(m_player_type_1p, 1);
				break;
				// '¡û'
			case VK_LEFT:
				m_is_btn_2P_left_down = false;
				change_player_type(m_player_type_2p, -1);
				break;
				// '¡ú'
			case VK_RIGHT:
				m_is_btn_2P_right_down = false;
				change_player_type(m_player_type_2p, 1);
				break;

				// Enter
			case VK_RETURN:
				Singleton<S_SceneManager>::get_instance().switch_to(S_SceneManager::SceneType::Game);
				MCI_MUSIC_PLAY("ui_confirm");
				break;

				// Esc
			case VK_ESCAPE:
				Singleton<S_SceneManager>::get_instance().switch_to(S_SceneManager::SceneType::Menu);
				break;
			}
			break;

		default:
			break;
	}



}

void S_SelectScene::on_exit()
{
	MCI_MUSIC_STOP("bgm_menu");

	switch (m_player_type_1p)
	{
		case PlayerType::Peashooter:
			g_player_1 = std::make_unique<PeashooterPlayer>();
			break;
		case PlayerType::Sunflower:
			g_player_1 = std::make_unique<SunflowerPlayer>();
			break;
	}
	g_player_1->set_id(PlayerID::P1);

	switch (m_player_type_2p)
	{
		case PlayerType::Peashooter:
			g_player_2 = std::make_unique<PeashooterPlayer>();
			break;
		case PlayerType::Sunflower:
			g_player_2 = std::make_unique<SunflowerPlayer>();
			break;
	}
	g_player_2->set_id(PlayerID::P2);

}
