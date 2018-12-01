#include <Model/GameConfiguration.h>
#include <Model/Buildings/Building.h>
#include <CustomException.h>

std::unique_ptr<GameConfiguration> GameConfiguration::instance(nullptr);

GameConfiguration::GameConfiguration(nlohmann::json& j) :
	initialGold(j["initialGold"]),
	initialEnergy(j["initialEnergy"]),
	initialMaxEnergy(j["initialMaxEnergy"]),	

	buildingConstructionTime(j["buildingConstructionTime"]),
	
	constructionYardCost(j["constructionYardCost"]),
	constructionYardWidth(j["constructionYardWidth"]),
	constructionYardHeight(j["constructionYardHeight"]),
	
	windTrapCost(j["windTrapCost"]),
	windTrapWidth(j["windTrapWidth"]),
	windTrapHeight(j["windTrapHeight"]),
	
	lightFactoryCost(j["lightFactoryCost"]),
	lightFactoryWidth(j["lightFactoryWidth"]),
	lightFactoryHeight(j["lightFactoryHeight"]),
	
	heavyFactoryCost(j["heavyFactoryCost"]),
	heavyFactoryWidth(j["heavyFactoryWidth"]),
	heavyFactoryHeight(j["heavyFactoryHeight"]),
	
	spiceRefineryCost(j["spiceRefineryCost"]),
	spiceRefinerySpiceCapacity(j["spiceRefinerySpiceCapacity"]),
	spiceRefineryWidth(j["spiceRefineryWidth"]),
	spiceRefineryHeight(j["spiceRefineryHeight"]),
	
	spiceSiloCost(j["spiceSiloCost"]),
	spiceSiloSpiceCapacity(j["spiceSiloSpiceCapacity"]),
	spiceSiloWidth(j["spiceSiloWidth"]),
	spiceSiloHeight(j["spiceSiloHeight"]),
	
	barracksCost(j["barracksCost"]),
	barracksWidth(j["barracksWidth"]),
	barracksHeight(j["barracksHeight"]),
	
	lightInfantryTrainingTime(j["lightInfantryTrainingTime"]),
	lightInfantryCost(j["lightInfantryCost"]),
	
	heavyInfantryTrainingTime(j["heavyInfantryTrainingTime"]),
	heavyInfantryCost(j["heavyInfantryCost"]),
	
	harvesterConstructionTime(j["harvesterConstructionTime"]),
	harvesterCost(j["harvesterCost"]),
	
	trikeConstructionTime(j["trikeConstructionTime"]),
	trikeCost(j["trikeCost"]),
	
	raiderConstructionTime(j["raiderConstructionTime"]),
	raiderCost(j["raiderCost"]),
	
	tankConstructionTime(j["tankConstructionTime"]),
	tankCost(j["tankCost"]) {}

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
