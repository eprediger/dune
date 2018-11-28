#include "PlayerBuildingCenter.h"
#include "Buildings/Building.h"
PlayerBuildingCenter::PlayerBuildingCenter(nlohmann::json& j) {
    update(j);
} 
#include <iostream>
void PlayerBuildingCenter::update(nlohmann::json& j){ 
    for (int i = 0; i<j["buildings"].size();i++){
        construction[j["buildings"][i]].first = j["time"][i];
        construction[j["buildings"][i]].second = false;
    }
    for (auto type: j["built"]){
        construction[type].second = true;
    }
}

void PlayerBuildingCenter::beginConstruction(Building::BuildingType type){
    construction[type].first = 1;
}

bool PlayerBuildingCenter::buildingReady(Building::BuildingType type) {
    return construction[type].first <= 0;
}

bool PlayerBuildingCenter::buildingConstructed(Building::BuildingType type) {
    return construction[type].second;
}


