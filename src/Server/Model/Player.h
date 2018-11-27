#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Buildings/Building.h" 
#include "Buildings/ConstructionYard.h" 
#include "PlayerTrainingCenter.h"
#include "PlayerBuildingCenter.h"
#include <vector>
#include <string>
#include <functional>

class Map;
class Unit;

class Player {
private:
    int id;
    std::string house;
    nlohmann::json serialization;

public:     // El cliente sólo debería tenerse a su propio player disponible
    int generatedEnergy; // Se sumara durante el constructor de la trampa de viento y se restara durante su destructor
    int consumedEnergy; // se suma cuando se construye un edificio, se resta cuando se destruye
    int gold;   // Se restara durante los constructores
    int gold_limit; // Se sumara dentro del constructor de la refineria o el silo
    PlayerTrainingCenter* trainingCenter;
    PlayerBuildingCenter* buildingCenter;

    std::vector<Building*> buildings;
    ConstructionYard* construction_yard;

    std::vector<Unit*>& getTrainedUnits(Map& map);

    explicit Player(int id, ConstructionYard &construction_yard);

    void addGold(int gold_to_add);
    void subGold(int gold_to_sub);
    //void addEnergy(int energy_to_add);
    //void subEnergy(int energy_to_sub);

//    void addUnit(Unit* unit);
    void addBuilding(Building* building);
//    void cleanUnit(Unit* unit);
    void cleanDeadBuildings();

    Building * getClosestBuilding(Position pos, Building::BuildingType type);
//    bool hasBuilding(const Building* building);

//    bool hasUnit(Unit *unit);
    bool hasBuilding(Building& building);
    bool hasBuilding(Building::BuildingType buildingType);

    ConstructionYard& getConstructionYard();

    bool lose();

    void trainUnits();
    void constructBuildings();

    int& getId();
    std::string& getHouse();

    bool operator==(const Player& other) const;

    void sellBuilding(Building* building);

    nlohmann::json& getSerialization();
};

#endif  // __PLAYER_H__
