#include "ButtonHandlerRaider.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerRaider::ButtonHandlerRaider(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/raider.gif",
                                            GameConfiguration::getConfig().raiderConstructionTime),
                     player, view, queue, GameConfiguration::getConfig().raiderConstructionTime) {
}

ButtonHandlerRaider::~ButtonHandlerRaider() {}

void ButtonHandlerRaider::execute() {
	nlohmann::json msg;
	msg["method"] = "createRaider";
	msg["args"]["player_id"] = player.getId();
	queue.enqueue(msg);
	player.trainingCenter->beginTraining(Unit::RAIDER);
	this->update();
}

bool ButtonHandlerRaider::canBeEnabled() {
	return this->player.hasResourcesFor(Unit::UnitType::RAIDER);
}

bool ButtonHandlerRaider::finishAction() {
	buttonView.update(((time - player.trainingCenter->remainingTime(Unit::RAIDER)) * 100) / time);  
	return (!this->player.trainingCenter->isTrainingRaider());
}
