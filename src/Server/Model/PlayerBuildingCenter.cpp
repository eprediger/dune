#include "PlayerBuildingCenter.h"

PlayerBuildingCenter::PlayerBuildingCenter():
    construction(),
    serialization()
{
    serialization["building_barracks"] = false;
    serialization["barracks_time"] = 0;
    serialization["barracks_built"] = false;
    serialization["building_lightFactory"] = false;
    serialization["lightFactory_time"] = 0;
    serialization["lightFactory_built"] = false;
    serialization["building_heavyFactory"] = false;
    serialization["heavyFactory_time"] = 0;
    serialization["heavyFactory_built"] = false;
    serialization["building_spiceRefinery"] = false;
    serialization["spiceRefinery_time"] = 0;
    serialization["spiceRefinery_built"] = false;
    serialization["building_spiceSilo"] = false;
    serialization["spiceSilo_time"] = 0;
    serialization["spiceSilo_built"] = false;
    serialization["building_windTrap"] = false;
    serialization["windTrap_time"] = 0;
    serialization["windTrap_built"] = false;
}

void PlayerBuildingCenter::newConstruct(Building::BuildingType type) {
    switch (type) {
        case Building::BARRACKS:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            serialization["building_barracks"] = true;
            serialization["barracks_time"] = GlobalConfig.buildingConstructionTime;
            break;
        }
        case Building::LIGHT_FACTORY:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            serialization["building_lightFactory"] = true;
            serialization["lightFactory_time"] = GlobalConfig.buildingConstructionTime;
            break;
        }
        case Building::HEAVY_FACTORY:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            serialization["building_heavyFactory"] = true;
            serialization["heavyFactory_time"] = GlobalConfig.buildingConstructionTime;
            break;
        }
        case Building::SPICE_REFINERY:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            serialization["building_spiceRefinery"] = true;
            serialization["spiceRefinery_time"] = GlobalConfig.buildingConstructionTime;
            break;
        }
        case Building::SPICE_SILO:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            serialization["building_spiceSilo"] = true;
            serialization["spiceSilo_time"] = GlobalConfig.buildingConstructionTime;
            break;
        }
        case Building::WIND_TRAP:
        {
            construction[type].first = GlobalConfig.buildingConstructionTime;
            construction[type].second = false;
            serialization["building_windTrap"] = true;
            serialization["windTrap_time"] = GlobalConfig.buildingConstructionTime;
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
        if (itr->second.first > 0){
            itr->second.first -= 1;
            switch (itr->first){
                case Building::BARRACKS:
                    serialization["barracks_time"] = itr->second.first;
                    break;
                case Building::LIGHT_FACTORY:
                    serialization["lightFactory_time"] = itr->second.first;
                    break;
                case Building::HEAVY_FACTORY:
                    serialization["heavyFactory_time"] =  itr->second.first;
                    break;
                case Building::SPICE_REFINERY:
                    serialization["spiceRefinery_time"] = itr->second.first;
                    break;
                case Building::SPICE_SILO:
                    serialization["spiceSilo_time"] =  itr->second.first;
                    break;
                case Building::WIND_TRAP:
                    serialization["windTrap_time"] =  itr->second.first;
                    break;
                default:
                    break;
            }
        }
    }
}

bool PlayerBuildingCenter::buildingConstructed(Building::BuildingType type) {
    return construction[type].second;
}

void PlayerBuildingCenter::build(Building::BuildingType type) {
    construction[type].second = true;
    switch (type){
        case Building::BARRACKS:
            serialization["barracks_built"] = true;
            serialization["building_barracks"] = false;
            break;
        case Building::LIGHT_FACTORY:
            serialization["lightFactory_built"] = true;
            serialization["building_lightFactory"] = false;
            break;
        case Building::HEAVY_FACTORY:
            serialization["heavyFactory_built"] =  true;
            serialization["building_heavyFactory"] = false;
            break;
        case Building::SPICE_REFINERY:
            serialization["spiceRefinery_built"] = true;
            serialization["building_spiceRefinery"] = false;
            break;
        case Building::SPICE_SILO:
            serialization["spiceSilo_built"] =  true;
            serialization["building_spiceSilo"] = false;
            break;
        case Building::WIND_TRAP:
            serialization["windTrap_built"] =  true;
            serialization["building_windTrap"] = false;
            break;
        default:
            break;
        
    }
}

nlohmann::json& PlayerBuildingCenter::getSerialization(){
    return this->serialization;
}