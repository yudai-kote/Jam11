#pragma once
#include "../../lib/framework.hpp"
#include "../../Share.h"
#include "../../Classbase.h"

class Gamemain : public Classbase{
private:


public:
	Gamemain();

	void Setup();
	void Update();
	void Draw();
	Scenename Shift();

};