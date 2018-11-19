#include "ButtonHandlerSpiceRefinery.h"
#include "../View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerSpiceRefinery::ButtonHandlerSpiceRefinery(Model &model, GameView &view, BuildingConstructor& constructor) :
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/refinery.jpg", 0), model, view)
	,constructor(constructor)
	{}

ButtonHandlerSpiceRefinery::~ButtonHandlerSpiceRefinery() {}

void ButtonHandlerSpiceRefinery::execute() {
	constructor.building = Building::SPICE_REFINERY;
    constructor.cost = GlobalConfig.spiceRefineryCost;
    constructor.width = GlobalConfig.spiceRefinerySpicWidth;
    constructor.height = GlobalConfig.spiceRefinerySpicHeight;
    constructor.on = true;
}

bool ButtonHandlerSpiceRefinery::canBeEnabled() {
    return (this->model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.spiceRefineryCost);
}

bool ButtonHandlerSpiceRefinery::finishAction() {
	return true;
}
