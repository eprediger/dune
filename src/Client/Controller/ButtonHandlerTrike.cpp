#include "ButtonHandlerTrike.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerTrike::ButtonHandlerTrike(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/trike.jpg",
                                            GameConfiguration::getConfig().trikeConstructionTime),
                      player, view, queue, GameConfiguration::getConfig().trikeConstructionTime) {
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
	return this->player.hasResourcesFor(Unit::UnitType::TRIKE);
} 

bool ButtonHandlerTrike::finishAction() {
	buttonView.update(((time - player.trainingCenter->remainingTime(Unit::TRIKE)) * 100) / time);  
	return (!this->player.trainingCenter->isTrainingTrike());
}
