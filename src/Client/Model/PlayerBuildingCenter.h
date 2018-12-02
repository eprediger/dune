#ifndef __PLAYERBUILDINGCENTER_H__
#define __PLAYERBUILDINGCENTER_H__

#include "Buildings/Building.h"
#include <map>
#include <utility>
#include <nlohmann/json.hpp>
#include <mutex>
class PlayerBuildingCenter {
public:
	explicit PlayerBuildingCenter(nlohmann::json& j);
	bool buildingReady(Building::BuildingType type);
	bool buildingConstructed(Building::BuildingType type);
	
	void beginConstruction(Building::BuildingType type);
	void update(nlohmann::json& j);

    int remainingTime(Building::BuildingType buildingType);

private:
	std::map<Building::BuildingType, std::pair<int, bool>> construction;
	std::mutex m;
};

#endif //DUNE_PLAYERBUILDINGCENTER_H
