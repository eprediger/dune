#include "UnitStateMoving.h"
#include "Model/Unit/Unit.h"

UnitState *UnitStateMoving::makeAction(Map &map, Unit &unit) {
	if (unit.move(map)) {
		return this;
	} else {
		return (UnitState*)&Unit::stopped;
	}
}
