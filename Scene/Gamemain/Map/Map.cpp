#include "Map.h"

Map::Map(){
	block = std::vector<std::vector<Block>>(LENGTH, std::vector<Block>(WIDE));
	block_element = std::vector<std::vector<Element>>(LENGTH, std::vector<Element>(WIDE));

	const char* file_name[FILE_MAX]{
		"res/Map_file/stage1.txt"
	};
	for (int index = 0; index < FILE_MAX; index++){
		file_list[index] = new std::ifstream(file_name[index]);
	}



	for (int y = 0; y < block.size(); y++){
		for (int x = 0; x < block[y].size(); x++){


			block_element[y][x].size = Vec2i(WIDTH * 3 / 4 / block.size(), HEIGHT / block.size());
			block_element[y][x].pos.x() = -WIDTH / 2 + (WIDTH * 3 / 4 / block.size())*x;
			block_element[y][x].pos.y() = -HEIGHT / 2 + (HEIGHT / block.size())*y;
			block[y][x].GetElement(block_element[y][x].pos, block_element[y][x].size, '0');

		}
	}

	floor = Texture("res/Texture/stage_classroom.png");
}


void Map::Setup(){


}

void Map::TextureSetup(){
	//floor = Texture("res/Texture/stage_classroom.png");
}

void Map::Update(){


}

void Map::Draw(){

	drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
				   WIDTH * 3 / 4, HEIGHT,
				   0, 0,
				   1024, 1024,
				   floor, Color::white);
	for (int y = 0; y < block.size(); y++){
		for (int x = 0; x < block[y].size(); x++){
			*file_list[STAGE1] >> block[y][x].blocktype;
			block[y][x].Draw();
		}
	}
}

