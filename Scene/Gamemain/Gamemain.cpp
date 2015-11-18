#include "Gamemain.h"

Gamemain::Gamemain(){

    Setup();
    

}


void Gamemain::Setup(){
	map.Setup();
    player.SetPos(map.GetPlayerPos());
    enemylist.SetPos(map.GetEnemyPos(),1);
    
}

void Gamemain::Update(){

	map.Update();
    player.SetSelectItem(ui.Select(player.GetSelectItem()));
    map.Editor(player.GetSelectItem(), player.MouseClick());
    player.Update();
}

void Gamemain::Draw(){

    ui.Draw();
    ui.Cost(player.GetCost());
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