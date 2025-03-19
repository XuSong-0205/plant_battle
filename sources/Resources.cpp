#include "Resources.h"
#include "Utils.h"
#include "Atlas.h"

#include <memory>


///////////////////////////////////////////////

IMAGE img_menu_background;				// ���˵�����ͼƬ

IMAGE img_VS;							// VS ������ͼƬ
IMAGE img_1P;							// 1P �ı�ͼƬ
IMAGE img_2P;							// 2P �ı�ͼƬ
IMAGE img_1P_desc;						// 1P ��λ����ͼƬ
IMAGE img_2P_desc;						// 2P ��λ����ͼƬ
IMAGE img_gravestone_left;				// �������Ĺ��ͼƬ
IMAGE img_gravestone_right;				// �����ҵ�Ĺ��ͼƬ
IMAGE img_selector_tip;					// ѡ�ǽ�����ʾ��Ϣ�ı�ͼƬ
IMAGE img_selector_background;			// ѡ�ǽ��汳��ͼ
IMAGE img_1P_selector_btn_idle_left;	// 1P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img_1P_selector_btn_idle_right;	// 1P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img_1P_selector_btn_down_left;	// 1P ����ѡ��ť����״̬ͼƬ
IMAGE img_1P_selector_btn_down_right;	// 1P ����ѡ��ť����״̬ͼƬ
IMAGE img_2P_selector_btn_idle_left;	// 2P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img_2P_selector_btn_idle_right;	// 2P ����ѡ��ťĬ��״̬ͼƬ
IMAGE img_2P_selector_btn_down_left;	// 2P ����ѡ��ť����״̬ͼƬ
IMAGE img_2P_selector_btn_down_right;	// 2P ����ѡ��ť����״̬ͼƬ
IMAGE img_peashooter_selector_background_left;	// ѡ�ǽ��泯������㶹���ֱ���ͼƬ
IMAGE img_peashooter_selector_background_right;	// ѡ�ǽ��泯���ҵ��㶹���ֱ���ͼƬ
IMAGE img_sunflower_selector_background_left;	// ѡ�ǽ��泯��������տ�����ͼƬ
IMAGE img_sunflower_selector_background_right;	// ѡ�ǽ��泯���ҵ����տ�����ͼƬ

IMAGE img_sky;							// ���ͼƬ
IMAGE img_hills;						// ɽ��ͼƬ
IMAGE img_platform_large;				// ����ƽ̨ͼƬ
IMAGE img_platform_small;				// С��ƽ̨ͼƬ

IMAGE img_1P_cursor;					// 1P ָʾ���ͼƬ
IMAGE img_2P_cursor;					// 2P ָʾ���ͼƬ

Atlas atlas_peashooter_idle_left;		// �㶹���ֳ������Ĭ�϶���ͼ��
Atlas atlas_peashooter_idle_right;		// �㶹���ֳ����ҵ�Ĭ�϶���ͼ��
Atlas atlas_peashooter_run_left;		// �㶹���ֳ�����ı��ܶ���ͼ��
Atlas atlas_peashooter_run_right;		// �㶹���ֳ����ҵı��ܶ���ͼ��
Atlas atlas_peashooter_attack_ex_left;	// �㶹���ֳ���������⹥������ͼ��
Atlas atlas_peashooter_attack_ex_right;	// �㶹���ֳ����ҵ����⹥������ͼ��
Atlas atlas_peashooter_die_left;		// �㶹���ֳ��������������ͼ��
Atlas atlas_peashooter_die_right;		// �㶹���ֳ����ҵ���������ͼ��

Atlas atlas_sunflower_idle_left;		// ���տ��������Ĭ�϶���ͼ��
Atlas atlas_sunflower_idle_right;		// ���տ������ҵ�Ĭ�϶���ͼ��
Atlas atlas_sunflower_run_left;			// ���տ�������ı��ܶ���ͼ��
Atlas atlas_sunflower_run_right;		// ���տ������ҵı��ܶ���ͼ��
Atlas atlas_sunflower_attack_ex_left;	// ���տ�����������⹥������ͼ��
Atlas atlas_sunflower_attack_ex_right;	// ���տ������ҵ����⹥������ͼ��
Atlas atlas_sunflower_die_left;			// ���տ����������������ͼ��
Atlas atlas_sunflower_die_right;		// ���տ������ҵ���������ͼ��

IMAGE img_pea;							// �㶹ͼƬ
Atlas atlas_pea_break;					// �㶹���鶯��ͼ��
Atlas atlas_sun;						// �չ⶯��ͼ��
Atlas atlas_sun_explode;				// �չⱬը����ͼ��
Atlas atlas_sun_ex;						// �չ���Ч����ͼ��
Atlas atlas_sun_ex_explode;				// �չ���Ч��ը����ͼ��
Atlas atlas_sun_text;					// ���ա��ı�����ͼ��

Atlas atlas_run_effect;					// ������Ч����ͼ��
Atlas atlas_jump_effect;				// ��Ծ��Ч����ͼ��
Atlas atlas_land_effect;				// ��½��Ч����ͼ��

IMAGE img_1P_winner;					// 1P ʤ���ı�ͼƬ
IMAGE img_2P_winner;					// 2P ʤ���ı�ͼƬ
IMAGE img_winnner_bar;					// ʤ������ı�����ͼƬ

IMAGE img_avatar_peashooter;			// �㶹����ͷ��ͼƬ
IMAGE img_avatar_sunflower;				// ���տ�ͷ��ͼƬ


///////////////////////////////////////////////


// ������Ϸ��Դ
void load_game_resources()
{
	// ����������Ϸ��Դ

	// ��������
	AddFontResourceEx(TEXT("resources/font/IPix.ttf"), FR_PRIVATE, NULL);


	// ��������
	mciSendString(TEXT("open resources/music/bgm_game.mp3 alias bgm_game"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/bgm_menu.mp3 alias bgm_menu"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/pea_break_1.mp3 alias pea_break_1"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/pea_break_2.mp3 alias pea_break_2"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/pea_break_3.mp3 alias pea_break_3"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/pea_shoot_1.mp3 alias pea_shoot_1"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/pea_shoot_2.mp3 alias pea_shoot_2"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/pea_shoot_ex.mp3 alias pea_shoot_ex"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/sun_explode.mp3 alias sun_explode"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/sun_explode_ex.mp3 alias sun_explode_ex"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/sun_text.mp3 alias sun_text"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/ui_confirm.wav alias ui_confirm"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/ui_switch.wav alias ui_switch"), nullptr, 0, nullptr);
	mciSendString(TEXT("open resources/music/ui_win.wav alias ui_win"), nullptr, 0, nullptr);


	// ����ͼƬ��ͼ��
	loadimage(&img_menu_background, TEXT("resources/image/menu_background.png"));

	loadimage(&img_VS, TEXT("resources/image/VS.png"));
	loadimage(&img_1P, TEXT("resources/image/1P.png"));
	loadimage(&img_2P, TEXT("resources/image/2P.png"));
	loadimage(&img_1P_desc, TEXT("resources/image/1P_desc.png"));
	loadimage(&img_2P_desc, TEXT("resources/image/2P_desc.png"));
	loadimage(&img_gravestone_right, TEXT("resources/image/gravestone.png"));
	flip_image(&img_gravestone_right, &img_gravestone_left);
	loadimage(&img_selector_tip, TEXT("resources/image/selector_tip.png"));
	loadimage(&img_selector_background, TEXT("resources/image/selector_background.png"));
	loadimage(&img_1P_selector_btn_idle_right, TEXT("resources/image/1P_selector_btn_idle.png"));
	flip_image(&img_1P_selector_btn_idle_right, &img_1P_selector_btn_idle_left);
	loadimage(&img_1P_selector_btn_down_right, TEXT("resources/image/1P_selector_btn_down.png"));
	flip_image(&img_1P_selector_btn_down_right, &img_1P_selector_btn_down_left);
	loadimage(&img_2P_selector_btn_idle_right, TEXT("resources/image/2P_selector_btn_idle.png"));
	flip_image(&img_2P_selector_btn_idle_right, &img_2P_selector_btn_idle_left);
	loadimage(&img_2P_selector_btn_down_right, TEXT("resources/image/2P_selector_btn_down.png"));
	flip_image(&img_2P_selector_btn_down_right, &img_2P_selector_btn_down_left);
	loadimage(&img_peashooter_selector_background_right, TEXT("resources/image/peashooter_selector_background.png"));
	flip_image(&img_peashooter_selector_background_right, &img_peashooter_selector_background_left);
	loadimage(&img_sunflower_selector_background_right, TEXT("resources/image/sunflower_selector_background.png"));
	flip_image(&img_sunflower_selector_background_right, &img_sunflower_selector_background_left);

	loadimage(&img_sky, TEXT("resources/image/sky.png"));
	loadimage(&img_hills, TEXT("resources/image/hills.png"));
	loadimage(&img_platform_large, TEXT("resources/image/platform_large.png"));
	loadimage(&img_platform_small, TEXT("resources/image/platform_small.png"));

	loadimage(&img_1P_cursor, TEXT("resources/image/1P_cursor.png"));
	loadimage(&img_2P_cursor, TEXT("resources/image/2P_cursor.png"));

	atlas_peashooter_idle_right.load_from_file(TEXT("resources/image/peashooter_idle_%d.png"), 9);
	Atlas::flip_atlas(atlas_peashooter_idle_right, atlas_peashooter_idle_left);
	atlas_peashooter_run_right.load_from_file(TEXT("resources/image/peashooter_run_%d.png"), 5);
	Atlas::flip_atlas(atlas_peashooter_run_right, atlas_peashooter_run_left);
	atlas_peashooter_attack_ex_right.load_from_file(TEXT("resources/image/peashooter_attack_ex_%d.png"), 3);
	Atlas::flip_atlas(atlas_peashooter_attack_ex_right, atlas_peashooter_attack_ex_left);
	atlas_peashooter_die_right.load_from_file(TEXT("resources/image/peashooter_die_%d.png"), 4);
	Atlas::flip_atlas(atlas_peashooter_die_right, atlas_peashooter_die_left);

	atlas_sunflower_idle_right.load_from_file(TEXT("resources/image/sunflower_idle_%d.png"), 8);
	Atlas::flip_atlas(atlas_sunflower_idle_right, atlas_sunflower_idle_left);
	atlas_sunflower_run_right.load_from_file(TEXT("resources/image/sunflower_run_%d.png"), 5);
	Atlas::flip_atlas(atlas_sunflower_run_right, atlas_sunflower_run_left);
	atlas_sunflower_attack_ex_right.load_from_file(TEXT("resources/image/sunflower_attack_ex_%d.png"), 9);
	Atlas::flip_atlas(atlas_sunflower_attack_ex_right, atlas_sunflower_attack_ex_left);
	atlas_sunflower_die_right.load_from_file(TEXT("resources/image/sunflower_die_%d.png"), 2);
	Atlas::flip_atlas(atlas_sunflower_die_right, atlas_sunflower_die_left);

	loadimage(&img_pea, TEXT("resources/image/pea.png"));
	atlas_pea_break.load_from_file(TEXT("resources/image/pea_break_%d.png"), 3);
	atlas_sun.load_from_file(TEXT("resources/image/sun_%d.png"), 5);
	atlas_sun_explode.load_from_file(TEXT("resources/image/sun_explode_%d.png"), 5);
	atlas_sun_ex.load_from_file(TEXT("resources/image/sun_ex_%d.png"), 5);
	atlas_sun_ex_explode.load_from_file(TEXT("resources/image/sun_ex_explode_%d.png"), 5);
	atlas_sun_text.load_from_file(TEXT("resources/image/sun_text_%d.png"), 6);

	atlas_run_effect.load_from_file(TEXT("resources/image/run_effect_%d.png"), 4);
	atlas_jump_effect.load_from_file(TEXT("resources/image/jump_effect_%d.png"), 5);
	atlas_land_effect.load_from_file(TEXT("resources/image/land_effect_%d.png"), 2);

	loadimage(&img_1P_winner, TEXT("resources/image/1P_winner.png"));
	loadimage(&img_2P_winner, TEXT("resources/image/2P_winner.png"));
	loadimage(&img_winnner_bar, TEXT("resources/image/winnner_bar.png"));

	loadimage(&img_avatar_peashooter, TEXT("resources/image/avatar_peashooter.png"));
	loadimage(&img_avatar_sunflower, TEXT("resources/image/avatar_sunflower.png"));
}