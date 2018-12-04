#include "Selector.h"
#include "Model/Unit/Unit.h"
#include <vector>

Selector::Selector(int x, int y) :
	pos(x, y),
	drag(false),
	drag_source(x, y),
	selection(),
	newUnits(false) {}

void Selector::addSelection(std::vector<Unit*>& units) {
	if (!units.empty()){
		newUnits = true;
	}	
	this->selection.addSelection(units);

}

void Selector::addSelection(std::vector<Building*>& buildings) {
	this->selection.addSelection(buildings);
}
