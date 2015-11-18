#include "../../../Share.h"

class Ui
{
public:
    Ui();
    
    void Draw();

    void Setup();
    void Cost(const int& cost);
    Item Select(Vec2f _mouse, bool _Push);




private:
    Font font = Font("res/meiryo.ttc");

    
    
    struct ItemForm 
    {
        
    };
};

