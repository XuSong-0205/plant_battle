#pragma once

#include "Scene.h"
#include "Utils.h"


// 游戏场景类
class S_GameScene : public Scene, public Singleton<S_GameScene>
{
public:
	void on_enter() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;
	void on_input(const ExMessage& msg) override;
	void on_exit() override;

private:
	POINT m_pos_img_sky{ 0, 0 };		// 天空背景图位置
	POINT m_pos_img_hills{ 0, 0 };		// 山脉背景图位置

};

