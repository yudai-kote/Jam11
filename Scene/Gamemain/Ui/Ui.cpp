#include "Ui.h"

bool collision(Vec2f pos, Vec2f floor_pos, Vec2f floor_size){
    return (
        pos.x() > floor_pos.x() &&
        pos.x() < floor_pos.x() + floor_size.x() &&
        pos.y() >= floor_pos.y() &&
        pos.y() <= floor_pos.y() + floor_size.y());

}

Ui::Ui()
{
    Setup();
    
}


void Ui::Setup(){
    font.size(100);
    
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

    
}


Item Ui::Select(Vec2f _mouse, bool _Push){


    return Item::COMIC;

}


