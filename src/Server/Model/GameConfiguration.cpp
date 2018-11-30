#include <Model/GameConfiguration.h>
#include <Model/Buildings/Building.h>
#include <CustomException.h>

std::unique_ptr<GameConfiguration> GameConfiguration::instance(nullptr);

GameConfiguration::GameConfiguration(const ConfigurationReader& config) :
	SPEED_FACTOR(config.getSpeedFactor()),
	RANGE_FACTOR(config.getRangeFactor()),
	TIME_FACTOR(config.getTimeFactor()),
	buildingConstructionTime(config.getBuildingConstructionTime() * TIME_FACTOR),
	constructionYardEnergy(config.getEnergyFor(Building::BuildingType::CONSTRUCTION_YARD)),
	constructionYardCost(config.getCostFor(Building::BuildingType::CONSTRUCTION_YARD)),
	constructionYardHitPoints(config.getHitPointsFor(Building::BuildingType::CONSTRUCTION_YARD)),
	constructionYardWidth(config.getWidthFor(Building::BuildingType::CONSTRUCTION_YARD)),
	constructionYardHeight(config.getHeightFor(Building::BuildingType::CONSTRUCTION_YARD)),
	windTrapEnergy(config.getEnergyFor(Building::BuildingType::WIND_TRAP)),
	windTrapCost(config.getCostFor(Building::BuildingType::WIND_TRAP)),
	windTrapHitPoints(config.getHitPointsFor(Building::BuildingType::WIND_TRAP)),
	windTrapWidth(config.getWidthFor(Building::BuildingType::WIND_TRAP)),
	windTrapHeight(config.getHeightFor(Building::BuildingType::WIND_TRAP)),
	lightFactoryEnergy(config.getEnergyFor(Building::BuildingType::LIGHT_FACTORY)),
	lightFactoryCost(config.getCostFor(Building::BuildingType::LIGHT_FACTORY)),
	lightFactoryHitPoints(config.getHitPointsFor(Building::BuildingType::LIGHT_FACTORY)),
	lightFactoryWidth(config.getWidthFor(Building::BuildingType::LIGHT_FACTORY)),
	lightFactoryHeight(config.getHeightFor(Building::BuildingType::LIGHT_FACTORY)),
	heavyFactoryEnergy(config.getEnergyFor(Building::BuildingType::HEAVY_FACTORY)),
	heavyFactoryCost(config.getCostFor(Building::BuildingType::HEAVY_FACTORY)),
	heavyFactoryHitPoints(config.getHitPointsFor(Building::BuildingType::HEAVY_FACTORY)),
	heavyFactoryWidth(config.getWidthFor(Building::BuildingType::HEAVY_FACTORY)),
	heavyFactoryHeight(config.getHeightFor(Building::BuildingType::HEAVY_FACTORY)),
	spiceRefineryEnergy(config.getEnergyFor(Building::BuildingType::SPICE_REFINERY)),
	spiceRefineryCost(config.getCostFor(Building::BuildingType::SPICE_REFINERY)),
	spiceRefineryHitPoints(config.getHitPointsFor(Building::BuildingType::SPICE_REFINERY)),
	spiceRefinerySpiceCapacity(config.getSpiceCapacityFor(Building::BuildingType::SPICE_REFINERY)),
	spiceRefinerySpicWidth(config.getWidthFor(Building::BuildingType::SPICE_REFINERY)),
	spiceRefinerySpicHeight(config.getHeightFor(Building::BuildingType::SPICE_REFINERY)),
	spiceSiloEnergy(config.getEnergyFor(Building::BuildingType::SPICE_REFINERY)),
	spiceSiloCost(config.getCostFor(Building::BuildingType::SPICE_REFINERY)),
	spiceSiloHitPoints(config.getHitPointsFor(Building::BuildingType::SPICE_REFINERY)),
	spiceSiloSpiceCapacity(config.getSpiceCapacityFor(Building::BuildingType::SPICE_REFINERY)),
	spiceSiloSpicWidth(config.getWidthFor(Building::BuildingType::SPICE_REFINERY)),
	spiceSiloSpicHeight(config.getHeightFor(Building::BuildingType::SPICE_REFINERY)),
	barracksEnergy(config.getEnergyFor(Building::BuildingType::BARRACKS)),
	barracksCost(config.getCostFor(Building::BuildingType::BARRACKS)),
	barracksHitPoints(config.getHitPointsFor(Building::BuildingType::BARRACKS)),
	barracksWidth(config.getWidthFor(Building::BuildingType::BARRACKS)),
	barracksHeight(config.getHeightFor(Building::BuildingType::BARRACKS)) {}

void GameConfiguration::init(const char *string) {
	if (instance == nullptr){
		ConfigurationReader config(string);
		instance = std::unique_ptr<GameConfiguration>(new GameConfiguration(config));
	}
}

GameConfiguration &GameConfiguration::getConfig() {
	if (instance == nullptr){
		// throw CustomException("Game Configuration Not initialized");
		ConfigurationReader config("../gameConfig.yaml");
		instance = std::unique_ptr<GameConfiguration>(new GameConfiguration(config));

	}
	return *instance;
}

nlohmann::json GameConfiguration::initwithJson() {
	nlohmann::json j;
	j["SPEED_FACTOR"] = this->SPEED_FACTOR;
	j["RANGE_FACTOR"] = this->RANGE_FACTOR;
	j["TIME_FACTOR"] = this->TIME_FACTOR;
	j["buildingConstructionTime"] = this->buildingConstructionTime;
	j["constructionYardEnergy"] = this->constructionYardEnergy;
	j["constructionYardCost"] = this->constructionYardCost;
	j["constructionYardHitPoints"] = this->constructionYardHitPoints;
	j["constructionYardWidth"] = this->constructionYardWidth;
	j["constructionYardHeight"] = this->constructionYardHeight;
	j["windTrapEnergy"] = this->windTrapEnergy;
	j["windTrapCost"] = this->windTrapCost;
	j["windTrapHitPoints"] = this->windTrapHitPoints;
	j["windTrapWidth"] = this->windTrapWidth;
	j["windTrapHeight"] = this->windTrapHeight;
	j["lightFactoryEnergy"] = this->lightFactoryEnergy;
	j["lightFactoryCost"] = this->lightFactoryCost;
	j["lightFactoryHitPoints"] = this->lightFactoryHitPoints;
	j["lightFactoryWidth"] = this->lightFactoryWidth;
	j["lightFactoryHeight"] = this->lightFactoryHeight;
	j["heavyFactoryEnergy"] = this->heavyFactoryEnergy;
	j["heavyFactoryCost"] = this->heavyFactoryCost;
	j["heavyFactoryHitPoints"] = this->heavyFactoryHitPoints;
	j["heavyFactoryWidth"] = this->heavyFactoryWidth;
	j["heavyFactoryHeight"] = this->heavyFactoryHeight;
	j["spiceRefineryEnergy"] = this->spiceRefineryEnergy;
	j["spiceRefineryCost"] = this->spiceRefineryCost;
	j["spiceRefineryHitPoints"] = this->spiceRefineryHitPoints;
	j["spiceRefinerySpiceCapacity"] = this->spiceRefinerySpiceCapacity;
	j["spiceRefinerySpicWidth"] = this->spiceRefinerySpicWidth;
	j["spiceRefinerySpicHeight"] = this->spiceRefinerySpicHeight;
	j["spiceSiloEnergy"] = this->spiceSiloEnergy;
	j["spiceSiloCost"] = this->spiceSiloCost;
	j["spiceSiloHitPoints"] = this->spiceSiloHitPoints;
	j["spiceSiloSpiceCapacity"] = this->spiceSiloSpiceCapacity;
	j["spiceSiloSpicWidth"] = this->spiceSiloSpicWidth;
	j["spiceSiloSpicHeight"] = this->spiceSiloSpicHeight;
	j["barracksEnergy"] = this->barracksEnergy;
	j["barracksCost"] = this->barracksCost;
	j["barracksHitPoints"] = this->barracksHitPoints;
	j["barracksWidth"] = this->barracksWidth;
	j["barracksHeight"] = this->barracksHeight;
	return j;
}
