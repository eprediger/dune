#include "UnitStateFollowing.h"

#include "Model/Unit/Unit.h"

UnitState *UnitStateFollowing::makeAction(Map &map, Unit &unit) {
    return unit.makeFollow(map);
}
