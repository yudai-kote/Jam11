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
	void PushEnemy(Vec2f pos,int count,Vec2f v_pos);
	void Draw(int i);
	void Move(int direction, int i);
	Vec2f GetPos(int i);
	int GetSpeed(int i);
	Vec2f GetVPos(int i);
	void SetPos(Vec2f set,int i);

};
