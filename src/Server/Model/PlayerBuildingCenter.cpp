#include "PlayerBuildingCenter.h"
#include "Buildings/Building.h"
PlayerBuildingCenter::PlayerBuildingCenter():
    construction(),
    serialization(),
    news(false)
{
    serialization["buildings"].push_back(Building::BARRACKS);
    serialization["time"].push_back(0);
    serialization["buildings"].push_back(Building::LIGHT_FACTORY);
    serialization["time"].push_back(0);
    serialization["buildings"].push_back(Building::HEAVY_FACTORY);
    serialization["time"].push_back(0);
    serialization["buildings"].push_back(Building::SPICE_REFINERY);
    serialization["time"].push_back(0);
    serialization["buildings"].push_back(Building::SPICE_SILO);
    serialization["time"].push_back(0);
    serialization["buildings"].push_back(Building::WIND_TRAP);
    serialization["time"].push_back(0);
}

#include <iostream>

void PlayerBuildingCenter::newConstruct(Building::BuildingType type) {
    switch (type) {
        case Building::BARRACKS:
        {
            std::cout<<"begin barracks\n";
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
            std::cout<<"begin windtra\n";
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

#include <iostream>
void PlayerBuildingCenter::construct() {
    if (!news){
        serialization["built"].clear();
        serialization["buildings"].clear();
        serialization["time"].clear();
    }
    for (auto itr = construction.begin(); itr != construction.end(); ++itr){
        if (itr->second.first > 0){
            news = true;
            itr->second.first -= 1;
            if (itr->second.first == 0)
                std::cout<<"fin building\n";
            serialization["buildings"].push_back(itr->first);
            serialization["time"].push_back(itr->second.first);
        }
    }
}

bool PlayerBuildingCenter::buildingConstructed(Building::BuildingType type) {
    return construction[type].second;
}

void PlayerBuildingCenter::build(Building::BuildingType type) {
    if (!news){
        serialization["built"].clear();
        serialization["buildings"].clear();
        serialization["time"].clear();
    }
    news = true;
    construction[type].second = true;
    serialization["built"].push_back(type);
}

nlohmann::json& PlayerBuildingCenter::getSerialization(){
    news = false;
    return this->serialization;
}