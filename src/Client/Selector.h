#ifndef __SELECTOR_H__
#define __SELECTOR_H__

#include "Position.h"
#include "Selection.h"
#include "Model/Unit/Unit.h"
#include "Model/Buildings/Building.h"
#include "Selection.h"
#include <vector>

class Selector {
public:
	Selector(int x, int y);
	void addSelection(std::vector<Unit*>& units);
	void addSelection(std::vector<Building*>& buildings);
	Position pos;
	bool drag;
	Position drag_source;
	Selection selection;
};

#endif	// __SELECTOR_H__
