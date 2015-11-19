#include "Enemy.h"

Enemy::Enemy(){
	size = Vec2f(120, 120);
	direction = Direction::UP;
	speed = 2;
	animation_count = 0;
	cut_x = 0;
}
void Enemy::Animation(){
	animation_count++;
}
void Enemy::Move(int astar_direction){
	switch (astar_direction)
	{
	case static_cast<int>(Direction::UP):
		pos.y() += speed;
		direction = Direction::UP;
		break;
	case static_cast<int>(Direction::DOWN) :
		pos.y() += speed;
		direction = Direction::DOWN;
		break;
	case static_cast<int>(Direction::RIGHT) :
		pos.x()+= speed;
		direction = Direction::RIGHT;
		break;
	case static_cast<int>(Direction::LEFT) :
		pos.x()-= speed;
		direction = Direction::LEFT;
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

Vec2f Enemy::GetVPos(){
	return v_pos;
}

int Enemy::GetSpeed(){
	return speed;
}

Texture Enemy::GetTx(){
	return tx;
}

int Enemy::GetAniCount(){
	return animation_count;
}
Direction Enemy::GetDir(){
	return direction;
}

void Enemy::SetPos(Vec2f set){
	if (set != null){
		pos = set;
	}
}
void Enemy::SetDirection(int dir){
	this->direction = static_cast<Direction>(dir);
}