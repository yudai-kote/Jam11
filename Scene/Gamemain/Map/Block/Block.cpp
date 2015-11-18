#include "Block.h"

void Block::Setup(){

}

void Block::TextureSetup(){

}

void Block::Update(){


}

void Block::Draw(){

	/*drawTextureBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(),
				   block.offset_pos.x(), block.offset_pos.y(),
				   block.offset_size.x(), block.offset_size.y(),
				   block.tex,block.color,
				   block.angle,
				   block.zoom,block.center);*/

	drawFillBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(), block.color,
				block.angle,
				block.zoom, block.center);
	if (is_desk == Item::DESK){
		drawTextureBox(block.pos.x(), block.pos.y(),
					   block.size.x(), block.size.y(),
					   block.offset_pos.x(), block.offset_pos.y(),
					   block.offset_size.x(), block.offset_size.y(),
					   *tex_list[DESK],
					   Color::white);
	}

	switch (category){
	case Item::AIR:

		break;
	case Item::DESK:

		break;
	case Item::COMIC:
		drawTextureBox(block.pos.x(), block.pos.y(),
					   block.size.x(), block.size.y(),
					   block.offset_pos.x(), block.offset_pos.y(),
					   block.offset_size.x(), block.offset_size.y(),
					   *tex_list[COMIC],
					   Color::white);
		break;
	case Item::GAME:
		drawTextureBox(block.pos.x(), block.pos.y(),
					   block.size.x(), block.size.y(),
					   block.offset_pos.x(), block.offset_pos.y(),
					   block.offset_size.x(), block.offset_size.y(),
					   *tex_list[GAME],
					   Color::white);
		break;
	case Item::ROBOT:
		drawTextureBox(block.pos.x(), block.pos.y(),
					   block.size.x(), block.size.y(),
					   block.offset_pos.x(), block.offset_pos.y(),
					   block.offset_size.x(), block.offset_size.y(),
					   *tex_list[ROBOT],
					   Color::white);
		break;
	}

	if (blocktype == '1'){
		drawTextureBox(block.pos.x(), block.pos.y(),
					   block.size.x(), block.size.y(),
					   block.offset_pos.x(), block.offset_pos.y(),
					   block.offset_size.x(), block.offset_size.y(),
					   *tex_list[DESK],
					   Color::red);
	}
}

void Block::SetElement(Vec2i pos, Vec2i size, Item type){
	block.pos = Vec2f((float)pos.x(), (float)pos.y());
	block.size = Vec2f((float)size.x(), (float)size.y());
	category = type;
}

void Block::SetColor(Color block_color){
	block.color = block_color;
}

void Block::SetItem(Item item){
	category = item;
}

void Block::SetDesk(Item desk){
	is_desk = desk;
}

Item Block::GetItem(){
	return category;
}

Item Block::GetDesk(){
	return is_desk;
}