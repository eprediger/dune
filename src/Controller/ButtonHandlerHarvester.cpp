#include "ButtonHandlerHarvester.h"
#include "../View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHarvester::ButtonHandlerHarvester(Model &model, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/harvest.gif",
                                            GlobalConfig.harvesterConstructionTime),
                      model, view, queue) {}

ButtonHandlerHarvester::~ButtonHandlerHarvester() {}

void ButtonHandlerHarvester::execute() {
	Harvester& newUnit = model.createHarvester(500, 500, GameHandler::actual_player);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}

bool ButtonHandlerHarvester::canBeEnabled() {
	return (((model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.harvesterCost)) &&
	        (model.getPlayer(GameHandler::actual_player).hasBuilding(Building::HEAVY_FACTORY)));
}

bool ButtonHandlerHarvester::finishAction() {
	return (!this->model.getPlayer(GameHandler::actual_player).trainingCenter->isTrainingHarvester());
}
