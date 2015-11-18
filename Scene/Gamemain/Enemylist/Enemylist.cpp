#include "Enemylist.h"

Enemylist::Enemylist(){
	stage[0] = { Item::ROBOT };
	stage[1] = { Item::COMIC };
	stage[2] = { Item::COMIC };
	stage[3] = { Item::COMIC };
	stage[4] = { Item::ROBOT };

}

void Enemylist::PushEnemy(){
	int count = 0;
	for (int i = 0; i < 5; i++){
		count++;
		l_enemy.push_back(new Gal(stage[i], count));
		
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
        //drawFillBox((*itr)->GetPos.x(), (*itr)->GetPos.x())
	}
	
}