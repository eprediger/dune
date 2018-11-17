#include "ButtonHandlerSpiceRefinery.h"
#include "../View/BuildingViewFactory.h"
#include <iostream>

ButtonHandlerSpiceRefinery::ButtonHandlerSpiceRefinery(Model &model, GameView &view) :
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/refinery.jpg"), model, view) {
}

ButtonHandlerSpiceRefinery::~ButtonHandlerSpiceRefinery() {}

void ButtonHandlerSpiceRefinery::execute() {
	SpiceRefinery& newBuilding = model.createSpiceRefinery(500, 500, 0);
	view.addBuildingView(BuildingViewFactory::createBuildingView(newBuilding, view.getWindow()));
}

bool ButtonHandlerSpiceRefinery::canBeEnabled() {
    return (this->model.getPlayer(0).gold >= GlobalConfig.spiceRefineryCost);
}
