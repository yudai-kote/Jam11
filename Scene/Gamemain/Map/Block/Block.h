#pragma once
#include "../../../../Share.h"

class Block{
private:

	enum Texturefile{

		ROBOT,
		GAME,
		DESK,
		COMIC,
		TEXTURE_MAX,

	};

	Object block;
	Item category;

	Texture *tex_list[TEXTURE_MAX];

	Item is_desk;



public:

	Block(){
		block.pos = Vec2f(0, 0);
		block.size = Vec2f(50.0f, 50.0f);
		block.offset_pos = Vec2f(0.0f, 0.0f);
		block.offset_size = Vec2f(512.0f, 512.0f);
		block.zoom = Vec2f(1.0f, 1.0f);
		block.center = Vec2f(0.0f, 0.0f);
		block.color = Color(1.0f, 1.0f, 1.0f, 0.3f);
		block.angle = 0;
		category = Item::AIR;
		is_desk = Item::AIR;

		const char* texture_list[TEXTURE_MAX]
		{
			"res/Texture/robot.png",
				"res/Texture/game.png",
				"res/Texture/desk.png",
				"res/Texture/comic.png",
		};
		for (int index = 0; index < TEXTURE_MAX; index++)
		{
			tex_list[index] = new Texture(texture_list[index]);
		}
	};


	char blocktype;

	void Setup();
	void TextureSetup();
	void Draw();
	void Update();

	void SetElement(Vec2i pos, Vec2i size, Item type);
	void SetColor(Color block_color);
	void SetItem(Item item);
	void SetDesk(Item desk);

	Item GetItem();
	Item GetDesk();

};