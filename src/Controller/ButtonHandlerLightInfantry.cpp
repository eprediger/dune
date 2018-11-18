#include "ButtonHandlerLightInfantry.h"
#include "../View/UnitViewFactory.h"
#include "../Model/GlobalConfig.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerLightInfantry::ButtonHandlerLightInfantry(Model &model, GameView &view) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/linfantry.gif"), model, view) {
}

ButtonHandlerLightInfantry::~ButtonHandlerLightInfantry() {}

void ButtonHandlerLightInfantry::execute() {
	LightInfantry& newUnit = model.createLightInfantry(500, 500, GameHandler::actual_player);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}

bool ButtonHandlerLightInfantry::canBeEnabled() {
	return (((model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.lightInfantryCost)) &&
	        (model.getPlayer(GameHandler::actual_player).hasBuilding(Building::BARRACKS)));
}

bool ButtonHandlerLightInfantry::finishAction() {
	return (!this->model.getPlayer(GameHandler::actual_player).trainingCenter->isTrainingLightInfantry());
}