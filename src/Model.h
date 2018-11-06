#ifndef __MODEL_H__
#define __MODEL_H__

#include "Unit/Unit.h"
#include "Map.h"
#include "Unit/OffensiveUnit.h"
#include <vector>
#include <memory>

#define LIMIT_TO_SELECT 32*32

class Model {
private:
	Map map;
	std::vector<std::unique_ptr<Unit>> units;
	std::vector<std::unique_ptr<Building>> buildings;

public:
	Model(int width, int height);

//    Map& createMap();
	Map& getMap();

	Unit &createUnit(Unit *unit);
	Building &createBuilding(Building* building);

	void step();
    void cleanDeadUnits();

	Unit* selectUnit(int x, int y);

};

#endif //__MODEL_H__
