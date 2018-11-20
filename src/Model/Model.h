#ifndef __MODEL_H__
#define __MODEL_H__

#include "Unit/Unit.h"
#include "Map.h"
#include "Unit/OffensiveUnit.h"
#include "Player.h"
#include "Unit/Raider.h"
#include "Unit/Trike.h"
#include "Unit/Tank.h"
#include "Unit/LightInfantry.h"
#include "Unit/HeavyInfantry.h"
#include "Unit/Harvester.h"
#include "Buildings/Barracks.h"
#include "Buildings/ConstructionYard.h"
#include "Buildings/SpiceRefinery.h"
#include "Buildings/SpiceSilo.h"
#include "Buildings/WindTrap.h"
#include "Buildings/HeavyFactory.h"
#include "Buildings/LightFactory.h"
#include <vector>
#include <memory>

#define LIMIT_TO_SELECT (32*32)

class Model {
private:
	Map map;
	std::vector<Unit*> units;
	std::vector<Building*> buildings;
    std::vector<Player*> players;
	std::vector<Rocket*> rockets;
    bool gameFinished;

public:
    Model(const char* file, int n_player);
    ~Model();

//    Map& createMap();
	Map& getMap();

	Harvester& createHarvester(int x, int y, int player);
	HeavyInfantry& createHeavyInfantry(int x, int y, int player);
	LightInfantry& createLightInfantry(int x, int y, int player);
	Raider& createRaider(int x, int y, int player);
	Tank& createTank(int x, int y, int player);
	Trike& createTrike(int x, int y, int player);
    Unit &createUnit(Unit *unit);

	Barracks& createBarracks(int x, int y, int player);
	ConstructionYard& createConstructionYard(int x, int y, int player);
	HeavyFactory& createHeavyFactory(int x, int y, int player);
	LightFactory& createLightFactory(int x, int y, int player);
	SpiceRefinery& createSpiceRefinery(int x, int y, int player);
	SpiceSilo& createSpiceSilo(int x, int y, int player);
	WindTrap& createWindTrap(int x, int y, int player);
	Building& createBuilding(Building* building);

    Unit* selectUnit(Position &pos, int player);
    std::vector<Unit*> selectUnitsInArea(Area& area, Player& player);
	std::vector<Building*> selectBuildingsInArea(Area& area, Player& player);
    void actionOnPosition(Position &pos, Unit &unit);
	bool canWeBuild(Position& pos, int width, int height, int cost, Player& player); 
	void step();
    void cleanDeadUnits();
	void cleanRockets();
    bool isGameFinished();
    Player* getWinner();

	Player& getPlayer(int player);

	int numberOfPlayers();

	Unit* selectUnit(int x, int y);

	void cleanDeadBuildings();
};

#endif	// __MODEL_H__
