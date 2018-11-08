#include "UnitStateMoving.h"

#include "../Unit.h"

UnitState *UnitStateMoving::makeAction(Map &map, Unit &unit) {
    unit.move(map);
    return this;
}
