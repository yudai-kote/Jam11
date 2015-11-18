#pragma once
#include "../../../Share.h"
#include "Block/Block.h"


class Map {
private:
	enum Mapfile{
		STAGE1,

		FILE_MAX,
	};

	enum Mapchipsize{
		LENGTH = 8,
		WIDE = 8,
	};

	enum  Blocktype {
		AIR_BLOCK = '0',
		DESK = '1',

	};
	struct Element{
		Vec2i pos;
		Vec2i size;
	};

	std::vector<std::vector<Block>> block;
	std::ifstream* file_list[FILE_MAX];

	std::vector<std::vector<Element>> block_element;

	Texture floor;

public:

	Map();

	void Setup();
	void TextureSetup();
	void Draw();
	void Update();



};