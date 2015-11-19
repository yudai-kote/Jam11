#pragma once
#include "../Enemy.h"
class Gal : public Enemy{
private:

public:
	Gal(Item item,int count,Vec2f map_pos){
		heart = new Item(item);
		number = count;
		pos = map_pos;
	}
};