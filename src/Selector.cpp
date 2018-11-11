#include "Selector.h"
#include "Unit/Unit.h"
#include <vector>
Selector::Selector(int x, int y)
    :pos(x,y)
    ,selection()
{
 
}

void Selector::addSelection(std::vector<Unit*>& units){
    this->selection.addSelection(units);
}
