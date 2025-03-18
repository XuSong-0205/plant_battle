#pragma once

#include "Scene.h"
#include "Utils.h"


// ��Ϸ������
class S_GameScene : public Scene, public Singleton<S_GameScene>
{
public:
	void on_enter() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;
	void on_input(const ExMessage& msg) override;
	void on_exit() override;

private:
	POINT m_pos_img_sky{ 0, 0 };		// ��ձ���ͼλ��
	POINT m_pos_img_hills{ 0, 0 };		// ɽ������ͼλ��

};

