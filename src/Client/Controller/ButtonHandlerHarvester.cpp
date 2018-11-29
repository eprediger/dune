#include "ButtonHandlerHarvester.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHarvester::ButtonHandlerHarvester(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/harvest.gif",
                                            GlobalConfig.harvesterConstructionTime),
                      player, view, queue) {}

ButtonHandlerHarvester::~ButtonHandlerHarvester() {}

void ButtonHandlerHarvester::execute() {
	nlohmann::json msg;
	msg["method"] = "createHarvester";
	msg["args"]["player"] = player.getId();
	queue.enqueue(msg);
	player.trainingCenter->beginTraining(Unit::HARVESTER);
}

bool ButtonHandlerHarvester::canBeEnabled() {
	return (((player.gold >= GlobalConfig.harvesterCost)) &&
	        (player.hasBuilding(Building::HEAVY_FACTORY)));
}

bool ButtonHandlerHarvester::finishAction() {
	return (!this->player.trainingCenter->isTrainingHarvester());
}
