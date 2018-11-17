#include "ButtonHandlerLightInfantry.h"
#include "../View/UnitViewFactory.h"
#include "../Model/GlobalConfig.h"
#include <iostream>

ButtonHandlerLightInfantry::ButtonHandlerLightInfantry(Model &model, GameView &view) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/linfantry.gif"), model, view) {
}

ButtonHandlerLightInfantry::~ButtonHandlerLightInfantry() {}

void ButtonHandlerLightInfantry::execute() {
	LightInfantry& newUnit = model.createLightInfantry(500, 500, 0);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}

bool ButtonHandlerLightInfantry::canBeEnabled() {
	return (((model.getPlayer(0).gold >= GlobalConfig.lightInfantryCost)) &&
	        (model.getPlayer(0).hasBuilding(Building::BARRACKS)));
}
