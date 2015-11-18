#pragma once
#include "../Enemy.h"
class Baseclub : Enemy{
private:
	
public:
	Baseclub(Item item){
		heart = new Item(item);
	}
};