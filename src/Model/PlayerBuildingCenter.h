#ifndef __PLAYERBUILDINGCENTER_H__
#define __PLAYERBUILDINGCENTER_H__

#include <map>
#include "Buildings/Building.h"

class PlayerBuildingCenter {
public:
    bool buildingReady(Building::BuildingType type);
    void newConstruct(Building::BuildingType type);
    void construct();
    void build(Building::BuildingType type);
    bool buildingConstructed(Building::BuildingType type);
private:
    std::map<Building::BuildingType,std::pair<int, bool>> construction;
};

#endif //DUNE_PLAYERBUILDINGCENTER_H
