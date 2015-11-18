#include "../../../Share.h"

class Ui
{
public:
    Ui();
    
    void Draw();

    void Setup();
    void Cost(const int& cost);
    Item Select(bool _Push);
    void SelectDraw(Item _item);



private:
    Font font = Font("res/meiryo.ttc");
    
    Object itemobject[static_cast<int>(Item::MAX)];
    

    
    
};

