#include "Player.h"


/////////コンストラクタ
Player::Player(){
    select_Item = Item::COMIC;
    Setup();

}

void Player::Setup(){
    cost = 50;
    select_Item = Item::COMIC;

}


Vec2f Player::GetMousePosition(){
    return env.mousePosition();
}

bool Player::MouseClick(){
    return env.isPushButton(Mouse::LEFT);
}

Item Player::GetSelectItem(){

    return select_Item;
}

int Player::GetCost(){
    return cost;
}