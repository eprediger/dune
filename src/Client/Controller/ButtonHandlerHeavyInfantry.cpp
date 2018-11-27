#include "ButtonHandlerHeavyInfantry.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHeavyInfantry::ButtonHandlerHeavyInfantry(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/hinfantry.gif",
                                            GlobalConfig.heavyInfantryTrainingTime),
                     player, view, queue) {
}

ButtonHandlerHeavyInfantry::~ButtonHandlerHeavyInfantry() {}

void ButtonHandlerHeavyInfantry::execute() {
	nlohmann::json msg;
	msg["method"] = "createHeavyInfantry";
	msg["args"]["player"] = player.getId();
	queue.enqueue(msg);
}

bool ButtonHandlerHeavyInfantry::canBeEnabled() {
	return (((player.gold >= GlobalConfig.heavyInfantryCost)) &&
	        (player.hasBuilding(Building::BARRACKS)));
}

bool ButtonHandlerHeavyInfantry::finishAction() {
	return !(this->player.trainingCenter->isTrainingHeavyInfantry());
}
