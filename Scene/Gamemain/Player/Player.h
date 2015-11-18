
#include "../../../Share.h"
class Player
{
public:
 
    Player();
    void Setup();

    void Update();

    Vec2f GetMousePosition();
    bool MouseClick();
    Item GetSelectItem();
    int GetCost();
    void SetSelectItem(Item _item);

private:

    Item select_Item;
    int cost;

};
