#include "Gamemain.h"

Gamemain::Gamemain(){



}


void Gamemain::Setup(){
	map.Setup();
	count = 0;
	enemy_number = 0;
}

void Gamemain::Update(){
	int index;
	count++;
	index = (count) % 8;
	if (index == 1){
		enemy_number++;
		if (enemy_number <= 5){
			enemylist.PushEnemy(map.GetEnemyPos(),enemy_number);
		}
	}
	map.Update();
    player.SetSelectItem(ui.Select(player.GetSelectItem()));
    map.Editor(player.GetSelectItem(), player.MouseClick());
	
}

void Gamemain::Draw(){
    ui.Draw();
    ui.Cost(player.GetCost());
    ui.SelectDraw(player.GetSelectItem());
	map.Draw();
	enemylist.Draw();
}


Scenename Gamemain::Shift(){
	if (env.isPushKey(GLFW_KEY_ENTER)){
		return Scenename::STAGESELECT;
	}
    return Scenename::GAMEMAIN;
}