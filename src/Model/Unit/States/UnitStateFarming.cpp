#include "UnitStateFarming.h"

#include "Model/Unit/Unit.h"

UnitState *UnitStateFarming::makeAction(Map &map, Unit &unit) {
    return unit.makeFarming(map);
}
