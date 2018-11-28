#ifndef __GAMEINTERFACE_H__
#define __GAMEINTERFACE_H__

#include <nlohmann/json.hpp>
#include "Model/Model.h"

class GameInterface {
public:
    GameInterface(Model &model);
    void execute(nlohmann::json json);

private:
    Model& model;

    void createWindTrap(int x, int y, int player_id);
    void createBarracks(int x, int y, int player_id);
    void createLightFactory(int x, int y, int player_id);
    void createHeavyFactory(int x, int y, int player_id);
    void createSpiceRefinery(int x, int y, int player_id);
    void createSpiceSilo(int x, int y, int player_id);

    void beginConstruction(int player_id, Building::BuildingType type);

    void createHarvester(int player_id);
    void createHeavyInfantry(int player_id);
    void createLightInfantry(int player_id);
    void createRaider(int player_id);
    void createTank(int player_id);
    void createTrike(int player_id);

    void sellBuilding(int player_id, int building_id);

    void setActionOnPosition(int player_id, int unit_id, int x, int y);
};

#endif //__GAMEINTERFACE_H__
