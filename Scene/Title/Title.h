#pragma once
#include "../../lib/framework.hpp"
#include "../../Share.h"
#include "../../Classbase.h"


class Title : public Classbase{

private:
    int count;


public:

	Title();

	void Setup();
	void Update();
	void Draw();
	Scenename Shift();



};