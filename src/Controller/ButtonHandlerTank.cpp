#include "ButtonHandlerTank.h"
#include "../View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerTank::ButtonHandlerTank(Model &model, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/tank.gif",
                                            GlobalConfig.tankConstructionTime),
                      model, view, queue) {
}

ButtonHandlerTank::~ButtonHandlerTank() {}

void ButtonHandlerTank::execute() {
	Tank& newUnit = model.createTank(500, 500, GameHandler::actual_player);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}

bool ButtonHandlerTank::canBeEnabled() {
	return (((model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.tankCost)) &&
	        (model.getPlayer(GameHandler::actual_player).hasBuilding(Building::HEAVY_FACTORY)));
}

bool ButtonHandlerTank::finishAction() {
	return (!this->model.getPlayer(GameHandler::actual_player).trainingCenter->isTrainingTank());
}
