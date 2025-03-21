#pragma once

#include "Bullet.h"
#include "Animation.h"


// �������ӵ���
class PeaBullet : public Bullet
{
public:
	PeaBullet();

	void on_collide() override;
	void on_update(int delta) override;
	void on_draw(const Camera& camera) override;


private:
	Animation m_animation_break;		// �ӵ����鶯��

};

