#pragma once
#include "../../../Share.h"
#include "Block/Block.h"


class Map {
private:
	enum Mapfile{
		STAGE1,

		FILE_MAX,
	};

	enum Texturefile{
		FLOOR,
		TEXTURE_MAX,
	};

	enum Mapchipsize{
		LENGTH = 8,
		WIDE = 8,
	};

	struct Element{
		Vec2i pos;
		Vec2i size;
	};

	std::vector<std::vector<Block>> block;
	std::ifstream* file_list[FILE_MAX];

	std::vector<std::vector<Element>> block_element;

	Texture *tex_list[TEXTURE_MAX];

	


	bool pointCollision(Vec2f point_pos, Vec2i box_pos, Vec2i box_size);
public:

	Map();

	void Setup();
	void TextureSetup();
	void Draw();
	void Update();

	void Editor(Item item, bool is_put = true);


};