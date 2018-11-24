#include "UnitStateLoading.h"

#include "Model/Unit/Unit.h"

UnitState *UnitStateLoading::makeAction(Map &map, Unit &unit) {
    return unit.makeLoading(map);
}
