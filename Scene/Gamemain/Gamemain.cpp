#include "Gamemain.h"

Gamemain::Gamemain(){

	
    Setup();
}


void Gamemain::Setup(){
	map.Setup();
    player.SetPos(map.GetPlayerPos());
	count = 0;
	enemy_number = 0;
    Astar::get().setMap(map.GetStatus());
	Astar::get().setup(map.GetEnemyChip(), map.GetPlayerChip());
    ui.Setup();
}

void Gamemain::Update(){
	int index;
	count++;
	index = (count) % 100;
	if (index == 1){
		enemy_number++;
		if (enemy_number <= 5){
			enemylist.PushEnemy(map.GetEnemyPos(), enemy_number, Vec2f(0, 7));
		}
	}
	for (int i = 0; i < enemy_number; i++){
		enemylist.Move(Astar::get().getParentPlayer(), i);
		Astar::get().setEnemyPos(map.ChangeChip(enemylist.GetPos(i),enemylist.GetSize(i)));
		Astar::get().setPlayerPos(map.GetPlayerChip());
		Astar::get().update();
	}
	map.Update();
    player.SetSelectItem(ui.Select(player.GetSelectItem()));
    map.Editor(player.GetSelectItem(), player.MouseClick());
    player.Update();
}

void Gamemain::Draw(){
    ui.Draw();
    ui.Cost(map.GetCost());
    ui.SelectDraw(player.GetSelectItem());
	map.Draw();
    player.Draw();
	enemylist.Draw();
}


Scenename Gamemain::Shift(){
	if (env.isPushKey(GLFW_KEY_ENTER)){
		return Scenename::STAGESELECT;
	}
    return Scenename::GAMEMAIN;
}

