
#include "../../../Share.h"
class Player
{
public:
 
    Player();
    Vec2f GetMousePosition();
    bool MouseClick();
    int GetSelectUnit();

private:

    int select_unit;


};
