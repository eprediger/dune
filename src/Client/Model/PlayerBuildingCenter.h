#ifndef __PLAYERBUILDINGCENTER_H__
#define __PLAYERBUILDINGCENTER_H__

#include "Buildings/Building.h"
#include <map>
#include <utility>
#include <nlohmann/json.hpp>

class PlayerBuildingCenter {
public:
    PlayerBuildingCenter(nlohmann::json& j);
    bool buildingReady(Building::BuildingType type);
    bool buildingConstructed(Building::BuildingType type);

    void update(nlohmann::json& j);
private:
    std::map<Building::BuildingType,std::pair<int, bool>> construction;
};

#endif //DUNE_PLAYERBUILDINGCENTER_H
