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
public:     // El cliente sólo debería tenerse a su propio player disponible
    int generatedEnergy; // Se sumara durante el constructor de la trampa de viento y se restara durante su destructor
    int consumedEnergy; // se suma cuando se construye un edificio, se resta cuando se destruye
    int gold;   // Se restara durante los constructores
    int gold_limit; // Se sumara dentro del constructor de la refineria o el silo
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
};

#endif  // __PLAYER_H__
