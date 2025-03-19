#pragma once

#include "Scene.h"
#include "Utils.h"
#include "Atlas.h"
#include "Animation.h"
#include "Camera.h"
#include "Timer.h"


extern IMAGE img_menu_background;


// Ö÷²Ëµ¥³¡¾°
class S_MenuScene : public Scene, public Singleton<S_MenuScene>
{
public:
	void on_enter() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;
	void on_input(const ExMessage& msg) override;
	void on_exit() override;

private:

};

