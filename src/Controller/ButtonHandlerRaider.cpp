#include "ButtonHandlerRaider.h"
#include "../View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerRaider::ButtonHandlerRaider(Model &model, GameView &view) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/raider.gif",
			GlobalConfig.raiderConstructionTime),
	model, view) {
}

ButtonHandlerRaider::~ButtonHandlerRaider() {}

void ButtonHandlerRaider::execute() {
	Raider& newUnit = model.createRaider(500, 500, GameHandler::actual_player);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}

bool ButtonHandlerRaider::canBeEnabled() {
	return (((model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.raiderCost)) &&
	        (model.getPlayer(GameHandler::actual_player).hasBuilding(Building::LIGHT_FACTORY)));
}

bool ButtonHandlerRaider::finishAction() {
	return (!this->model.getPlayer(GameHandler::actual_player).trainingCenter->isTrainingRaider());
}