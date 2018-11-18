#include "ButtonHandlerHeavyInfantry.h"
#include "../View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHeavyInfantry::ButtonHandlerHeavyInfantry(Model &model, GameView &view) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/hinfantry.gif"), model, view) {
}

ButtonHandlerHeavyInfantry::~ButtonHandlerHeavyInfantry() {}

void ButtonHandlerHeavyInfantry::execute() {
	HeavyInfantry& newUnit = model.createHeavyInfantry(500, 500, GameHandler::actual_player);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}

bool ButtonHandlerHeavyInfantry::canBeEnabled() {
	return (((model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.heavyInfantryCost)) &&
	        (model.getPlayer(GameHandler::actual_player).hasBuilding(Building::BARRACKS)));
}
