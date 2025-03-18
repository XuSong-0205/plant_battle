#pragma once

#include <memory>

#include "Utils.h"
#include "Scene.h"


// 场景管理器类
class S_SceneManager : public Singleton<S_SceneManager>
{
public:
	enum class SceneType
	{
		Menu,
		Game,
		Selector
	};


private:
	friend class Singleton<S_SceneManager>;
	S_SceneManager() = default;
	~S_SceneManager() = default;


public:
	void on_update(int delta);
	void on_draw(const Camera& camera);
	void on_input(const ExMessage& msg);

public:
	void set_menu_scene(Scene* scene);
	void set_game_scene(Scene* scene);
	void set_selector_scene(Scene* scene);
	void set_current_scene(SceneType type);
	void switch_to(SceneType type);


private:
	void set_current_scene(Scene* scene);

private:
	Scene* m_current_scene = nullptr;

	Scene* m_menu_scene = nullptr;
	Scene* m_game_scene = nullptr;
	Scene* m_selector_scene = nullptr;
};

