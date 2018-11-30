#include "ButtonHandlerLightInfantry.h"
#include "View/UnitViewFactory.h"
#include <Model/GameConfiguration.h>
#include "GameHandler.h"
#include <iostream>

ButtonHandlerLightInfantry::ButtonHandlerLightInfantry(Player& player, GameView &view, CommunicationQueue& queue) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/linfantry.gif",
	                                    GameConfiguration::getConfig().lightInfantryTrainingTime),
	              player, view, queue) {}

ButtonHandlerLightInfantry::~ButtonHandlerLightInfantry() {}

void ButtonHandlerLightInfantry::execute() {
	nlohmann::json msg;
	msg["method"] = "createLightInfantry";
	msg["args"]["player_id"] = player.getId();
	queue.enqueue(msg);
	player.trainingCenter->beginTraining(Unit::LIGHT_INFANTRY);
	this->update();
}

bool ButtonHandlerLightInfantry::canBeEnabled() {
	return (((player.gold >= GameConfiguration::getConfig().lightInfantryCost)) &&
	        (player.hasBuilding(Building::BARRACKS)));
}

bool ButtonHandlerLightInfantry::finishAction() {
	return (!this->player.trainingCenter->isTrainingLightInfantry());
}
