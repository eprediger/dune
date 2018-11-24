#include "ButtonHandlerHeavyInfantry.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHeavyInfantry::ButtonHandlerHeavyInfantry(Model &model, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/hinfantry.gif",
                                            GlobalConfig.heavyInfantryTrainingTime),
                      model, view, queue) {
}

ButtonHandlerHeavyInfantry::~ButtonHandlerHeavyInfantry() {}

void ButtonHandlerHeavyInfantry::execute() {
	nlohmann::json msg;
	msg["method"] = "createHeavyInfantry";
	msg["args"]["player"] = GameHandler::actual_player;
	queue.enqueue(msg);
}

bool ButtonHandlerHeavyInfantry::canBeEnabled() {
	return (((model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.heavyInfantryCost)) &&
	        (model.getPlayer(GameHandler::actual_player).hasBuilding(Building::BARRACKS)));
}

bool ButtonHandlerHeavyInfantry::finishAction() {
	return !(this->model.getPlayer(GameHandler::actual_player).trainingCenter->isTrainingHeavyInfantry());
}
