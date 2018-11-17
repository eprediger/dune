#include "ButtonHandlerWindTrap.h"
#include "../View/BuildingViewFactory.h"
#include <iostream>

ButtonHandlerWindTrap::ButtonHandlerWindTrap(Model &model, GameView &view) :
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/windtrap.gif"), model, view) {}

ButtonHandlerWindTrap::~ButtonHandlerWindTrap() {}

void ButtonHandlerWindTrap::execute() {
	WindTrap& newBuilding = model.createWindTrap(500, 500, 0);
	view.addBuildingView(BuildingViewFactory::createBuildingView(newBuilding, view.getWindow()));
}
