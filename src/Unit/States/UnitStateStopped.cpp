#include "UnitStateStopped.h"

#include "../Unit.h"

UnitState *UnitStateStopped::makeAction(Map &map, Unit &unit) {
    return unit.makeStopped(map);
}
