#include "Map.h"

Map::Map(){

	block = std::vector<std::vector<Block>>(LENGTH, std::vector<Block>(WIDE));
	one_or_zero = std::vector<std::vector<int>>(LENGTH, std::vector<int>(WIDE));
	block_element = std::vector<std::vector<Element>>(LENGTH, std::vector<Element>(WIDE));

	const char* file_name[FILE_MAX]
	{
		"res/Map_file/stage1.txt",
	};
	for (int index = 0; index < FILE_MAX; index++)
	{
		file_list[index] = std::ifstream(file_name[index]);
	}

	for (int y = 0; y < block.size(); y++)
	{
		for (int x = 0; x < block[y].size(); x++)
		{
			file_list[STAGE1] >> block[y][x].blocktype;
			block_element[y][x].size = Vec2i(WIDTH * 3 / 4 / block.size(), HEIGHT / block.size());
			block_element[y][x].pos.x() = -WIDTH / 2 + (WIDTH * 3 / 4 / block.size())*x;
			block_element[y][x].pos.y() = HEIGHT / 2 - (HEIGHT / block.size())*y - HEIGHT / block.size();
			block[y][x].SetElement(block_element[y][x].pos, block_element[y][x].size, Item::AIR);
		}
	}

	const char* texture_list[TEXTURE_MAX]
	{
		"res/Texture/stage_classroom.png",
			"res/Texture/desk.png",
	};
	for (int index = 0; index < TEXTURE_MAX; index++)
	{
		tex_list[index] = new Texture(texture_list[index]);
	}

}


void Map::Setup(){


}

void Map::TextureSetup(){

}

void Map::Update(){
	ChangeBlock();

}

void Map::Draw(){

	drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
				   WIDTH * 3 / 4, HEIGHT,
				   0, 0,
				   1024, 1024,
				   *tex_list[FLOOR], Color::white);
	//std::ifstream a = std::ifstream("res/Map_file/stage1.txt");
	
	for (int y = 0; y < block.size(); y++)
	{
		for (int x = 0; x < block[y].size(); x++)
		{
			file_list[STAGE1] >> block[y][x].blocktype;
			//a >> block[y][x].blocktype;
			block[y][x].Draw();
			//block[0][0].blocktype = 1;
			if (block[y][x].blocktype == DESK_BLOCK)
			{
				drawTextureBox(block_element[y][x].pos.x(), block_element[y][x].pos.y(),
							   block_element[y][x].size.x(), block_element[y][x].size.y(),
							   0, 0,
							   512, 512,
							   *tex_list[TEX_DESK],
							   Color::red);
			}
		}
	}

}

void Map::Editor(Item item, bool is_put){


	for (int y = 0; y < block.size(); y++)
	{
		for (int x = 0; x < block[y].size(); x++)
		{
			block[y][x].SetColor(Color(1, 1, 1, 0.3));
			if (pointCollision(env.mousePosition(), block_element[y][x].pos, block_element[y][x].size) == true)
			{
				block[y][x].SetColor(Color(0.0f, 1.0f, 1.0f, 0.3));
				if (is_put == true)
				{
					if (env.isPushButton(Mouse::LEFT))
					{
						if (block[y][x].blocktype != PLAYER_START_POS&&
							block[y][x].blocktype != ENEMY_START_POS&&
							block[y][x].blocktype != DESK_BLOCK)
						{
							if (block[y][x].GetItem() == Item::AIR && item == Item::DESK)
							{
								block[y][x].SetDesk(item);
							}
							if (block[y][x].GetDesk() == Item::DESK && item != Item::DESK)
							{
								block[y][x].SetItem(item);
							}
							if (block[y][x].GetDesk() == Item::DESK && item == Item::AIR)
							{
								block[y][x].SetItem(item);
								block[y][x].SetDesk(item);
							}
						}
					}
				}

			}
		}

	}
}

//“_‚ÆŽlŠp‚Ì“–‚è”»’è
bool Map::pointCollision(Vec2f point_pos, Vec2i box_pos, Vec2i box_size){
	drawPoint(point_pos.x(), point_pos.y(), 10, Color::yellow);

	return (point_pos.x() > box_pos.x() &&
			point_pos.x() < box_pos.x() + box_size.x() &&
			point_pos.y() > box_pos.y() &&
			point_pos.y() < box_pos.y() + box_size.y());
}



void Map::ChangeBlock(){

	for (int y = 0; y < block.size(); y++)
	{
		for (int x = 0; x < block[y].size(); x++)
		{
			file_list[STAGE1] >> block[y][x].blocktype;

			if (block[y][x].blocktype == DESK_BLOCK)
			{
				one_or_zero[y][x] = 1;
			}
			if (block[y][x].blocktype == PLAYER_START_POS)
			{
				one_or_zero[y][x] = 0;
			}
			if (block[y][x].blocktype == ENEMY_START_POS)
			{
				one_or_zero[y][x] = 0;
			}
			if (block[y][x].GetDesk() == Item::DESK)
			{
				one_or_zero[y][x] = 1;
			}

		}
	}

}

Vec2f Map::GetPlayerPos(){
	for (int y = 0; y < block.size(); y++)
	{
		for (int x = 0; x < block[y].size(); x++)
		{
			if (block[y][x].blocktype == PLAYER_START_POS)
			{
				return Vec2f((float)block_element[y][x].pos.x(),
							 (float)block_element[y][x].pos.y());
			}
		}
	}
}

Vec2f Map::GetEnemyPos(){
	for (int y = 0; y < block.size(); y++)
	{
		for (int x = 0; x < block[y].size(); x++)
		{
			if (block[y][x].blocktype == ENEMY_START_POS)
			{
				return Vec2f((float)block_element[y][x].pos.x(),
							 (float)block_element[y][x].pos.y());
			}
		}
	}
}
