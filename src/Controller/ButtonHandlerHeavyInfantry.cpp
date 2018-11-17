#include "ButtonHandlerHeavyInfantry.h"
#include "../View/UnitViewFactory.h"
#include <iostream>

ButtonHandlerHeavyInfantry::ButtonHandlerHeavyInfantry(Model &model, GameView &view) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/hinfantry.gif"), model, view) {
}

ButtonHandlerHeavyInfantry::~ButtonHandlerHeavyInfantry() {}

void ButtonHandlerHeavyInfantry::execute() {
	HeavyInfantry& newUnit = model.createHeavyInfantry(500, 500, 0);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}

bool ButtonHandlerHeavyInfantry::canBeEnabled() {
	return (((model.getPlayer(0).gold >= GlobalConfig.heavyInfantryCost)) &&
	        (model.getPlayer(0).hasBuilding(Building::BARRACKS)));
}
