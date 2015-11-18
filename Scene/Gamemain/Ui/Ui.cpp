#include "Ui.h"

bool collision(Vec2f pos, Vec2f floor_pos, Vec2f floor_size){
    return (
        pos.x() >= floor_pos.x() &&
        pos.x() <= floor_pos.x() + floor_size.x() &&
        pos.y() >= floor_pos.y() &&
        pos.y() <= floor_pos.y() + floor_size.y());

}
void drawBox(Vec2f pos,Vec2f size,Color _color){
    drawBox(pos.x(), pos.y(), size.x(), size.y(), 100, _color);
}

Ui::Ui()
{
    Setup();
    
}


void Ui::Setup(){
    font.size(100);
    for (int i = 0; i < static_cast<int>(Item::MAX); i++)
    {
        itemobject[i].size = Vec2f(100, 100);
        itemobject[i].pos = Vec2f(450, 120 - i * 120);
    }
}
void Ui::Cost(const int& cost){
    font.draw("コスト　" , Vec2f(WIDTH / 4, HEIGHT / 2-100),Color::white);
    font.draw(std::to_string(cost), Vec2f(WIDTH / 2 - font.drawSize(std::to_string(cost)).x(),
        HEIGHT / 2 - 200), Color::white);

}


void Ui::Draw(){

    drawFillBox(WIDTH / 4, -HEIGHT / 2, WIDTH / 4, HEIGHT, Color::blue);
    /*for (int y = 0; y < 8; y++){
        for (int x = 0; x < 8; x++)
        {
            drawBox(-WIDTH / 2 + (WIDTH * 3 / 4 / 8)*x, -HEIGHT / 2 + (HEIGHT / 8)*y,
                WIDTH * 3 / 4 / 8, HEIGHT / 8,100,Color::white);
        }
    }*/

    for (int i = 0; i < static_cast<int>(Item::MAX); i++)
    {
        drawFillBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
            itemobject[i].size.x(), itemobject[i].size.y(), Color::white);
    }
    //std::cout << env.mousePosition().x() << "  " << env.mousePosition().y() << std::endl;
}

void Ui::SelectDraw(Item _item){
    for (int i = 0; i < static_cast<int>(Item::MAX); i++)
    {  
        if (_item == static_cast<Item>(i))
        {
            drawBox(itemobject[i].pos, itemobject[i].size, Color::yellow);
        }
        
    }
}

Item Ui::Select(bool _Push){

    for (int i = 0; i < static_cast<int>(Item::MAX); i++)
    {
        if(collision(env.mousePosition(), itemobject[i].pos, itemobject[i].size)){
            return static_cast<Item>(i);
        }
        
    }
}


