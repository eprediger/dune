#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Buildings/Building.h"
#include "Buildings/ConstructionYard.h"
#include <vector>
#include <functional>

class Player {
private:
    int id;
    
public:     // El cliente sólo debería tenerse a su propio player disponible
    int generatedEnergy; // Se sumara durante el constructor de la trampa de viento y se restara durante su destructor
    int consumedEnergy; // se suma cuando se construye un edificio, se resta cuando se destruye
    int gold;   // Se restara durante los constructores
    int gold_limit; // Se sumara dentro del constructor de la refineria o el silo

    std::vector<Building*> buildings;
    ConstructionYard* construction_yard;

    explicit Player(int id);

    void addGold(int gold_to_add);
    void subGold(int gold_to_sub);
    //void addEnergy(int energy_to_add);
    //void subEnergy(int energy_to_sub);

//    void addUnit(Unit* unit);
    void addBuilding(Building* building);
//    void cleanUnit(Unit* unit);
    void cleanBuilding(Building* building);

    Building * getClosestBuilding(Position pos, Building::BuildingType type);

//    bool hasUnit(Unit *unit);
    bool hasBuilding(Building* building);

    bool lose();

    int& getId();

    bool operator==(const Player& other) const;
};

#endif  // __PLAYER_H__
