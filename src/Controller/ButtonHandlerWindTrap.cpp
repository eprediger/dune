#include "ButtonHandlerWindTrap.h"
#include "../View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerWindTrap::ButtonHandlerWindTrap(Model& model, GameView& view, BuildingConstructor& constructor) :
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/windtrap.gif"), model, view)
    ,constructor(constructor) {
    if (this->canBeEnabled()) {
        this->setState(State::ENABLED);
    }
}

ButtonHandlerWindTrap::~ButtonHandlerWindTrap() {}

void ButtonHandlerWindTrap::execute() {
	constructor.building = Building::WIND_TRAP;
    constructor.cost = GlobalConfig.windTrapCost;
    constructor.width = GlobalConfig.windTrapWidth;
    constructor.height = GlobalConfig.windTrapHeight;
    constructor.on = true;
}

bool ButtonHandlerWindTrap::canBeEnabled() {
    return (this->model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.windTrapCost);
}

bool ButtonHandlerWindTrap::finishAction() {
    return true;
}
