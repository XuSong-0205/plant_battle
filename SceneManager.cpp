#include "SceneManager.h"


void S_SceneManager::on_update(int delta)
{
	m_current_scene->on_update(delta);
}

void S_SceneManager::on_draw(const Camera& camera)
{
	m_current_scene->on_draw(camera);
}

void S_SceneManager::on_input(const ExMessage& msg)
{
	m_current_scene->on_input(msg);
}


void S_SceneManager::set_menu_scene(Scene* scene)
{
	m_menu_scene = scene;
}

void S_SceneManager::set_game_scene(Scene* scene)
{
	m_game_scene = scene;
}

void S_SceneManager::set_selector_scene(Scene* scene)
{
	m_selector_scene = scene;
}

void S_SceneManager::switch_to(SceneType type)
{
	m_current_scene->on_exit();
	set_current_scene(type);
}


void S_SceneManager::set_current_scene(SceneType type)
{
	switch (type)
	{
	case SceneType::Menu:
		set_current_scene(m_menu_scene);
		break;
	case SceneType::Game:
		set_current_scene(m_game_scene);
		break;
	case SceneType::Selector:
		set_current_scene(m_selector_scene);
		break;
	default:
		break;
	}
}

void S_SceneManager::set_current_scene(Scene* scene)
{
	m_current_scene = scene;
	m_current_scene->on_enter();
}