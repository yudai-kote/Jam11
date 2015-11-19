#pragma once
#include "../../lib/framework.hpp"
#include "../../Share.h"
#include "../../Classbase.h"
#include "Ui/Ui.h"
#include "Map/Map.h"
#include "Player/Player.h"
#include "Enemylist/Enemylist.h"


class Gamemain : public Classbase{
private:
    Ui ui;
    Player player;
	Map map;
	Enemylist enemylist;
	int count;
	int enemy_number;
public:
	Gamemain();

	void Setup();
	void Update();
	void Draw();
	Scenename Shift();

};