#include "ButtonHandlerSpiceRefinery.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerSpiceRefinery::ButtonHandlerSpiceRefinery(Player& player, GameView &view,
    BuildingConstructor& constructor, CommunicationQueue& queue) :
    ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/refinery.jpg",
                                            GameConfiguration::getConfig().buildingConstructionTime),
                  player, view, queue, GameConfiguration::getConfig().buildingConstructionTime),
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
    return (this->player.hasResourcesFor(Building::SPICE_REFINERY));
}

bool ButtonHandlerSpiceRefinery::finishAction() {
	buttonView.update(((time - player.buildingCenter->remainingTime(Building::SPICE_REFINERY)) * 100) / time);  
    return player.buildingCenter->buildingReady(Building::SPICE_REFINERY); 
}

void ButtonHandlerSpiceRefinery::executeReady() {
    constructor.building = Building::SPICE_REFINERY;
    constructor.cost = GameConfiguration::getConfig().spiceRefineryCost;
    constructor.width = GameConfiguration::getConfig().spiceRefineryWidth;
    constructor.height = GameConfiguration::getConfig().spiceRefineryHeight;
    constructor.on = true;
}

bool ButtonHandlerSpiceRefinery::finishReady() {
    return player.buildingCenter->buildingConstructed(Building::SPICE_REFINERY);
}
