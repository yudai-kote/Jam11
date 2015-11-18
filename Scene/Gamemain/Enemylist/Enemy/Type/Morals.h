#pragma once
#include "../Enemy.h"
class Morals : Enemy{
private:

public:
	Morals(Item item){
		heart = new Item(item);
	}
};