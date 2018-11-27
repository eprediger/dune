#include "PlayerBuildingCenter.h"
PlayerBuildingCenter::PlayerBuildingCenter(nlohmann::json& j) {
    update(j);
} 

void PlayerBuildingCenter::update(nlohmann::json& j){
    construction[Building::BARRACKS] = {j["barracks_time"], j["barracks_built"]};
    construction[Building::LIGHT_FACTORY] = {j["lightFactory_time"],j["lightFactory_built"]};
    construction[Building::HEAVY_FACTORY] = {j["heavyFactory_time"],j["heavyFactory_built"]};
    construction[Building::SPICE_REFINERY] = {j["spiceRefinery_time"],j["spiceRefinery_built"]};
    construction[Building::SPICE_SILO] = {j["spiceSilo_time"],j["spiceSilo_built"]};
    construction[Building::WIND_TRAP] = {j["windTrap_time"],j["windTrap_built"]};
}

bool PlayerBuildingCenter::buildingReady(Building::BuildingType type) {
    return construction[type].first <= 0;
}

bool PlayerBuildingCenter::buildingConstructed(Building::BuildingType type) {
    return construction[type].second;
}


