#pragma once
#include "../../../../Share.h"

class Block{
private:

	Object block;
	char category;

public:

	

	Block(){
		block.pos = Vec2f(0, 0);
		block.size = Vec2f(50.0f, 50.0f);
		block.zoom = Vec2f(1.0f, 1.0f);
		block.center = Vec2f(0.0f, 0.0f);
		block.color = Color::white;
		block.angle = 0;

	};


	char blocktype;

	void Setup();
	void TextureSetup();
	void Draw();
	void Update();

	void GetElement(Vec2i pos, Vec2i size, char type);


};