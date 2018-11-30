#include "ButtonHandlerSpiceRefinery.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerSpiceRefinery::ButtonHandlerSpiceRefinery(Player& player, GameView &view,
    BuildingConstructor& constructor, CommunicationQueue& queue) :
    ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/refinery.jpg",
                                            GameConfiguration::getConfig().buildingConstructionTime),
                  player, view, queue),
    constructor(constructor) {}

ButtonHandlerSpiceRefinery::~ButtonHandlerSpiceRefinery() {}

void ButtonHandlerSpiceRefinery::execute() {
    nlohmann::json msg;
    msg["method"] = "beginConstruction";
    msg["args"]["player_id"] = player.getId();
    msg["args"]["building_type"] = Building::SPICE_REFINERY;
    queue.enqueue(msg);
    player.buildingCenter->beginConstruction(Building::SPICE_REFINERY);
}

bool ButtonHandlerSpiceRefinery::canBeEnabled() {
    return (this->player.gold >= GameConfiguration::getConfig().spiceRefineryCost);
}

bool ButtonHandlerSpiceRefinery::finishAction() {
    return player.buildingCenter->buildingReady(Building::SPICE_REFINERY);
}

void ButtonHandlerSpiceRefinery::executeReady() {
    constructor.building = Building::SPICE_REFINERY;
    constructor.cost = GameConfiguration::getConfig().spiceRefineryCost;
    constructor.width = GameConfiguration::getConfig().spiceRefinerySpicWidth;
    constructor.height = GameConfiguration::getConfig().spiceRefinerySpicHeight;
    constructor.on = true;
}

bool ButtonHandlerSpiceRefinery::finishReady() {
    return player.buildingCenter->buildingConstructed(Building::SPICE_REFINERY);
}
