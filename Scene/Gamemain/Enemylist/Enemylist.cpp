#include "Enemylist.h"

Enemylist::Enemylist(){
	stage[0] = { Item::ROBOT };
	stage[1] = { Item::COMIC };
	stage[2] = { Item::COMIC };
	stage[3] = { Item::COMIC };
	stage[4] = { Item::ROBOT };
	
}



void Enemylist::PushEnemy(Vec2f pos, int count,Vec2f v_pos){
	switch (Rand_::get()(0, 2)){
	case 0:
		l_enemy.push_back(new Gal(stage[count], count, pos, v_pos));
		break;
	case 1:
		l_enemy.push_back(new Morals(stage[count], count, pos, v_pos));
		break;
	case 2:
		l_enemy.push_back(new Baseclub(stage[count], count, pos, v_pos));
		break;
	}
}

void Enemylist::Move(int direction, int i){
	for (auto itr = l_enemy.begin(); itr != l_enemy.end(); ++itr)
	{
		if (i == (*itr)->GetNum()){
			(*itr)->Move(direction);
			(*itr)->Animation();
		}
		
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

void Enemylist::Draw(int i){
	for (auto itr = l_enemy.begin(); itr != l_enemy.end(); ++itr)
	{
		if (i == (*itr)->GetNum()){
			drawTextureBox((*itr)->GetPos().x(), (*itr)->GetPos().y(), (*itr)->GetSize().x(),
				(*itr)->GetSize().y(), (*itr)->GetAniCount() / 12 % 4 * 512, 0, 512, 512, (*itr)->GetTx(), Color::white);
			
			
		}
	}
	
}