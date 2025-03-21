#pragma once

#include "Bullet.h"
#include "Animation.h"
#include "Camera.h"
#include "Vector2.h"


// 巨大日光炸弹子弹类
class SunBulletEx : public Bullet
{
public:
	SunBulletEx();


	void on_collide() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;
	
	bool check_collide(const Vector2& pos, const Vector2& size) const override;

private:
	Animation m_animation_idle;			// 巨大日光炸弹默认动画
	Animation m_animation_explode;		// 巨大日光炸弹爆炸动画
	Vector2 m_explode_render_offset;	// 爆炸动画渲染偏移

};

