#include "UnitStateLoading.h"

#include "../Unit.h"

UnitState *UnitStateLoading::makeAction(Map &map, Unit &unit) {
    return unit.makeLoading(map);
}
