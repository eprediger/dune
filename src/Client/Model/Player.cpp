#include "Model/Player.h"
#include "PlayerTrainingCenter.h"
#include "Player.h"
#include "GameConfiguration.h"

#include <algorithm>
#include <vector>
#include <string>

Player::Player(nlohmann::json& j) :
	id(j["id"]),
	house(j["house"].get<std::string>()),
	playerName(j["playerName"].get<std::string>()),
	generatedEnergy(j["generated_energy"]),
	consumedEnergy(j["consumed_energy"]),
	gold(j["gold"]),
	gold_limit(j["gold_limit"]),
	trainingCenter(new PlayerTrainingCenter(j["trainingCenter"])),
	buildingCenter(new PlayerBuildingCenter(j["buildingCenter"])) {}

void Player::update(nlohmann::json& j) {
	generatedEnergy = j["generated_energy"];
	consumedEnergy = j["consumed_energy"];
	gold = j["gold"];
	gold_limit = j["gold_limit"];
	trainingCenter->update(j["trainingCenter"]);
	buildingCenter->update(j["buildingCenter"]);
}

bool Player::operator==(const Player &other) const {
	return this->id == other.id;
}

int& Player::getId() {
	return this->id;
}

std::string& Player::getHouse() {
	return this->house;
}

std::string &Player::getName() {
	return this->playerName;
}

bool Player::hasBuilding(const Building::BuildingType buildingType) const {
	bool buildingTypeFound = false;
	unsigned i = 0;
	while ((!buildingTypeFound) && (i < this->buildings.size())) {
		buildingTypeFound = this->buildings[i]->is(buildingType);
		i++;
	}
	return buildingTypeFound;
}

void Player::cleanDeadBuildings() {
	std::vector<Building*>::iterator it = buildings.begin();
	while (it != buildings.end()) {
		if ((*it)->isDead()) {
			it = buildings.erase(it);
		} else {
			it++;
		}
	}
}

void Player::addBuilding(Building *building) {
	buildings.push_back(building);
	building->setPlayer(this);
}

int Player::getGoldLimit() const {
	return gold_limit;
}

float Player::getEnergyRatio() const {
	return (1 - ((float)this->consumedEnergy / (float)this->generatedEnergy));
}

bool Player::hasResourcesFor(const Building::BuildingType buildingType) const {
	bool canBuild = false;

	switch (buildingType) {
	case Building::BuildingType::CONSTRUCTION_YARD:
		canBuild = true;
		break;
	case Building::BuildingType::BARRACKS:
		canBuild = (this->gold >= GameConfiguration::getConfig().barracksCost);
		break;
	case Building::BuildingType::HEAVY_FACTORY:
		canBuild = (this->gold >= GameConfiguration::getConfig().heavyFactoryCost);
		break;
	case Building::BuildingType::LIGHT_FACTORY:
		canBuild = (this->gold >= GameConfiguration::getConfig().lightFactoryCost);
		break;
	case Building::BuildingType::SPICE_REFINERY:
		canBuild = (this->gold >= GameConfiguration::getConfig().spiceRefineryCost);
		break;
	case Building::BuildingType::SPICE_SILO:
		canBuild = (this->gold >= GameConfiguration::getConfig().spiceSiloCost);
		break;
	case Building::BuildingType::WIND_TRAP:
		canBuild = (this->gold >= GameConfiguration::getConfig().windTrapCost);
		break;
	default:    // El tipo de edificio no se encuentra definido
		canBuild = false;
	}

	return canBuild;
}

bool Player::hasResourcesFor(const Unit::UnitType unitType) const {
	bool canTrain;

	switch (unitType) {
	case Unit::UnitType::HARVESTER:
		canTrain = ((this->gold >= GameConfiguration::getConfig().harvesterCost)
		            && this->hasBuilding(Building::HEAVY_FACTORY));
		break;
	case Unit::UnitType::LIGHT_INFANTRY:
		canTrain = ((this->gold >= GameConfiguration::getConfig().lightInfantryCost)
		            && this->hasBuilding(Building::BARRACKS));
		break;
	case Unit::UnitType::HEAVY_INFANTRY:
		canTrain = ((this->gold >= GameConfiguration::getConfig().heavyInfantryCost)
		            && this->hasBuilding(Building::BARRACKS));
		break;
	case Unit::UnitType::RAIDER:
		canTrain = (this->house == "Ordos") && ((this->gold >= GameConfiguration::getConfig().raiderCost))
		           && (this->hasBuilding(Building::LIGHT_FACTORY));
		break;
	case Unit::UnitType::TANK:
		canTrain = ((this->gold >= GameConfiguration::getConfig().tankCost))
		           && (this->hasBuilding(Building::HEAVY_FACTORY));
		break;
	case Unit::UnitType::TRIKE:
		canTrain = (this->house != "Ordos") && ((this->gold >= GameConfiguration::getConfig().trikeCost))
		           && (this->hasBuilding(Building::LIGHT_FACTORY));
		break;
	default:    // El tipo de unidad no se encuentra definida
		canTrain = false;
	}
	return canTrain;
}
