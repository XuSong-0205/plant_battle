#include "GameScene.h"
#include "Utils.h"
#include "SceneManager.h"
#include "Platform.h"
#include "Player.h"
#include "Bullet.h"



extern IMAGE img_sky;							// 天空图片
extern IMAGE img_hills;							// 山脉图片
extern IMAGE img_platform_large;				// 大型平台图片
extern IMAGE img_platform_small;				// 小型平台图片

extern bool g_is_debug;							// 是否开启调试模式
extern Camera g_main_camera;					// 主摄像机
extern std::vector<std::shared_ptr<Bullet>> g_bullet_list;	// 子弹列表
extern std::vector<Platform> g_platform_list;	// 游戏中的平台列表

extern std::unique_ptr<Player> g_player_1;		// 玩家 1
extern std::unique_ptr<Player> g_player_2;		// 玩家 2

extern IMAGE* g_img_player_1_avatar;			// 玩家 1 的头像
extern IMAGE* g_img_player_2_avatar;			// 玩家 2 的头像


///////////////////////////////////////////

void S_GameScene::on_enter()
{
	MCI_MUSIC_PLAY_LOOP("bgm_game");

	g_player_1->set_position({ 200, 50 });
	g_player_2->set_position({ 975, 50 });

	m_status_bar_1P.set_avatar(g_img_player_1_avatar);
	m_status_bar_2P.set_avatar(g_img_player_2_avatar);
	m_status_bar_1P.set_position({ 235, 625 });
	m_status_bar_2P.set_position({ 675, 625 });


	m_pos_img_sky.x = (getwidth() - img_sky.getwidth()) / 2;
	m_pos_img_sky.y = (getheight() - img_sky.getheight()) / 2;

	m_pos_img_hills.x = (getwidth() - img_hills.getwidth()) / 2;
	m_pos_img_hills.y = (getheight() - img_hills.getheight()) / 2;

	g_platform_list.resize(4);

	Platform& large_platform = g_platform_list[0];
	large_platform.m_img = &img_platform_large;
	large_platform.m_render_pos.x = 122;
	large_platform.m_render_pos.y = 455;
	large_platform.m_shape.left = large_platform.m_render_pos.x + 30;
	large_platform.m_shape.right = large_platform.m_render_pos.x + img_platform_large.getwidth() - 30;
	large_platform.m_shape.y = large_platform.m_render_pos.y + 60;

	Platform& small_platform_1 = g_platform_list[1];
	small_platform_1.m_img = &img_platform_small;
	small_platform_1.m_render_pos.x = 175;
	small_platform_1.m_render_pos.y = 360;
	small_platform_1.m_shape.left = small_platform_1.m_render_pos.x + 40;
	small_platform_1.m_shape.right = small_platform_1.m_render_pos.x + img_platform_small.getwidth() - 40;
	small_platform_1.m_shape.y = small_platform_1.m_render_pos.y + (double)img_platform_small.getheight() / 2;

	Platform& small_platform_2 = g_platform_list[2];
	small_platform_2.m_img = &img_platform_small;
	small_platform_2.m_render_pos.x = 855;
	small_platform_2.m_render_pos.y = 360;
	small_platform_2.m_shape.left = small_platform_2.m_render_pos.x + 40;
	small_platform_2.m_shape.right = small_platform_2.m_render_pos.x + img_platform_small.getwidth() - 40;
	small_platform_2.m_shape.y = small_platform_2.m_render_pos.y + (double)img_platform_small.getheight() / 2;

	Platform& small_platform_3 = g_platform_list[3];
	small_platform_3.m_img = &img_platform_small;
	small_platform_3.m_render_pos.x = 515;
	small_platform_3.m_render_pos.y = 225;
	small_platform_3.m_shape.left = small_platform_3.m_render_pos.x + 40;
	small_platform_3.m_shape.right = small_platform_3.m_render_pos.x + img_platform_small.getwidth() - 40;
	small_platform_3.m_shape.y = small_platform_3.m_render_pos.y + (double)img_platform_small.getheight() / 2;

}

void S_GameScene::on_update(int delta)
{
	g_player_1->on_update(delta);
	g_player_2->on_update(delta);

	g_main_camera.on_update(delta);

	g_bullet_list.erase(std::remove_if(g_bullet_list.begin(), g_bullet_list.end(),
		[](const std::shared_ptr<Bullet>& bullet)
		{
			return bullet->check_can_remove();
		}),
		g_bullet_list.end());

	for (auto& bullet : g_bullet_list)
	{
		bullet->on_update(delta);
	}

	m_status_bar_1P.set_hp(g_player_1->get_hp());
	m_status_bar_1P.set_mp(g_player_1->get_mp());
	m_status_bar_2P.set_hp(g_player_2->get_hp());
	m_status_bar_2P.set_mp(g_player_2->get_mp());
}

void S_GameScene::on_draw(const Camera& camera)
{
	putimage_alpha(camera, { m_pos_img_sky.x, m_pos_img_sky.y }, &img_sky);
	putimage_alpha(camera, { m_pos_img_hills.x, m_pos_img_hills.y }, &img_hills);

	for (auto& platform : g_platform_list)
	{
		platform.on_draw(camera);
	}

	if (g_is_debug)
	{
		settextcolor(RGB(255, 0, 0));
		outtextxy(15, 15, TEXT("已开启调试模式，按 'Q' 键关闭"));
	}

	g_player_1->on_draw(camera);
	g_player_2->on_draw(camera);

	for (auto& bullet : g_bullet_list)
	{
		bullet->on_draw(camera);
	}

	m_status_bar_1P.on_draw();
	m_status_bar_2P.on_draw();
}

void S_GameScene::on_input(const ExMessage& msg)
{
	g_player_1->on_input(msg);
	g_player_2->on_input(msg);

	switch (msg.message)
	{
	case WM_KEYUP:
		switch (msg.vkcode)
		{
			// 'Q'
		case 0x51:
			g_is_debug = !g_is_debug;
			break;

			// ESC
		case VK_ESCAPE:
			Singleton<S_SceneManager>::get_instance().switch_to(S_SceneManager::SceneType::Menu);
			break;
		}
		break;



	default:
		break;
	}
}

void S_GameScene::on_exit()
{
	MCI_MUSIC_STOP("bgm_game");
}
