#include "ConfigurationReader.h"
#include <CustomException.h>
#include <Codes.h>

ConfigurationReader::ConfigurationReader(const char *filename) :
	YAMLReader(filename) {}

ConfigurationReader::~ConfigurationReader() {}

unsigned ConfigurationReader::getSpeedFactor() const {
	return this->config["SPEED_FACTOR"].as<unsigned>();
}

unsigned ConfigurationReader::getRangeFactor() const {
	return this->config["RANGE_FACTOR"].as<unsigned>();
}

unsigned ConfigurationReader::getTimeFactor() const {
	return this->config["TIME_FACTOR"].as<unsigned>();
}

unsigned ConfigurationReader::getBuildingConstructionTime() const {
	return this->config["buildings"]["constructionTime"].as<unsigned>();
}

unsigned ConfigurationReader::getEnergyFor(Building::BuildingType buildingType) const {
	std::string buildingName;
	buildingName = this->parseType(buildingType);
	return this->config["buildings"][buildingName]["energy"].as<unsigned>();
}

unsigned ConfigurationReader::getCostFor(Building::BuildingType buildingType) const {
	std::string buildingName = this->parseType(buildingType);
	return this->config["buildings"][buildingName]["cost"].as<unsigned>();
}

unsigned ConfigurationReader::getHitPointsFor(Building::BuildingType buildingType) const {
	std::string buildingName = this->parseType(buildingType);
	return this->config["buildings"][buildingName]["hitPoints"].as<unsigned>();
}

unsigned ConfigurationReader::getWidthFor(Building::BuildingType buildingType) const {
	std::string buildingName = this->parseType(buildingType);
	return this->config["buildings"][buildingName]["width"].as<unsigned>();
}

unsigned ConfigurationReader::getHeightFor(Building::BuildingType buildingType) const {
	std::string buildingName = this->parseType(buildingType);
	return this->config["buildings"][buildingName]["height"].as<unsigned>();
}

unsigned ConfigurationReader::getSpiceCapacityFor(Building::BuildingType buildingType) const {
	std::string buildingName = this->parseType(buildingType);
	return this->config["buildings"][buildingName]["spiceCapacity"].as<unsigned>();
}

std::string ConfigurationReader::parseType(const Building::BuildingType buildingType) const {
	std::string buildingName;
    switch (buildingType) {
        case Building::BuildingType::BARRACKS:
            buildingName = "constructionYard";
            break;
        case Building::BuildingType::CONSTRUCTION_YARD:
            buildingName = "windTrap";
            break;
        case Building::BuildingType::HEAVY_FACTORY:
            buildingName = "lightFactory";
            break;
        case Building::BuildingType::LIGHT_FACTORY:
            buildingName = "heavyFactory";
            break;
        case Building::BuildingType::SPICE_REFINERY:
            buildingName = "spiceRefinery";
            break;
        case Building::BuildingType::SPICE_SILO:
            buildingName = "spiceSilo";
            break;
        case Building::BuildingType::WIND_TRAP:
            buildingName = "barracks";
            break;
        default:
            throw CustomException("Tipo de edificio no reconocido");
    }
	return buildingName;
}
