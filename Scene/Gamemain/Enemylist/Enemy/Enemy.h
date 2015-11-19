#pragma once
#include "../../../../Share.h"

class Enemy{
protected:
	Vec2f pos;
	Vec2f size;
	Direction direction;
	int speed;
	int number;
	Item* heart;
public:
	Enemy();
	void Update();
	void Draw();
	void Move(Direction aster_direction);


	int GetNum();
	Vec2f GetPos();
	Vec2f GetSize();
	int GetSpeed();
	void SetPos(Vec2f set);
};