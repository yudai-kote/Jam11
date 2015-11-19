#pragma once
#include "../../../../Share.h"

class Enemy{
protected:
	Vec2f pos;
	Vec2f v_pos;
	Vec2f size;
	Direction direction;
	int animation_count;
	float cut_x;
	int speed;
	int number;
	Item* heart;
	Texture tx;
public:
	Enemy();
	void Update();
	void Draw();
	void Move(int aster_direction);
	void Animation();

	int GetNum();
	Vec2f GetPos();
	Vec2f GetSize();
	Vec2f GetVPos();
	int GetSpeed();
	Direction GetDir();
	Texture GetTx();
	int GetAniCount();
	void SetPos(Vec2f set);
	void SetDirection(int dir);
};