#pragma once
#include "../../lib/framework.hpp"
#include "../../Share.h"
#include "../../Classbase.h"
#include "Ui/Ui.h"
#include "Map/Map.h"


class Gamemain : public Classbase{
private:
    Ui ui;



public:
	Gamemain();

	void Setup();
	void Update();
	void Draw();
	Scenename Shift();

};