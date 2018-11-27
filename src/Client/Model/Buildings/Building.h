#ifndef __BUILDING_H__
#define __BUILDING_H__

#include <vector>
#include "../../Position.h"
#include <nlohmann/json.hpp>

class Player;

class Building{
public:
    enum BuildingType {
        BARRACKS,
        CONSTRUCTION_YARD,
        HEAVY_FACTORY,
        LIGHT_FACTORY,
        SPICE_REFINERY,
        SPICE_SILO,
        WIND_TRAP
    };

    Building(nlohmann::json& j);

    virtual ~Building();


    bool is(BuildingType type);
    void setPlayer(Player* player);
    Player* getPlayer();

    void update(nlohmann::json& j);

    int getLife();
    int getInitialLife();
    Position& getPosition();

    Position& getClosestPosition(Position& position);

    bool isDead();

    const int width, height;
    const int id;
protected:
    int player_id;
    Player* player;
    int initial_life;
    int life;
    BuildingType key;
    std::vector<Position> all_positions;
};

#endif //__BUILDING_H__
