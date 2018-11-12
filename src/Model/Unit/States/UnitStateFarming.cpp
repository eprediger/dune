#include "UnitStateFarming.h"

#include "../Unit.h"

UnitState *UnitStateFarming::makeAction(Map &map, Unit &unit) {
    return unit.makeFarming(map);
}
