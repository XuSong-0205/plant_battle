#include <Windows.h>
#include <easyx.h>
#include <ctime>
#include <memory>
#include <vector>

#include "Utils.h"
#include "Scene.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "SelectScene.h"
#include "SceneManager.h"
#include "Camera.h"
#include "Platform.h"
#include "Player.h"
#include "Resources.h"

///////////////////////////////////////

bool g_is_debug = false;				// 是否开启调试模式

bool g_is_game_running = true;			// 游戏是否正在运行

Camera g_main_camera;					// 主摄像机

std::vector<Platform> g_platform_list;	// 游戏中的平台列表

std::unique_ptr<Player> g_player_1;		// 玩家 1
std::unique_ptr<Player> g_player_2;		// 玩家 2


///////////////////////////////////////

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	load_game_resources();


	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, EX_SHOWCONSOLE);

	settextstyle(28, 0, TEXT("IPix"));
	setbkmode(TRANSPARENT);
	BeginBatchDraw();


	S_MenuScene& menu_scene = Singleton<S_MenuScene>::get_instance();
	S_GameScene& game_scene = Singleton<S_GameScene>::get_instance();
	S_SelectScene& select_scene = Singleton<S_SelectScene>::get_instance();
	S_SceneManager& scene_manager = Singleton<S_SceneManager>::get_instance();
	scene_manager.set_menu_scene(&menu_scene);
	scene_manager.set_game_scene(&game_scene);
	scene_manager.set_selector_scene(&select_scene);
	scene_manager.set_current_scene(S_SceneManager::SceneType::Menu);


	ExMessage msg;
	while (g_is_game_running)
	{
		const auto frame_start_time = GetTickCount64();

		while (peekmessage(&msg))
		{
			scene_manager.on_input(msg);
		}

		static auto last_tick = GetTickCount64();
		auto curr_tick = GetTickCount64();
		const auto delta_tick = curr_tick - last_tick;
		scene_manager.on_update(static_cast<int>(delta_tick));
		last_tick = curr_tick;


		cleardevice();
		scene_manager.on_draw(g_main_camera);

		FlushBatchDraw();

		const auto frame_end_time = GetTickCount64();
		const auto frame_delta_time = frame_end_time - frame_start_time;
		if (frame_delta_time < 1000 / GAME_FPS)
		{
			Sleep(1000 / GAME_FPS - frame_delta_time);
		}

	}

	EndBatchDraw();
	closegraph();

	return 0;
}



