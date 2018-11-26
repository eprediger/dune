#include "PlayerBuildingCenter.h"
PlayerBuildingCenter::PlayerBuildingCenter() {
    construction[Building::BARRACKS] = {GlobalConfig.buildingConstructionTime, false};
    construction[Building::LIGHT_FACTORY] = {GlobalConfig.buildingConstructionTime, false};
    construction[Building::HEAVY_FACTORY] = {GlobalConfig.buildingConstructionTime, false};
    construction[Building::SPICE_REFINERY] = {GlobalConfig.buildingConstructionTime, false};
    construction[Building::SPICE_SILO] = {GlobalConfig.buildingConstructionTime, false};
    construction[Building::WIND_TRAP] = {GlobalConfig.buildingConstructionTime, false};
}


void PlayerBuildingCenter::newConstruct(Building::BuildingType type) {
    switch (type) {
        case Building::BARRACKS:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            break;
        }
        case Building::LIGHT_FACTORY:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            break;
        }
        case Building::HEAVY_FACTORY:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            break;
        }
        case Building::SPICE_REFINERY:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            break;
        }
        case Building::SPICE_SILO:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            break;
        }
        case Building::WIND_TRAP:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            break;
        }
        default:
            break;
    }
}

bool PlayerBuildingCenter::buildingReady(Building::BuildingType type) {
    return construction[type].first <= 0;
}

void PlayerBuildingCenter::construct() {
    for (auto itr = construction.begin(); itr != construction.end(); ++itr){
        itr->second.first-= itr->second.first > 0 ? 1 : 0;
    }
}

bool PlayerBuildingCenter::buildingConstructed(Building::BuildingType type) {
    return construction[type].second;
}

void PlayerBuildingCenter::build(Building::BuildingType type) {
    construction[type].second = true;
}


