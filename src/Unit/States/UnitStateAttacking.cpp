#include "UnitStateAttacking.h"
#include "../../Position.h"

#include "../Unit.h"

UnitState *UnitStateAttacking::makeAction(Map &map, Unit &unit) {
    return unit.makeAttack(map);
}

bool UnitStateAttacking::isAttacking() {
    return true;
}
