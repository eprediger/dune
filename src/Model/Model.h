#ifndef __MODEL_H__
#define __MODEL_H__

#include "Unit/Unit.h"
#include "Map.h"
#include "Unit/OffensiveUnit.h"
#include "Player.h"
#include "Unit/Raider.h"
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

    void createHarvester(int x, int y, int player);
    void createHeavyInfantry(int x, int y, int player);
    void createLightInfantry(int x, int y, int player);
    Raider & createRaider(int x, int y, int player);
    void createTank(int x, int y, int player);
    void createTrike(int x, int y, int player);
    Unit &createUnit(Unit *unit);

    void createBarracks(int x, int y, int player);
    void createConstructionYard(int x, int y, int player);
    void createHeavyFactory(int x, int y, int player);
    void createLightFactory(int x, int y, int player);
    void createSpiceRefinery(int x, int y, int player);
    void createSpiceSilo(int x, int y, int player);
    void createWindTrap(int x, int y, int player);
	Building &createBuilding(Building* building);

    Unit * selectUnit(Position &pos, int player);
    std::vector<Unit*> selectUnitsInArea(Area& area, Player& player);

    void actionOnPosition(Position &pos, Unit &unit);

	void step();
    void cleanDeadUnits();

	Player& getPlayer(int player);

	Unit* selectUnit(int x, int y);

};

#endif //__MODEL_H__
