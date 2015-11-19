#include "Map.h"

Map::Map(){

	block = std::vector<std::vector<Block>>(static_cast<int>(Block_size::LENGTH), std::vector<Block>(static_cast<int>(Block_size::WIDE)));
	one_or_zero = std::vector<std::vector<int>>(static_cast<int>(Block_size::LENGTH), std::vector<int>(static_cast<int>(Block_size::WIDE)));
	block_element = std::vector<std::vector<Element>>(static_cast<int>(Block_size::LENGTH), std::vector<Element>(static_cast<int>(Block_size::WIDE)));

	const char* file_name[FILE_MAX]
	{
		"res/Map_file/stage1.txt",
	};
	for (int index = 0; index < FILE_MAX; index++)
	{
		file_list[index] = std::ifstream(file_name[index]);
	}

	for (unsigned y = 0; y < block.size(); y++)
	{
		for (unsigned x = 0; x < block[y].size(); x++)
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

	for (unsigned y = 0; y < block.size(); y++)
	{
		for (unsigned x = 0; x < block[y].size(); x++)
		{
			file_list[STAGE1] >> block[y][x].blocktype;

			block[y][x].Draw();
			if (pointCollision(env.mousePosition(), block_element[y][x].pos, block_element[y][x].size) == true)
			{
				if (is_fillbox == true){
					drawFillBox(block_element[y][x].pos.x(), block_element[y][x].pos.y(),
								block_element[y][x].size.x(), block_element[y][x].size.y(),
								Color(0.0f, 1.0f, 1.0f, 0.3f));
				}
			}
		}
	}

}

void Map::Editor(Item item, bool is_put){


	for (unsigned y = 0; y < block.size(); y++)
	{
		for (unsigned x = 0; x < block[y].size(); x++)
		{
			block[y][x].SetColor(Color(1.0f, 1.0f, 1.0f, 0.3f));
			if (pointCollision(env.mousePosition(), block_element[y][x].pos, block_element[y][x].size) == true)
			{
				block[y][x].SetColor(Color(0.0f, 1.0f, 1.0f, 0.3f));
				if (is_put == true)
				{
					if (env.isPushButton(Mouse::LEFT))
					{
						if (block[y][x].blocktype != PLAYER_START_POS&&
							block[y][x].blocktype != ENEMY_START_POS)
						{

							if (block[y][x].GetDesk() == Item::DESK &&
								block[y][x].GetItem() != Item::AIR &&
								item > Item::DESK)
							{
								if (item >= Item::ROBOT_EX &&
									block[y][x].GetItem() < Item::ROBOT_EX)
								{
									cost += item_cost - item_cost_ex;
								}
								if (item < Item::ROBOT_EX &&
									block[y][x].GetItem() >= Item::ROBOT_EX)
								{
									cost += item_cost_ex - item_cost;
								}
								block[y][x].SetItem(item);
							}
							if (block[y][x].blocktype == DESK_BLOCK &&
								block[y][x].GetItem() != Item::AIR&&
								block[y][x].GetDesk() != Item::DESK&&
								item > Item::DESK)
							{
								if (item >= Item::ROBOT_EX &&
									block[y][x].GetItem() < Item::ROBOT_EX)
								{
									cost += item_cost - item_cost_ex;
								}
								if (item < Item::ROBOT_EX &&
									block[y][x].GetItem() >= Item::ROBOT_EX)
								{
									cost += item_cost_ex - item_cost;
								}
								block[y][x].SetItem(item);
							}
							if (block[y][x].GetDesk() == Item::DESK&&
								block[y][x].GetItem() == Item::AIR)
							{
								if (item >= Item::ROBOT_EX)
								{
									if (cost >= item_cost_ex){
										block[y][x].SetItem(item);
										cost -= item_cost_ex;
									}
								}
								else if (item > Item::DESK)
								{
									if (cost >= item_cost){
										block[y][x].SetItem(item);
										cost -= item_cost;
									}
								}
							}
							if (block[y][x].blocktype == DESK_BLOCK&&
								block[y][x].GetItem() == Item::AIR)
							{
								if (item >= Item::ROBOT_EX)
								{
									if (cost >= item_cost_ex){
										block[y][x].SetItem(item);
										cost -= item_cost_ex;
									}
								}
								else if (item > Item::DESK)
								{
									if (cost >= item_cost){
										block[y][x].SetItem(item);
										cost -= item_cost;
									}
								}
							}
							if (block[y][x].GetItem() == Item::AIR &&
								block[y][x].GetDesk() == Item::AIR&&
								block[y][x].blocktype != DESK_BLOCK&&
								item == Item::DESK)
							{
								if (cost >= desk_cost)
								{
									block[y][x].SetDesk(item);
									cost -= desk_cost;
								}
							}
							if (block[y][x].GetDesk() == Item::DESK && item == Item::AIR)
							{
								cost += desk_cost;
								if (block[y][x].GetItem() >= Item::ROBOT_EX)
								{
									cost += item_cost_ex;
								}
								else if (block[y][x].GetItem() > Item::DESK)
								{
									cost += item_cost;
								}
								block[y][x].SetItem(item);
								block[y][x].SetDesk(item);


							}
							if (block[y][x].blocktype == DESK_BLOCK && item == Item::AIR)
							{
								if (block[y][x].GetItem() >= Item::ROBOT_EX)
								{
									cost += item_cost_ex;
								}
								else if (block[y][x].GetItem() > Item::DESK)
								{
									cost += item_cost;
								}
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

	for (unsigned y = 0; y < block.size(); y++)
	{
		for (unsigned x = 0; x < block[y].size(); x++)
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
	for (unsigned y = 0; y < block.size(); y++)
	{
		for (unsigned x = 0; x < block[y].size(); x++)
		{
			if (block[y][x].blocktype == PLAYER_START_POS)
			{
				return Vec2f((float)block_element[y][x].pos.x(),
							 (float)block_element[y][x].pos.y());
			}
		}
	}
	return Vec2f(0.0f, 0.0f);
}

Vec2f Map::GetEnemyPos(){
	for (unsigned y = 0; y < block.size(); y++)
	{
		for (unsigned x = 0; x < block[y].size(); x++)
		{
			if (block[y][x].blocktype == ENEMY_START_POS)
			{
				return Vec2f((float)block_element[y][x].pos.x(),
							 (float)block_element[y][x].pos.y());
			}
		}
	}
	return Vec2f(0.0f, 0.0f);
}

Vec2f Map::GetPlayerChip(){
	for (unsigned y = 0; y < block.size(); y++)
	{
		for (unsigned x = 0; x < block[y].size(); x++)
		{
			if (block[y][x].blocktype == PLAYER_START_POS)
			{
				return Vec2f(x, y);
			}
		}
	}
	return Vec2f(0.0f, 0.0f);

}
Vec2f Map::GetEnemyChip(){
	for (unsigned y = 0; y < block.size(); y++)
	{
		for (unsigned x = 0; x < block[y].size(); x++)
		{
			if (block[y][x].blocktype == ENEMY_START_POS)
			{
				//std::cout << Vec2f(x, y) << std::endl;
				return Vec2f(x, y);
			}
		}
	}
	return Vec2f(0.0f, 0.0f);
}


int Map::GetCost(){
	return cost;
}

std::vector<std::vector<int>> Map::GetStatus(){
	return one_or_zero;
}

void Map::SetIsFillBox(bool is_box){
	is_fillbox = is_box;
}


Vec2f Map::ChangeChip(Vec2f pos){
	for (unsigned y = 0; y < block.size(); y++)
	{
		for (unsigned x = 0; x < block[y].size(); x++)
		{
			if (pointCollision(Vec2f(pos.x() + block_element[y][x].size.x() / 2, pos.y() + block_element[y][x].size.y() / 2), block_element[y][x].pos, block_element[y][x].size))
			{
				return Vec2f(x, y);
			}
		}
	}
}

Vec2f Map::CenteringEnemyPos(Vec2f enemy_pos){
	for (unsigned y = 0; y < block.size(); y++)
	{
		for (unsigned x = 0; x < block[y].size(); x++)
		{

			//drawPoint(block_element[y][x].pos.x(), block_element[y][x].pos.y(), 100, Color::cyan);
			//drawPoint(enemy_pos.x(), enemy_pos.y(), 100, Color::cyan);

			if (block_element[y][x].pos == Vec2i((float)enemy_pos.x(), (float)enemy_pos.y())){
				return Vec2f(block_element[y][x].pos.x(), block_element[y][x].pos.y());
			}
		}
	}
	return null;

}

bool Map::DirectionChange(Vec2f enemy_pos, int enemy_speed){
	for (unsigned y = 0; y < block.size(); y++)
	{
		for (unsigned x = 0; x < block[y].size(); x++)
		{
			if (block_element[y][x].pos == Vec2i((float)enemy_pos.x(), (float)enemy_pos.y())){
				return true;
			}
		}
	}
	return false;
}