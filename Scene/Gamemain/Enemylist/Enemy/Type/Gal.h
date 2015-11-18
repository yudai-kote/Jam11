#pragma once
#include "../Enemy.h"
class Gal : public Enemy{
private:

public:
	Gal(Item item,int count){
		heart = new Item(item);
		number = count;
	}
};