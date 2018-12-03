#include "PlayerBuildingCenter.h"
#include "Buildings/Building.h"

PlayerBuildingCenter::PlayerBuildingCenter(nlohmann::json& j): m() {
    update(j);
}

void PlayerBuildingCenter::update(nlohmann::json& j) {
    m.lock();
    for (unsigned i = 0; i < j["buildings"].size(); i++) {
        construction[j["buildings"][i]].first = j["time"][i];
        construction[j["buildings"][i]].second = false;
    }
    for (auto type : j["built"]) {
        construction[type].second = true;
    }
    m.unlock();
}

void PlayerBuildingCenter::beginConstruction(Building::BuildingType type) {
    construction[type].first = 1;
}

bool PlayerBuildingCenter::buildingReady(Building::BuildingType type) {
    return construction[type].first <= 0;
}

bool PlayerBuildingCenter::buildingConstructed(Building::BuildingType type) {
    return construction[type].second;
}

int PlayerBuildingCenter::remainingTime(Building::BuildingType buildingType) {
    m.lock();
    int ans = this->construction.at(buildingType).first;
    m.unlock();
    return ans;
}
