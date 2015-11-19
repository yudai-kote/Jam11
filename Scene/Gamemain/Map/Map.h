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
		TEX_DESK,
		TEXTURE_MAX,
	};

	enum Chiptype{
		DESK_BLOCK = '1',
		PLAYER_START_POS = '2',
		ENEMY_START_POS = '3',
	};

	struct Element{
		Vec2i pos;
		Vec2i size;
	};



	std::vector<std::vector<Block>> block;
	std::ifstream file_list[FILE_MAX];
	std::vector<std::vector<Element>> block_element;
	std::vector<std::vector<int>> one_or_zero;	// Astar用のvector


	// コスト
	int cost = 1000;
	int desk_cost = 100;
	int item_cost = 50;
	int item_cost_ex = 200;

	bool is_fillbox;

	


	Texture *tex_list[TEXTURE_MAX];

	void ChangeBlock();
	bool pointCollision(Vec2f point_pos, Vec2i box_pos, Vec2i box_size);
public:

	Map();

	void Setup();
	void TextureSetup();
	void Draw();
	void Update();

	void Editor(Item item, bool is_put = true);

	void SetIsFillBox(bool is_box = true);
	Vec2f CenteringEnemyPos(Vec2f enemy_pos);

	bool DirectionChange(Vec2f enemy_pos, int enemy_speed);

	Vec2f GetPlayerPos();
	Vec2f GetEnemyPos();
	Vec2f GetPlayerChip();
	Vec2f GetEnemyChip();

	Vec2f ChangeChip(Vec2f pos);

	int GetCost();
	std::vector<std::vector<int>> GetStatus();

};