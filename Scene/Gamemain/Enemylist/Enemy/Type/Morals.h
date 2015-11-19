#pragma once
#include "../Enemy.h"
class Morals : public Enemy{
private:

public:
	Morals(Item item, int count, Vec2f map_pos, Vec2f v_pos){
		heart = new Item(item);
		number = count;
		pos = map_pos;
		this->v_pos = v_pos;
		tx = Texture("res/Texture/morals/morals_back.png");
	}
};