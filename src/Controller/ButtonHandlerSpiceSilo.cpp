#include "ButtonHandlerSpiceSilo.h"
#include "../View/BuildingViewFactory.h"
#include <iostream>

ButtonHandlerSpiceSilo::ButtonHandlerSpiceSilo(Model &model, GameView &view) :
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/silo.gif"), model, view) {
}

ButtonHandlerSpiceSilo::~ButtonHandlerSpiceSilo() {}

void ButtonHandlerSpiceSilo::execute() {
	SpiceSilo& newBuilding = model.createSpiceSilo(500, 500, 0);
	view.addBuildingView(BuildingViewFactory::createBuildingView(newBuilding, view.getWindow()));
}

bool ButtonHandlerSpiceSilo::canBeEnabled() {
    return (this->model.getPlayer(0).gold >= GlobalConfig.spiceSiloCost);
}
