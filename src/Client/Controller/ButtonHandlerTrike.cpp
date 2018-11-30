#include "ButtonHandlerTrike.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerTrike::ButtonHandlerTrike(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/trike.jpg",
                                            GameConfiguration::getConfig().trikeConstructionTime),
                      player, view, queue) {
}

ButtonHandlerTrike::~ButtonHandlerTrike() {}

void ButtonHandlerTrike::execute() {
	nlohmann::json msg;
	msg["method"] = "createTrike";
	msg["args"]["player_id"] = player.getId();
	queue.enqueue(msg);
	player.trainingCenter->beginTraining(Unit::TRIKE);
	this->update();
}

bool ButtonHandlerTrike::canBeEnabled() {
	return (((player.gold >= GameConfiguration::getConfig().trikeCost)) &&
	        (player.hasBuilding(Building::LIGHT_FACTORY)));
} 

bool ButtonHandlerTrike::finishAction() {
	return (!this->player.trainingCenter->isTrainingTrike());
}
