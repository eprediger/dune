#include "ButtonHandlerHeavyInfantry.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHeavyInfantry::ButtonHandlerHeavyInfantry(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/hinfantry.gif",
                                            GameConfiguration::getConfig().heavyInfantryTrainingTime),
                     player, view, queue) {
}

ButtonHandlerHeavyInfantry::~ButtonHandlerHeavyInfantry() {}

void ButtonHandlerHeavyInfantry::execute() {
	nlohmann::json msg;
	msg["method"] = "createHeavyInfantry";
	msg["args"]["player_id"] = player.getId();
	queue.enqueue(msg);
	player.trainingCenter->beginTraining(Unit::HEAVY_INFANTRY);
	this->update();
}

bool ButtonHandlerHeavyInfantry::canBeEnabled() {
	return this->player.hasResourcesFor(Unit::UnitType::HEAVY_INFANTRY);
}

bool ButtonHandlerHeavyInfantry::finishAction() {
	return !(this->player.trainingCenter->isTrainingHeavyInfantry());
}
