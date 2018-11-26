#include "ButtonHandlerSpiceRefinery.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerSpiceRefinery::ButtonHandlerSpiceRefinery(Model &model, GameView &view,
            BuildingConstructor& constructor, CommunicationQueue& queue) :
        ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/refinery.jpg",
                                                GlobalConfig.buildingConstructionTime),
                      model, view, queue),
    constructor(constructor) {}

ButtonHandlerSpiceRefinery::~ButtonHandlerSpiceRefinery() {}

void ButtonHandlerSpiceRefinery::execute() {
    nlohmann::json msg;
    msg["method"] = "beginConstruction";
    msg["args"]["player"] = GameHandler::actual_player;
    msg["args"]["building_type"] = Building::SPICE_REFINERY;
    queue.enqueue(msg);
    model.getPlayer(GameHandler::actual_player).buildingCenter->newConstruct(Building::SPICE_REFINERY);
}

bool ButtonHandlerSpiceRefinery::canBeEnabled() {
    return (this->model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.spiceRefineryCost);
}

bool ButtonHandlerSpiceRefinery::finishAction() {
    return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingReady(Building::SPICE_REFINERY);
}

void ButtonHandlerSpiceRefinery::executeReady() {
    constructor.building = Building::SPICE_REFINERY;
    constructor.cost = GlobalConfig.spiceRefineryCost;
    constructor.width = GlobalConfig.spiceRefinerySpicWidth;
    constructor.height = GlobalConfig.spiceRefinerySpicHeight;
    constructor.on = true;
}

bool ButtonHandlerSpiceRefinery::finishReady() {
    return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingConstructed(Building::SPICE_REFINERY);
}
