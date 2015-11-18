#include "Ui.h"

Ui::Ui()
{
    Setup();

}

void Ui::Setup(){
    font.size(100);
}
void Ui::Cost(const int& cost){
    font.draw("コスト　　" + cost, Vec2f(WIDTH / 4, HEIGHT / 2),Color::white);


}


void Ui::Draw(){

    drawFillBox(WIDTH / 4, -HEIGHT / 2, WIDTH / 4, HEIGHT, Color::blue);
    for (int y = 0; y < 8; y++){
        for (int x = 0; x < 8; x++)
        {
            drawBox(-WIDTH / 2 + (WIDTH * 3 / 4 / 8)*x, -HEIGHT / 2 + (HEIGHT / 8)*y,
                WIDTH * 3 / 4 / 8, HEIGHT / 8,100,Color::white);
        }
    }
    //font 
    //drawFillBox()

}



