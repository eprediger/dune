#ifndef __PLAYERBUILDINGCENTER_H__
#define __PLAYERBUILDINGCENTER_H__

#include "Model/Buildings/Building.h"
#include <map>
#include <utility>
#include <nlohmann/json.hpp>

class PlayerBuildingCenter {
public:
    PlayerBuildingCenter();
    bool buildingReady(Building::BuildingType type);
    void newConstruct(Building::BuildingType type);
    void construct();
    void build(Building::BuildingType type);
    bool buildingConstructed(Building::BuildingType type);
    nlohmann::json& getSerialization();
    bool news;
private:
    std::map<Building::BuildingType,std::pair<int, bool>> construction;
    nlohmann::json serialization; 
};

#endif //DUNE_PLAYERBUILDINGCENTER_H
