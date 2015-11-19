#include "Enemylist.h"

Enemylist::Enemylist(){
	stage[0] = { Item::ROBOT };
	stage[1] = { Item::COMIC };
	stage[2] = { Item::COMIC };
	stage[3] = { Item::COMIC };
	stage[4] = { Item::ROBOT };

}



void Enemylist::PushEnemy(Vec2f pos, int count,Vec2f v_pos){

		l_enemy.push_back(new Gal(stage[count], count,pos,v_pos));
		
	
}

void Enemylist::Move(int direction, int i){
	for (auto itr = l_enemy.begin(); itr != l_enemy.end(); ++itr)
	{
		if (i == (*itr)->GetNum()){
			(*itr)->Move(direction);
		}
		(*itr)->Animation();
	}
}

 Vec2f Enemylist::GetPos(int i){
	for (auto itr = l_enemy.begin(); itr != l_enemy.end(); ++itr)
	{
		if (i == (*itr)->GetNum()){
			return (*itr)->GetPos();
		}
	}
}

int Enemylist::GetSpeed(int i){
	 for (auto itr = l_enemy.begin(); itr != l_enemy.end(); ++itr)
	 {
		 if (i == (*itr)->GetNum()){
			 return (*itr)->GetSpeed();
		 }
	 }
 }

Vec2f Enemylist::GetVPos(int i){
	for (auto itr = l_enemy.begin(); itr != l_enemy.end(); ++itr)
	{
		if (i == (*itr)->GetNum()){
			return (*itr)->GetVPos();
		}
	}
}

void Enemylist::SetPos(Vec2f set, int i){
	for (auto itr = l_enemy.begin(); itr != l_enemy.end(); ++itr)
	{
		if (i == (*itr)->GetNum()){
			(*itr)->SetPos(set);
		}
	}
}

void Enemylist::Draw(){
	for (auto itr = l_enemy.begin(); itr != l_enemy.end(); ++itr)
	{
		drawFillBox((*itr)->GetPos().x(), (*itr)->GetPos().y(), (*itr)->GetSize().x(),
			(*itr)->GetSize().y(), Color::white);
	}
	
}