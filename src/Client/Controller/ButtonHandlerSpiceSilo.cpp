#include "ButtonHandlerSpiceSilo.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerSpiceSilo::ButtonHandlerSpiceSilo(Player& player, GameView &view,
    BuildingConstructor& constructor, CommunicationQueue& queue) :
    ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/silo.gif",
                                            GameConfiguration::getConfig().buildingConstructionTime),
                  player, view, queue,GameConfiguration::getConfig().buildingConstructionTime),
    constructor(constructor) {}

ButtonHandlerSpiceSilo::~ButtonHandlerSpiceSilo() {}

void ButtonHandlerSpiceSilo::execute() {
    nlohmann::json msg;
    msg["method"] = "beginConstruction";
    msg["args"]["player_id"] = player.getId();
    msg["args"]["building_type"] = Building::SPICE_SILO;
    queue.enqueue(msg);
    player.buildingCenter->beginConstruction(Building::SPICE_SILO);
    this->update();
}

bool ButtonHandlerSpiceSilo::canBeEnabled() {
    return (player.hasResourcesFor(Building::SPICE_SILO));
}

bool ButtonHandlerSpiceSilo::finishAction() {
	buttonView.update(((time - player.buildingCenter->remainingTime(Building::SPICE_SILO)) * 100) / time);  
    return player.buildingCenter->buildingReady(Building::SPICE_SILO);
}

void ButtonHandlerSpiceSilo::executeReady() {
    constructor.building = Building::SPICE_SILO;
    constructor.cost = GameConfiguration::getConfig().spiceSiloCost;
    constructor.width = GameConfiguration::getConfig().spiceSiloWidth;
    constructor.height = GameConfiguration::getConfig().spiceSiloHeight;
    constructor.on = true;
}

bool ButtonHandlerSpiceSilo::finishReady() {
    return player.buildingCenter->buildingConstructed(Building::SPICE_SILO);
}
