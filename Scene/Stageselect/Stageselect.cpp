#include "Stageselect.h"

Stageselect::Stageselect(){



}


void Stageselect::Setup(){

}

void Stageselect::Update(){

}

void Stageselect::Draw(){

}


Scenename Stageselect::Shift(){
	if (env.isPushKey(GLFW_KEY_ENTER)){
		return Scenename::GAMEMAIN;
	}
    return Scenename::STAGESELECT;
}