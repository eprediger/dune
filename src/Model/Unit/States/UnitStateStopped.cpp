#include "UnitStateStopped.h"

#include "Model/Unit/Unit.h"

UnitState *UnitStateStopped::makeAction(Map &map, Unit &unit) {
    return unit.makeStopped(map);
}
