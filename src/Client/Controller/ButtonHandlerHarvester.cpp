#include "ButtonHandlerHarvester.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHarvester::ButtonHandlerHarvester(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/harvest.gif",
                                            GameConfiguration::getConfig().harvesterConstructionTime),
                      player, view, queue) {}

ButtonHandlerHarvester::~ButtonHandlerHarvester() {}

void ButtonHandlerHarvester::execute() {
	nlohmann::json msg;
	msg["method"] = "createHarvester";
	msg["args"]["player_id"] = player.getId();
	queue.enqueue(msg);
	player.trainingCenter->beginTraining(Unit::HARVESTER);
	this->update();
}

bool ButtonHandlerHarvester::canBeEnabled() {
	return (((player.gold >= GameConfiguration::getConfig().harvesterCost)) &&
	        (player.hasBuilding(Building::HEAVY_FACTORY)));
}

bool ButtonHandlerHarvester::finishAction() {
	return (!this->player.trainingCenter->isTrainingHarvester());
}
