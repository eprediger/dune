#include "UnitStateTraining.h"

UnitState* UnitStateTraining::makeAction(Map& map, Unit& unit) {
	 return this;
}

bool UnitStateTraining::isTraining() {
	return true;
}
