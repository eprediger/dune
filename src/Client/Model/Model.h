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
#include "Weapons/Rocket.h"
#include <vector>
#include <map>
#include <memory>
#include "CommunicationQueue.h"

#define LIMIT_TO_SELECT (32*32)

class Model {
private:
	Map map;
	std::map<int, Unit*> units;
	std::map<int, Building*> buildings;
	std::map<int, Player*> players;
	std::map<int, Rocket*> rockets;
	bool gameFinished;
	CommunicationQueue& queue;

public:
	Model(nlohmann::json& file, CommunicationQueue &queue);
	~Model();

	Map& getMap();

	void addPlayer(nlohmann::json& j);
	void updatePlayer(nlohmann::json& j);

	bool playerExists(int id);
	bool buildingExists(int id);
	bool unitExists(int id);
	bool rocketExists(int id);

	Harvester& createHarvester(nlohmann::json& j);
	HeavyInfantry& createHeavyInfantry(nlohmann::json& j);
	LightInfantry& createLightInfantry(nlohmann::json& j);
	Raider& createRaider(nlohmann::json& j);
	Tank& createTank(nlohmann::json& j);
	Trike& createTrike(nlohmann::json& j);
	Unit &createUnit(Unit *unit);
	void updateUnit(nlohmann::json& j);

	Barracks& createBarracks(nlohmann::json& j);
	ConstructionYard& createConstructionYard(nlohmann::json& j);
	HeavyFactory& createHeavyFactory(nlohmann::json& j);
	LightFactory& createLightFactory(nlohmann::json& j);
	SpiceRefinery& createSpiceRefinery(nlohmann::json& j);
	SpiceSilo& createSpiceSilo(nlohmann::json& j);
	WindTrap& createWindTrap(nlohmann::json& j);
	Building& createBuilding(Building* building);
	void updateBuilding(nlohmann::json& j);

	Rocket& createRocket(nlohmann::json& j);
	void updateRocket(nlohmann::json& j);


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

};

#endif	// __MODEL_H__
