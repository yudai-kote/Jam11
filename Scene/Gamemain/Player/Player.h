
#include "../../../Share.h"
class Player
{
public:
 
    Player();
    void Setup();


    Vec2f GetMousePosition();
    bool MouseClick();
    Item GetSelectItem();
    int GetCost();


private:

    Item select_Item;
    int cost;

};
