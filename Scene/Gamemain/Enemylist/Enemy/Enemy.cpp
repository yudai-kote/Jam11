#include "Enemy.h"

Enemy::Enemy(){
	size = Vec2f(100, 100);
	direction = Direction::NONE;
	speed = 2;
}

void Enemy::Move(Direction astar_direction){
	
	switch (astar_direction)
	{
	case Direction::UP:
		pos.y() -= speed;
		break;
	case Direction::DOWN:
		pos.y() += speed;
		break;
	case Direction::RIGHT:
		pos.x()+= speed;
		break;
	case Direction::LEFT:
		pos.x()-= speed;
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

int Enemy::GetSpeed(){
	return speed;
}

void Enemy::SetPos(Vec2f set){
	if (set != null){
		pos = set;
	}
}