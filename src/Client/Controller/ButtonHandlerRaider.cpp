#include "ButtonHandlerRaider.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerRaider::ButtonHandlerRaider(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/raider.gif",
                                            GlobalConfig.raiderConstructionTime),
                     player, view, queue) {
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
	return (((player.gold >= GlobalConfig.raiderCost)) &&
	        (player.hasBuilding(Building::LIGHT_FACTORY)));
}

bool ButtonHandlerRaider::finishAction() {
	return (!this->player.trainingCenter->isTrainingRaider());
}
