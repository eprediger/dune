#ifndef __SELECTION_H__
#define __SELECTION_H__

#include "Model/Unit/Unit.h"
#include "Model/Buildings/Building.h"
#include <vector>

class Selection {
public:
	Selection();
	
	void addSelection(std::vector<Unit*>& new_units);
	
	void addSelection(std::vector<Building*>& new_buildings);
	
	void eraseDeads();
	
	std::vector<Unit*>& getSelectedUnits();
	
	std::vector<Building*>& getSelectedBuildings();

private:
	std::vector<Unit*> units;
	std::vector<Building*> buildings;
};

#endif  // __SELECTION_H__
