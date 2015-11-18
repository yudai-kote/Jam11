#include "Player.h"



Vec2f Player::GetMousePosition(){
    return env.mousePosition();
}

bool Player::MouseClick(){
    return env.isPushButton(Mouse::LEFT);
}

int Player::GetSelectUnit(){

    return select_unit;
}