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

	switch (blocktype){
	case '0':
		drawBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(), 5, block.color,
				block.angle,
				block.zoom, block.center);
		break;
	case '1':
		drawBox(block.pos.x(), block.pos.y(), block.size.x(), block.size.y(), 5, block.color,
				block.angle,
				block.zoom, block.center);
		break;


	}
}

void Block::GetElement(Vec2i pos, Vec2i size, char type){
	block.pos = Vec2f((float)pos.x(), (float)pos.y());
	block.size = Vec2f((float)size.x(), (float)size.y());
	category = type;
}