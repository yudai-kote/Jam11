#include "Title.h"

Title::Title(){
    Setup();


}


void Title::Setup(){
    count = 0;



}

void Title::Update(){
    
    if (env.isPushButton(Mouse::LEFT) &&
        count == 0)
        count++;
    if (count > 0)
        count++;

}

void Title::Draw(){
    drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color::blue);
    drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color(0, 0, 0, (float)count / 30.f));
    //drawBox(100, 100, 100, 100, 100, Color::blue);

}


Scenename Title::Shift(){

    if (count == 30){
        Setup();
        return Scenename::STAGESELECT;
    
    }
    return Scenename::TITLE;
}