#pragma once

#include "Scene.h"
#include "Utils.h"
#include "Animation.h"
#include "SceneManager.h"


// ѡ�񳡾���
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
	POINT m_pos_img_VS{ 0, 0 };								// VS ������ͼƬλ��
	POINT m_pos_img_tip{ 0, 0 };							// ��ʾ��Ϣ�ı�ͼƬλ��
	POINT m_pos_img_1P{ 0, 0 };								// 1P �ı�ͼƬλ��
	POINT m_pos_img_2P{ 0, 0 };								// 2P �ı�ͼƬλ��
	POINT m_pos_img_1P_desc{ 0, 0 };						// 1P ��λ����ͼƬλ��
	POINT m_pos_img_2P_desc{ 0, 0 };						// 2P ��λ����ͼƬλ��
	POINT m_pos_img_1P_name{ 0, 0 };						// 1P ��ɫ�����ı�λ��
	POINT m_pos_img_2P_name{ 0, 0 };						// 2P ��ɫ�����ı�λ��
	POINT m_pos_aninmation_1P{ 0, 0 };						// 1P ��ɫ����λ��
	POINT m_pos_aninmation_2P{ 0, 0 };						// 2P ��ɫ����λ��
	POINT m_pos_img_1P_gravestone{ 0, 0 };					// 1P Ĺ��ͼƬλ��
	POINT m_pos_img_2P_gravestone{ 0, 0 };					// 2P Ĺ��ͼƬλ��
	POINT m_pos_1P_selector_btn_left{ 0, 0 };				// 1P ����ѡ��ťλ��
	POINT m_pos_1P_selector_btn_right{ 0, 0 };				// 1P ����ѡ��ťλ��
	POINT m_pos_2P_selector_btn_left{ 0, 0 };				// 2P ����ѡ��ťλ��
	POINT m_pos_2P_selector_btn_right{ 0, 0 };				// 2P ����ѡ��ťλ��

	Animation m_animation_peashooter;						// �㶹���ֶ���
	Animation m_animation_sunflower;						// ���տ�����

	PlayerType m_player_type_1p = PlayerType::Peashooter;	// 1P ��ɫ����
	PlayerType m_player_type_2p = PlayerType::Sunflower;	// 2P ��ɫ����

	LPCTSTR m_str_peashooter_name = TEXT("������");		// �㶹���ֽ�ɫ����
	LPCTSTR m_str_sunflower_name = TEXT("���տ�");			// ���տ���ɫ����


	int m_selector_background_scorll_offset_x = 0;			// ѡ�񱳾���������

	bool m_is_btn_1P_left_down = false;						// 1P ����ѡ��ť�Ƿ���
	bool m_is_btn_1P_right_down = false;					// 1P ����ѡ��ť�Ƿ���
	bool m_is_btn_2P_left_down = false;						// 2P ����ѡ��ť�Ƿ���
	bool m_is_btn_2P_right_down = false;					// 2P ����ѡ��ť�Ƿ���

};

