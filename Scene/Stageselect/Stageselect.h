#pragma once
#include "../../lib/framework.hpp"
#include "../../Share.h"
#include "../../Classbase.h"


class Stageselect : public Classbase{
private:
    int count;
    bool is_ok;
public:
	Stageselect();

	void Setup();
	void Update();
	void Draw();
	Scenename Shift();

};