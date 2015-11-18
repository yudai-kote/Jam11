#include "Scenemanager.h"

Scenemanager::Scenemanager(){


}

void Scenemanager::Setup(){
	scenechange = Scenename::TITLE;
}


void Scenemanager::Update(){

	switch (scenechange)
	{
	case Scenename::TITLE:


		break;
	case Scenename::STAGESELECT:


		break;

	case Scenename::GAMEMAIN:

		break;
	}
}

void Scenemanager::Draw(){


	switch (scenechange){
	case Scenename::TITLE:


		break;
	case Scenename::STAGESELECT:


		break;
	case Scenename::GAMEMAIN:

		break;
	}
}


void Scenemanager::Shift(){

	switch (scenechange){
	case Scenename::TITLE:
		scenechange = title.Shift();

		break;
	case Scenename::STAGESELECT:

		scenechange = stageselect.Shift();
		break;

	case Scenename::GAMEMAIN:
		scenechange = gamemanager.Shift();

		break;
	}
}