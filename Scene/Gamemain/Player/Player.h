
#include "../../../Share.h"
class Player
{
public:
 
    Player();
    void Setup();

    void Update();
    void Draw();
    

    Vec2f GetMousePosition();
    bool MouseClick();
    Item GetSelectItem();
    int GetCost();
    void SetSelectItem(Item _item);
    void SetPos(Vec2f _pos);


private:

    Item select_Item;
    int cost;
    Vec2f pos;
    Texture player;
    int ani_count;
    

};
