#pragma once
#include "../lib/framework.hpp"
#include "../Share.h"
#include "Title/Title.h"
#include "Stageselect/Stageselect.h"
#include "Gamemain/Gamemain.h"
#include "../Classbase.h"

class Scenemanager : public Classbase{
private:

	Title title;
	Gamemain gamemanager;
	Stageselect stageselect;
	Scenename scenechange;

	
public:
	Scenemanager();

	void Setup();
	void Update();
	void Draw();
	void Shift();

};