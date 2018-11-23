#ifndef __GAMEINTERFACE_H__
#define __GAMEINTERFACE_H__


#include <json.hpp>
#include "Model/Model.h"
#include "View/GameView.h"

class GameInterface {
public:
    GameInterface(Model &model, GameView &view);
    void execute(nlohmann::json json);
private:
    Model& model;
    GameView& view;

    void createWindTrap(int x, int y, int player_id);
    void createBarracks(int x, int y, int player_id);
    void createLightFactory(int x, int y, int player_id);
    void createHeavyFactory(int x, int y, int player_id);
    void createSpiceRefinery(int x, int y, int player_id);
    void createSpiceSilo(int x, int y, int player_id);

    void beginConstruction(int player_id, Building::BuildingType type);
};


#endif //__GAMEINTERFACE_H__
