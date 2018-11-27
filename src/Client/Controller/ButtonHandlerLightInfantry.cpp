#include "ButtonHandlerLightInfantry.h"
#include "View/UnitViewFactory.h"
#include "Model/GlobalConfig.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerLightInfantry::ButtonHandlerLightInfantry(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/linfantry.gif",
                                            GlobalConfig.lightInfantryTrainingTime),
                      player, view, queue) {}

ButtonHandlerLightInfantry::~ButtonHandlerLightInfantry() {}

void ButtonHandlerLightInfantry::execute() {
	nlohmann::json msg;
	msg["method"] = "createLightInfantry";
	msg["args"]["player"] = player.getId();
	queue.enqueue(msg);
}

bool ButtonHandlerLightInfantry::canBeEnabled() {
	return (((player.gold >= GlobalConfig.lightInfantryCost)) &&
	        (player.hasBuilding(Building::BARRACKS)));
}

bool ButtonHandlerLightInfantry::finishAction() {
	return (!this->player.trainingCenter->isTrainingLightInfantry());
}