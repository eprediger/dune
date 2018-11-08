#ifndef __Player_H__
#define __Player_H__

#include <vector>
#include "Buildings/Building.h"

class Player {
private:
    int id;
    int energy; //Se sumara durante el constructor de la trampa de viento y se restara durante su destructor
    int gold; //Se restara durante los constructores
    int gold_limit; //Se sumara dentro del constructor de la refineria o el silo

    std::vector<Building*> buildings;
public:
    Player(int id);

    void addGold(int gold_to_add);
    void subGold(int gold_to_sub);
    void addEnergy(int energy_to_add);
    void subEnergy(int energy_to_sub);

//    void addUnit(Unit* unit);
    void addBuilding(Building* building);
//    void cleanUnit(Unit* unit);
    void cleanBuilding(Building* building);

//    bool hasUnit(Unit *unit);
    bool hasBuilding(Building* building);

    bool operator==(const Player& other) const;

};

#endif //__Player_H__
