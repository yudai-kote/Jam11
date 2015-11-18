
#include "../../../Share.h"
class Player
{
public:
 
    Player();
    Vec2f GetMousePosition();
    bool MouseClick();
    Item GetSelectItem();



private:

    Item select_Item;


};
