#include "BuildingConstructor.h"
#include "Model/Buildings/Barracks.h"
#include "Model/Buildings/LightFactory.h"
#include "Model/Buildings/HeavyFactory.h"
#include "Model/Buildings/SpiceRefinery.h"
#include "Model/Buildings/SpiceSilo.h"
#include "View/GameView.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"

#include <nlohmann/json.hpp>

BuildingConstructor::BuildingConstructor(Model& model, Player& player, GameView& view, CommunicationQueue& queue):
    model(model),
    player(player),
    view(view),
    queue(queue),
    on(false),
    pos(0, 0),
    building(),
    width(0),
    height(0),
    cost(0) {
    view.addBuildingConstructorView(this);
}

bool BuildingConstructor::canWeBuild() {
    pos = model.getMap().getCornerPosition(pos);
    return (on && model.canWeBuild(pos, width, height, cost, player));
}

void BuildingConstructor::build() {
    if (on) {
        if (model.canWeBuild(pos, width, height, cost, player)) {
            nlohmann::json msg;
            msg["args"]["x"] = pos.x;
            msg["args"]["y"] = pos.y;
            msg["args"]["player_id"] = player.getId();
            switch (building) {
            case Building::BARRACKS:
            {
                msg["method"] = "createBarracks";
                queue.enqueue(msg);
                break;
            }
            case Building::LIGHT_FACTORY:
            {
                msg["method"] = "createLightFactory";
                queue.enqueue(msg);
                break;
            }
            case Building::HEAVY_FACTORY:
            {
                msg["method"] = "createHeavyFactory";
                queue.enqueue(msg);
                break;
            }
            case Building::SPICE_REFINERY:
            {
                msg["method"] = "createSpiceRefinery";
                queue.enqueue(msg);
                break;
            }
            case Building::SPICE_SILO:
            {
                msg["method"] = "createSpiceSilo";
                queue.enqueue(msg);
                break;
            }
            case Building::WIND_TRAP:
            {
                msg["method"] = "createWindTrap";
                queue.enqueue(msg);
            }
            default:
                break;
            }
            on = false;
        }
    }
}

Player& BuildingConstructor::getPlayer() {
    return player;
}
