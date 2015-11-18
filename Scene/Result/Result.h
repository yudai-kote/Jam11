#pragma once
#include "../../lib/framework.hpp"
#include "../../Share.h"
#include "../../Classbase.h"


class Result : public Classbase{
private:


public:
	Result();

	void Setup();
	void Update();
	void Draw();
	Scenename Shift();

};