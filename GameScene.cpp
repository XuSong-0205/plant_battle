#include "GameScene.h"
#include "Utils.h"
#include "SceneManager.h"
#include "Platform.h"


extern IMAGE img_sky;						// 天空图片
extern IMAGE img_hills;						// 山脉图片
extern IMAGE img_platform_large;			// 大型平台图片
extern IMAGE img_platform_small;			// 小型平台图片

extern bool is_debug;						// 是否开启调试模式
extern Camera main_camera;					// 主摄像机
extern std::vector<Platform> platform_list;	// 游戏中的平台列表

///////////////////////////////////////////

void S_GameScene::on_enter()
{
	MCI_MUSIC_PLAY_LOOP("bgm_game");

	m_pos_img_sky.x = (getwidth() - img_sky.getwidth()) / 2;
	m_pos_img_sky.y = (getheight() - img_sky.getheight()) / 2;

	m_pos_img_hills.x = (getwidth() - img_hills.getwidth()) / 2;
	m_pos_img_hills.y = (getheight() - img_hills.getheight()) / 2;

	platform_list.resize(4);

	Platform& large_platform = platform_list[0];
	large_platform.m_img = &img_platform_large;
	large_platform.m_render_pos.x = 122;
	large_platform.m_render_pos.y = 455;
	large_platform.m_shape.left = large_platform.m_render_pos.x + 30;
	large_platform.m_shape.right = large_platform.m_render_pos.x + img_platform_large.getwidth() - 30;
	large_platform.m_shape.y = large_platform.m_render_pos.y + 60;

	Platform& small_platform_1 = platform_list[1];
	small_platform_1.m_img = &img_platform_small;
	small_platform_1.m_render_pos.x = 175;
	small_platform_1.m_render_pos.y = 360;
	small_platform_1.m_shape.left = small_platform_1.m_render_pos.x + 40;
	small_platform_1.m_shape.right = small_platform_1.m_render_pos.x + img_platform_small.getwidth() - 40;
	small_platform_1.m_shape.y = small_platform_1.m_render_pos.y + (double)img_platform_small.getheight() / 2;

	Platform& small_platform_2 = platform_list[2];
	small_platform_2.m_img = &img_platform_small;
	small_platform_2.m_render_pos.x = 855;
	small_platform_2.m_render_pos.y = 360;
	small_platform_2.m_shape.left = small_platform_2.m_render_pos.x + 40;
	small_platform_2.m_shape.right = small_platform_2.m_render_pos.x + img_platform_small.getwidth() - 40;
	small_platform_2.m_shape.y = small_platform_2.m_render_pos.y + (double)img_platform_small.getheight() / 2;

	Platform& small_platform_3 = platform_list[3];
	small_platform_3.m_img = &img_platform_small;
	small_platform_3.m_render_pos.x = 515;
	small_platform_3.m_render_pos.y = 225;
	small_platform_3.m_shape.left = small_platform_3.m_render_pos.x + 40;
	small_platform_3.m_shape.right = small_platform_3.m_render_pos.x + img_platform_small.getwidth() - 40;
	small_platform_3.m_shape.y = small_platform_3.m_render_pos.y + (double)img_platform_small.getheight() / 2;

}

void S_GameScene::on_update(int delta)
{

}

void S_GameScene::on_draw(const Camera& camera)
{
	putimage_alpha(camera, { m_pos_img_sky.x, m_pos_img_sky.y }, &img_sky);
	putimage_alpha(camera, { m_pos_img_hills.x, m_pos_img_hills.y }, &img_hills);

	for (auto& platform : platform_list)
	{
		platform.on_draw(camera);
	}

	if (is_debug)
	{
		settextcolor(RGB(255, 0, 0));
		outtextxy(15, 15, TEXT("已开启调试模式，按 'Q' 键关闭"));
	}
}

void S_GameScene::on_input(const ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYUP:
		switch (msg.vkcode)
		{
			// 'Q'
		case 0x51:
			is_debug = !is_debug;
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
