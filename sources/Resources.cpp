#include "Resources.h"
#include "Utils.h"
#include "Atlas.h"

#include <memory>


///////////////////////////////////////////////

IMAGE img_menu_background;				// 主菜单背景图片

IMAGE img_VS;							// VS 艺术字图片
IMAGE img_1P;							// 1P 文本图片
IMAGE img_2P;							// 2P 文本图片
IMAGE img_1P_desc;						// 1P 键位描述图片
IMAGE img_2P_desc;						// 2P 键位描述图片
IMAGE img_gravestone_left;				// 朝向左的墓碑图片
IMAGE img_gravestone_right;				// 朝向右的墓碑图片
IMAGE img_selector_tip;					// 选角界面提示信息文本图片
IMAGE img_selector_background;			// 选角界面背景图
IMAGE img_1P_selector_btn_idle_left;	// 1P 向左选择按钮默认状态图片
IMAGE img_1P_selector_btn_idle_right;	// 1P 向右选择按钮默认状态图片
IMAGE img_1P_selector_btn_down_left;	// 1P 向左选择按钮按下状态图片
IMAGE img_1P_selector_btn_down_right;	// 1P 向右选择按钮按下状态图片
IMAGE img_2P_selector_btn_idle_left;	// 2P 向左选择按钮默认状态图片
IMAGE img_2P_selector_btn_idle_right;	// 2P 向右选择按钮默认状态图片
IMAGE img_2P_selector_btn_down_left;	// 2P 向左选择按钮按下状态图片
IMAGE img_2P_selector_btn_down_right;	// 2P 向右选择按钮按下状态图片
IMAGE img_peashooter_selector_background_left;	// 选角界面朝向左的豌豆射手背景图片
IMAGE img_peashooter_selector_background_right;	// 选角界面朝向右的豌豆射手背景图片
IMAGE img_sunflower_selector_background_left;	// 选角界面朝向左的龙日葵背景图片
IMAGE img_sunflower_selector_background_right;	// 选角界面朝向右的龙日葵背景图片

IMAGE img_sky;							// 天空图片
IMAGE img_hills;						// 山脉图片
IMAGE img_platform_large;				// 大型平台图片
IMAGE img_platform_small;				// 小型平台图片

IMAGE img_1P_cursor;					// 1P 指示光标图片
IMAGE img_2P_cursor;					// 2P 指示光标图片

Atlas atlas_peashooter_idle_left;		// 豌豆射手朝向左的默认动画图集
Atlas atlas_peashooter_idle_right;		// 豌豆射手朝向右的默认动画图集
Atlas atlas_peashooter_run_left;		// 豌豆射手朝向左的奔跑动画图集
Atlas atlas_peashooter_run_right;		// 豌豆射手朝向右的奔跑动画图集
Atlas atlas_peashooter_attack_ex_left;	// 豌豆射手朝向左的特殊攻击动画图集
Atlas atlas_peashooter_attack_ex_right;	// 豌豆射手朝向右的特殊攻击动画图集
Atlas atlas_peashooter_die_left;		// 豌豆射手朝向左的死亡动画图集
Atlas atlas_peashooter_die_right;		// 豌豆射手朝向右的死亡动画图集

Atlas atlas_sunflower_idle_left;		// 龙日葵朝向左的默认动画图集
Atlas atlas_sunflower_idle_right;		// 龙日葵朝向右的默认动画图集
Atlas atlas_sunflower_run_left;			// 龙日葵朝向左的奔跑动画图集
Atlas atlas_sunflower_run_right;		// 龙日葵朝向右的奔跑动画图集
Atlas atlas_sunflower_attack_ex_left;	// 龙日葵朝向左的特殊攻击动画图集
Atlas atlas_sunflower_attack_ex_right;	// 龙日葵朝向右的特殊攻击动画图集
Atlas atlas_sunflower_die_left;			// 龙日葵朝向左的死亡动画图集
Atlas atlas_sunflower_die_right;		// 龙日葵朝向右的死亡动画图集

IMAGE img_pea;							// 豌豆图片
Atlas atlas_pea_break;					// 豌豆破碎动画图集
Atlas atlas_sun;						// 日光动画图集
Atlas atlas_sun_explode;				// 日光爆炸动画图集
Atlas atlas_sun_ex;						// 日光特效动画图集
Atlas atlas_sun_ex_explode;				// 日光特效爆炸动画图集
Atlas atlas_sun_text;					// “日”文本动画图集

Atlas atlas_run_effect;					// 奔跑特效动画图集
Atlas atlas_jump_effect;				// 跳跃特效动画图集
Atlas atlas_land_effect;				// 着陆特效动画图集

IMAGE img_1P_winner;					// 1P 胜利文本图片
IMAGE img_2P_winner;					// 2P 胜利文本图片
IMAGE img_winnner_bar;					// 胜利玩家文本背景图片

IMAGE img_avatar_peashooter;			// 豌豆射手头像图片
IMAGE img_avatar_sunflower;				// 龙日葵头像图片


///////////////////////////////////////////////


// 加载游戏资源
void load_game_resources()
{
	// 加载所有游戏资源

	// 加载字体
	AddFontResourceEx(TEXT("resources/font/IPix.ttf"), FR_PRIVATE, NULL);


	// 加载音乐
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


	// 加载图片，图集
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