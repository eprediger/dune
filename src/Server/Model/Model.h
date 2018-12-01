#ifndef __MODEL_H__
#define __MODEL_H__

#include "Unit/Unit.h"
#include "Map.h"
#include "Unit/OffensiveUnit.h"
#include "Model/Player.h"
#include "Unit/Raider.h"
#include "Unit/Trike.h"
#include "Unit/Tank.h"
#include "Unit/LightInfantry.h"
#include "Unit/HeavyInfantry.h"
#include "Unit/Harvester.h"
#include "Model/Buildings/Barracks.h"
#include "Model/Buildings/ConstructionYard.h"
#include "Model/Buildings/SpiceRefinery.h"
#include "Model/Buildings/SpiceSilo.h"
#include "Model/Buildings/WindTrap.h"
#include "Model/Buildings/HeavyFactory.h"
#include "Model/Buildings/LightFactory.h"
#include <Model/GameConfiguration.h>
#include <vector>
#include <map>
#include <memory>
#include <CommunicationQueue.h>

class AcceptedPlayer;

#define LIMIT_TO_SELECT (32*32)

class Model {
private:
	Map map;
	std::map<int, Unit*> units;
	std::map<int, Building*> buildings;
	std::map<int, Player*> players;
	std::vector<Rocket*> rockets;
	bool gameFinished;

public:
	explicit Model(const char *file);
    ~Model();

//    Map& createMap();
	Map& getMap();

	int addPlayer(const std::string& house);

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

	void cleanDeadBuildings();

	/// TEMPORAL
	Building & getBuildingById(int id);
	Unit& getUnitById(int id);

	void serialize(std::vector<AcceptedPlayer*>& players);
};

#endif	// __MODEL_H__
