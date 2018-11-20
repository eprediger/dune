#include "PlayerBuildingCenter.h"

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
