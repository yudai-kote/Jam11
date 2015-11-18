#include "Scenemanager.h"

Scenemanager::Scenemanager(){
    Setup();

}

void Scenemanager::Setup(){
	scenechange = Scenename::TITLE;
}


void Scenemanager::Update(){
    //std::cout << scenechange << std::endl;
	
    switch (scenechange)
	{
	case Scenename::TITLE:
        title.Update();

		break;
	case Scenename::STAGESELECT:
        stageselect.Update();

		break;

	case Scenename::GAMEMAIN:
        gamemanager.Update();
		break;
	}
}

void Scenemanager::Draw(){


	switch (scenechange){
	case Scenename::TITLE:
        title.Draw();

		break;
	case Scenename::STAGESELECT:
        stageselect.Draw();

		break;
	case Scenename::GAMEMAIN:
        gamemanager.Draw();
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