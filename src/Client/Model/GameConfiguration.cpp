#include <Model/GameConfiguration.h>
#include <Model/Buildings/Building.h>
#include <CustomException.h>

std::unique_ptr<GameConfiguration> GameConfiguration::instance(nullptr);

GameConfiguration::GameConfiguration(nlohmann::json& j) :
	SPEED_FACTOR(j["SPEED_FACTOR"]),
	RANGE_FACTOR(j["RANGE_FACTOR"]),
	TIME_FACTOR(j["TIME_FACTOR"]),
	buildingConstructionTime(j["buildingConstructionTime"]),
	constructionYardEnergy(j["constructionYardEnergy"]),
	constructionYardCost(j["constructionYardCost"]),
	constructionYardHitPoints(j["constructionYardHitPoints"]),
	constructionYardWidth(j["constructionYardWidth"]),
	constructionYardHeight(j["constructionYardHeight"]),
	windTrapEnergy(j["windTrapEnergy"]),
	windTrapCost(j["windTrapCost"]),
	windTrapHitPoints(j["windTrapHitPoints"]),
	windTrapWidth(j["windTrapWidth"]),
	windTrapHeight(j["windTrapHeight"]),
	lightFactoryEnergy(j["lightFactoryEnergy"]),
	lightFactoryCost(j["lightFactoryCost"]),
	lightFactoryHitPoints(j["lightFactoryHitPoints"]),
	lightFactoryWidth(j["lightFactoryWidth"]),
	lightFactoryHeight(j["lightFactoryHeight"]),
	heavyFactoryEnergy(j["heavyFactoryEnergy"]),
	heavyFactoryCost(j["heavyFactoryCost"]),
	heavyFactoryHitPoints(j["heavyFactoryHitPoints"]),
	heavyFactoryWidth(j["heavyFactoryWidth"]),
	heavyFactoryHeight(j["heavyFactoryHeight"]),
	spiceRefineryEnergy(j["spiceRefineryEnergy"]),
	spiceRefineryCost(j["spiceRefineryCost"]),
	spiceRefineryHitPoints(j["spiceRefineryHitPoints"]),
	spiceRefinerySpiceCapacity(j["spiceRefinerySpiceCapacity"]),
	spiceRefinerySpicWidth(j["spiceRefinerySpicWidth"]),
	spiceRefinerySpicHeight(j["spiceRefinerySpicHeight"]),
	spiceSiloEnergy(j["spiceSiloEnergy"]),
	spiceSiloCost(j["spiceSiloCost"]),
	spiceSiloHitPoints(j["spiceSiloHitPoints"]),
	spiceSiloSpiceCapacity(j["spiceSiloSpiceCapacity"]),
	spiceSiloSpicWidth(j["spiceSiloSpicWidth"]),
	spiceSiloSpicHeight(j["spiceSiloSpicHeight"]),
	barracksEnergy(j["barracksEnergy"]),
	barracksCost(j["barracksCost"]),
	barracksHitPoints(j["barracksHitPoints"]),
	barracksWidth(j["barracksWidth"]),
	barracksHeight(j["barracksHeight"]) {}

void GameConfiguration::init(nlohmann::json& j) {
	if (instance == nullptr) {
		instance = std::unique_ptr<GameConfiguration>(new GameConfiguration(j));
	}
}

GameConfiguration &GameConfiguration::getConfig() {
	if (instance == nullptr) {
		throw CustomException("Game Configuration Not initialized");
		// instance = std::unique_ptr<GameConfiguration>(new GameConfiguration(config));
	}
	return *instance;
}
