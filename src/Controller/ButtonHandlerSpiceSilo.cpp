#include "ButtonHandlerSpiceSilo.h"
#include "../View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerSpiceSilo::ButtonHandlerSpiceSilo(Model &model, GameView &view, BuildingConstructor& constructor) :
    ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/silo.gif",
                                            GlobalConfig.buildingConstructionTime),
                  model, view),
    constructor(constructor) {}

ButtonHandlerSpiceSilo::~ButtonHandlerSpiceSilo() {}

void ButtonHandlerSpiceSilo::execute() {
    model.getPlayer(GameHandler::actual_player).buildingCenter->newConstruct(Building::SPICE_SILO);
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
