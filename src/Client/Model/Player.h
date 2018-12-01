#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player;

#include "Model/Buildings/Building.h"
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
    int generatedEnergy;
    int consumedEnergy;

public:
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

    bool hasBuilding(const Building::BuildingType type) const;

    void addBuilding(Building* building);
    void cleanDeadBuildings();

    int getGoldLimit() const;

    float getEnergyRatio() const;

    // Retorna true si el jugador tiene recursos
    // suficientes para el edificio buildingType
    bool hasResourcesFor(const Building::BuildingType buildingType) const;

    bool hasResourcesFor(const Unit::UnitType unitType) const;
};

#endif  // __PLAYER_H__
