#pragma once
#include "../Enemy.h"
class Baseclub : public Enemy{
private:
	
public:
	Baseclub(Item item, int count, Vec2f map_pos, Vec2f v_pos){
		heart = new Item(item);
		number = count;
		pos = map_pos;
		this->v_pos = v_pos;
		tx = Texture("res/Texture/morals/morals_back.png");
		
	}
};