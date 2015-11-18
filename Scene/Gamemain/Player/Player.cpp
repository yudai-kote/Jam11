#include "Player.h"


/////////コンストラクタ
Player::Player(){
    
    Setup();

}

void Player::Setup(){
    cost = 50;
    select_Item = Item::COMIC;

}

void Player::Update(){

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

void Player::SetSelectItem(Item _item){
    select_Item = _item;
}