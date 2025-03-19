#pragma once

#include "Scene.h"
#include "Utils.h"
#include "Animation.h"
#include "SceneManager.h"


// 选择场景类
class S_SelectScene : public Scene, public Singleton<S_SelectScene>
{
public:
	void on_enter() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;
	void on_input(const ExMessage& msg) override;
	void on_exit() override;


private:
	enum class PlayerType
	{
		Peashooter,
		Sunflower,
		Invalid
	};

private:
	POINT m_pos_img_VS{ 0, 0 };								// VS 艺术字图片位置
	POINT m_pos_img_tip{ 0, 0 };							// 提示信息文本图片位置
	POINT m_pos_img_1P{ 0, 0 };								// 1P 文本图片位置
	POINT m_pos_img_2P{ 0, 0 };								// 2P 文本图片位置
	POINT m_pos_img_1P_desc{ 0, 0 };						// 1P 键位描述图片位置
	POINT m_pos_img_2P_desc{ 0, 0 };						// 2P 键位描述图片位置
	POINT m_pos_img_1P_name{ 0, 0 };						// 1P 角色名字文本位置
	POINT m_pos_img_2P_name{ 0, 0 };						// 2P 角色名字文本位置
	POINT m_pos_aninmation_1P{ 0, 0 };						// 1P 角色动画位置
	POINT m_pos_aninmation_2P{ 0, 0 };						// 2P 角色动画位置
	POINT m_pos_img_1P_gravestone{ 0, 0 };					// 1P 墓碑图片位置
	POINT m_pos_img_2P_gravestone{ 0, 0 };					// 2P 墓碑图片位置
	POINT m_pos_1P_selector_btn_left{ 0, 0 };				// 1P 向左选择按钮位置
	POINT m_pos_1P_selector_btn_right{ 0, 0 };				// 1P 向右选择按钮位置
	POINT m_pos_2P_selector_btn_left{ 0, 0 };				// 2P 向左选择按钮位置
	POINT m_pos_2P_selector_btn_right{ 0, 0 };				// 2P 向右选择按钮位置

	Animation m_animation_peashooter;						// 豌豆射手动画
	Animation m_animation_sunflower;						// 龙日葵动画

	PlayerType m_player_type_1p = PlayerType::Peashooter;	// 1P 角色类型
	PlayerType m_player_type_2p = PlayerType::Sunflower;	// 2P 角色类型

	LPCTSTR m_str_peashooter_name = TEXT("婉逗射手");		// 豌豆射手角色名字
	LPCTSTR m_str_sunflower_name = TEXT("龙日葵");			// 龙日葵角色名字


	int m_selector_background_scorll_offset_x = 0;			// 选择背景滚动距离

	bool m_is_btn_1P_left_down = false;						// 1P 向左选择按钮是否按下
	bool m_is_btn_1P_right_down = false;					// 1P 向右选择按钮是否按下
	bool m_is_btn_2P_left_down = false;						// 2P 向左选择按钮是否按下
	bool m_is_btn_2P_right_down = false;					// 2P 向右选择按钮是否按下

};

