#ifndef __BUILDING_CONSTRUCTOR_H__
#define __BUILDING_CONSTRUCTOR_H__

#include "../Model/Buildings/Building.h"
#include "../Model/Model.h"
#include "../Model/Player.h"
#include "../View/GameView.h"

#include <json.hpp>

class GameView;

class BuildingConstructor {
private:
    Model& model;
    Player& player;
    GameView& view;
    std::deque<nlohmann::json>& send_queue;

public:
    bool on;
    Position pos;
    Building::BuildingType building;
    int width, height;
    int cost;

    BuildingConstructor(Model& model, Player& player, GameView& view, std::deque<nlohmann::json>& send_queue);
    void build();
    bool canWeBuild();
    Player& getPlayer();
};

#endif
