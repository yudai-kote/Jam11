#include "Enemy.h"

Enemy::Enemy(){
	size = Vec2f(100, 100);
	direction = Direction::NONE;
	speed = 2;
	animation_count = 0;
}
void Enemy::Animation(){
	animation_count++;
	int index = (animation_count) % 40;
	float x = (index) % 8 * 512.0f;

}
void Enemy::Move(int astar_direction){
	switch (astar_direction)
	{
	case static_cast<int>(Direction::UP):
		pos.y() += speed;
		break;
	case static_cast<int>(Direction::DOWN) :
		pos.y() += speed;
		break;
	case static_cast<int>(Direction::RIGHT) :
		pos.x()+= speed;
		break;
	case static_cast<int>(Direction::LEFT) :
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