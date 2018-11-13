#include "UnitStateBacking.h"

#include "../Unit.h"

UnitState *UnitStateBacking::makeAction(Map &map, Unit &unit) {
    return unit.makeBacking(map);
}
