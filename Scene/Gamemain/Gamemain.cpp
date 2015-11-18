#include "Gamemain.h"

Gamemain::Gamemain(){



}


void Gamemain::Setup(){
	map.Setup();
}

void Gamemain::Update(){

	map.Update();
}

void Gamemain::Draw(){
    ui.Draw();
    ui.Cost(player.GetCost());

	map.Draw();
}


Scenename Gamemain::Shift(){
	if (env.isPushKey(GLFW_KEY_ENTER)){
		return Scenename::STAGESELECT;
	}
    return Scenename::GAMEMAIN;
}