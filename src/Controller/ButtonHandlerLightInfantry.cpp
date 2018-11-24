#include "ButtonHandlerLightInfantry.h"
#include "../View/UnitViewFactory.h"
#include "../Model/GlobalConfig.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerLightInfantry::ButtonHandlerLightInfantry(Model &model, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/linfantry.gif",
                                            GlobalConfig.lightInfantryTrainingTime),
                      model, view, queue) {}

ButtonHandlerLightInfantry::~ButtonHandlerLightInfantry() {}

void ButtonHandlerLightInfantry::execute() {
	nlohmann::json msg;
	msg["method"] = "createLightInfantry";
	msg["args"]["player"] = GameHandler::actual_player;
	queue.enqueue(msg);
}

bool ButtonHandlerLightInfantry::canBeEnabled() {
	return (((model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.lightInfantryCost)) &&
	        (model.getPlayer(GameHandler::actual_player).hasBuilding(Building::BARRACKS)));
}

bool ButtonHandlerLightInfantry::finishAction() {
	return (!this->model.getPlayer(GameHandler::actual_player).trainingCenter->isTrainingLightInfantry());
}
