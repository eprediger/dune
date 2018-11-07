#ifndef __MODEL_H__
#define __MODEL_H__

#include "Unit/Unit.h"
#include "Map.h"
#include "Unit/OffensiveUnit.h"
#include "Player.h"
#include <vector>
#include <memory>

#define LIMIT_TO_SELECT 32*32

class Model {
private:
	Map map;
	std::vector<Unit*> units;
	std::vector<Building*> buildings;
    std::vector<Player> players;

public:
    Model(int width, int height, int n_player);
    ~Model();

//    Map& createMap();
	Map& getMap();

	Building &createBuilding(Building* building);
    Unit &createUnit(Unit *unit, int player);

	void step();
    void cleanDeadUnits();

	Player& getPlayer(int player);

	Unit* selectUnit(int x, int y);

};

#endif //__MODEL_H__
