#include "Player.h"


/////////コンストラクタ
Player::Player(){
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