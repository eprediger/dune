#include "UnitStateFollowing.h"

#include "../Unit.h"

UnitState *UnitStateFollowing::makeAction(Map &map, Unit &unit) {
    return unit.makeFollow(map);
}
