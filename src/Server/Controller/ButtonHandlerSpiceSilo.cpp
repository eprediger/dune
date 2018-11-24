#include "ButtonHandlerSpiceSilo.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerSpiceSilo::ButtonHandlerSpiceSilo(Model &model, GameView &view,
            BuildingConstructor& constructor, CommunicationQueue& queue) :
        ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/silo.gif",
                                                GlobalConfig.buildingConstructionTime),
                      model, view, queue),
    constructor(constructor) {}

ButtonHandlerSpiceSilo::~ButtonHandlerSpiceSilo() {}

void ButtonHandlerSpiceSilo::execute() {
    nlohmann::json msg;
    msg["method"] = "beginConstruction";
    msg["args"]["player"] = GameHandler::actual_player;
    msg["args"]["building_type"] = Building::SPICE_SILO;
    queue.enqueue(msg);
}

bool ButtonHandlerSpiceSilo::canBeEnabled() {
    return (this->model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.spiceSiloCost);
}

bool ButtonHandlerSpiceSilo::finishAction() {
    return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingReady(Building::SPICE_SILO);
}

void ButtonHandlerSpiceSilo::executeReady() {
    constructor.building = Building::SPICE_SILO;
    constructor.cost = GlobalConfig.spiceSiloCost;
    constructor.width = GlobalConfig.spiceSiloSpicWidth;
    constructor.height = GlobalConfig.spiceSiloSpicHeight;
    constructor.on = true;
}

bool ButtonHandlerSpiceSilo::finishReady() {
    return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingConstructed(Building::SPICE_SILO);
}
