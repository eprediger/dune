#include "ButtonHandlerHeavyFactory.h"
#include "../View/BuildingViewFactory.h"
#include <iostream>

ButtonHandlerHeavyFactory::ButtonHandlerHeavyFactory(Model &model, GameView &view) :
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/heavy-factory.gif"), model, view) {
}

ButtonHandlerHeavyFactory::~ButtonHandlerHeavyFactory() {}

void ButtonHandlerHeavyFactory::execute() {
	HeavyFactory& newBuilding = model.createHeavyFactory(500, 500, 0);
	view.addBuildingView(BuildingViewFactory::createBuildingView(newBuilding, view.getWindow()));
}

bool ButtonHandlerHeavyFactory::canBeEnabled() {
    return (this->model.getPlayer(0).gold >= GlobalConfig.heavyFactoryCost);
}
