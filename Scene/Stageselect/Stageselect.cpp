#include "Stageselect.h"

Stageselect::Stageselect(){

    Setup();

}


void Stageselect::Setup(){
    count = 30;
    is_ok = false;



}

void Stageselect::Update(){
    
    if (count > 0 &&
        !is_ok){
        count--;
    }
    if (env.isPushButton(Mouse::LEFT) &&
        count == 0){
        is_ok = true;
    }
    if (is_ok){
        count++;
    }
    
    


}

void Stageselect::Draw(){
    drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color::yellow);
    drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color(0, 0, 0, static_cast<float>(count) / 30.f));

}


Scenename Stageselect::Shift(){
    std::cout << count << std::endl;
	if (count == 30){
        Setup();
		return Scenename::GAMEMAIN;
	}
    return Scenename::STAGESELECT;
}