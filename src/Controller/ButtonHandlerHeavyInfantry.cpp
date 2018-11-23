#include "ButtonHandlerHeavyInfantry.h"
#include "../View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHeavyInfantry::ButtonHandlerHeavyInfantry(Model &model, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/hinfantry.gif",
                                            GlobalConfig.heavyInfantryTrainingTime),
                      model, view, queue) {
}

ButtonHandlerHeavyInfantry::~ButtonHandlerHeavyInfantry() {}

void ButtonHandlerHeavyInfantry::execute() {
	HeavyInfantry& newUnit = model.createHeavyInfantry(500, 500, GameHandler::actual_player);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit,view.getRocketViews(), view.getWindow()));
}

bool ButtonHandlerHeavyInfantry::canBeEnabled() {
	return (((model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.heavyInfantryCost)) &&
	        (model.getPlayer(GameHandler::actual_player).hasBuilding(Building::BARRACKS)));
}

bool ButtonHandlerHeavyInfantry::finishAction() {
	return !(this->model.getPlayer(GameHandler::actual_player).trainingCenter->isTrainingHeavyInfantry());
}
