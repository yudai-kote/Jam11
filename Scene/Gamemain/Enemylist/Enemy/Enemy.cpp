#include "Enemy.h"

Enemy::Enemy(){
	size = Vec2f(100, 100);
	direction = Direction::NONE;
}

void Enemy::Move(Direction astar_direction){
	float speed = 10;
	switch (astar_direction)
	{
	case Direction::UP:
		pos.y()++;
		break;
	case Direction::DOWN:
		pos.y()--;
		break;
	case Direction::RIGHT:
		pos.x()++;
		break;
	case Direction::LEFT:
		pos.x()--;
		break;
	}
}

int Enemy::GetNum(){
	return number;
}

Vec2f Enemy::GetPos(){
	return pos;
}

Vec2f Enemy::GetSize(){
	return size;
}

void Enemy::SetPos(Vec2f set){
	pos = set;
}