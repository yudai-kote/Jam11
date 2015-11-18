#pragma once
#include "../../../Share.h"
#include "Enemy/Enemy.h"
#include "Enemy\Type\Baseclub.h"
#include "Enemy\Type\Gal.h"
#include "Enemy\Type\Morals.h"
class Enemylist{
private:

	std::list<Enemy*> l_enemy;
	Item stage[5];
public:
	Enemylist();
	void PushEnemy();
	void Draw();
	void Move(Direction direction, int i);
	Vec2f GetPos(int i);
	void SetPos(Vec2f set,int i);
};
