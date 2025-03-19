#include "MenuScene.h"
#include "Utils.h"
#include "SceneManager.h"

extern bool g_is_game_running;


void S_MenuScene::on_enter() 
{
	MCI_MUSIC_PLAY_LOOP("bgm_menu");
}

void S_MenuScene::on_update(int delta)
{

}

void S_MenuScene::on_draw(const Camera& camera)
{
	putimage(0, 0, &img_menu_background);
}

void S_MenuScene::on_input(const ExMessage& msg)
{
	if (msg.message == WM_KEYUP)
	{
		if (msg.vkcode == VK_ESCAPE)
		{
			g_is_game_running = false;
		}
		else
		{
			MCI_MUSIC_PLAY_LOOP("ui_confirm");
			Singleton<S_SceneManager>::get_instance().switch_to(S_SceneManager::SceneType::Selector);
		}
	}
}

void S_MenuScene::on_exit()
{

}