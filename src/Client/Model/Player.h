#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player;

#include "Model/Buildings/Building.h"
//#include "Model/Buildings/ConstructionYard.h"
#include "PlayerTrainingCenter.h"
#include "PlayerBuildingCenter.h"
#include <vector>
#include <string>
#include <functional>
#include <nlohmann/json.hpp>

class Player {
private:
    int id;
    std::string house;
    std::vector<Building*> buildings;

public:
    int generatedEnergy;
    int consumedEnergy;
    int gold;
    int gold_limit;
    PlayerTrainingCenter* trainingCenter;
    PlayerBuildingCenter* buildingCenter;

    explicit Player(nlohmann::json& j);
    void update(nlohmann::json& j);
    int& getId();
    std::string& getHouse();
    bool operator==(const Player& other) const;

    void sellBuilding(Building* building);

    bool hasBuilding(Building::BuildingType type);

    void addBuilding(Building* building);
    void cleanDeadBuildings();

    int getGoldLimit();
};

#endif  // __PLAYER_H__
