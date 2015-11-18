#include "Gamemain.h"

Gamemain::Gamemain(){



}


void Gamemain::Setup(){
	map.Setup();
}

void Gamemain::Update(){

	map.Update();
    player.SetSelectItem(ui.Select(player.GetSelectItem()));
    map.Editor(player.GetSelectItem(), player.MouseClick());
}

void Gamemain::Draw(){
    ui.Draw();
    ui.Cost(player.GetCost());
    ui.SelectDraw(player.GetSelectItem());
	map.Draw();
}


Scenename Gamemain::Shift(){
	if (env.isPushKey(GLFW_KEY_ENTER)){
		return Scenename::STAGESELECT;
	}
    return Scenename::GAMEMAIN;
}