#include "ButtonHandlerHarvester.h"
#include "../View/UnitViewFactory.h"
#include <iostream>

ButtonHandlerHarvester::ButtonHandlerHarvester(Model &model, GameView &view) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/harvest.gif"), model, view) {
}

ButtonHandlerHarvester::~ButtonHandlerHarvester() {}

void ButtonHandlerHarvester::execute() {
	Harvester& newUnit = model.createHarvester(500, 500, 0);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}

bool ButtonHandlerHarvester::canBeEnabled() {
	return (((model.getPlayer(0).gold >= GlobalConfig.harvesterCost)) &&
	        (model.getPlayer(0).hasBuilding(Building::HEAVY_FACTORY)));
}
