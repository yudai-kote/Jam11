#include "Title.h"

Title::Title(){



}


void Title::Setup(){




}

void Title::Update(){



}

void Title::Draw(){

    drawBox(100, 100, 100, 100, 100, Color::blue);

}


Scenename Title::Shift(){

	if (env.isPushKey(GLFW_KEY_ENTER))
		return Scenename::GAMEMAIN;
    return Scenename::TITLE;
}