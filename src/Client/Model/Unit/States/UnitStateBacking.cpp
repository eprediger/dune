#include "UnitStateBacking.h"

#include "Model/Unit/Unit.h"

UnitState *UnitStateBacking::makeAction(Map &map, Unit &unit) {
    return unit.makeBacking(map);
}
