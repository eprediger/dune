#include "ButtonHandlerTrike.h"
#include "../View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerTrike::ButtonHandlerTrike(Model &model, GameView &view) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/trike.jpg"), model, view) {
}

ButtonHandlerTrike::~ButtonHandlerTrike() {}

void ButtonHandlerTrike::execute() {
	Trike& newUnit = model.createTrike(500, 500, GameHandler::actual_player);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}

bool ButtonHandlerTrike::canBeEnabled() {
	return (((model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.trikeCost)) &&
	        (model.getPlayer(GameHandler::actual_player).hasBuilding(Building::LIGHT_FACTORY)));
}

bool ButtonHandlerTrike::finishAction() {
	return (!this->model.getPlayer(GameHandler::actual_player).trainingCenter->isTrainingTrike());
}