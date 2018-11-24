#include "ButtonHandlerTrike.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerTrike::ButtonHandlerTrike(Model &model, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/trike.jpg",
                                            GlobalConfig.trikeConstructionTime),
                      model, view, queue) {
}

ButtonHandlerTrike::~ButtonHandlerTrike() {}

void ButtonHandlerTrike::execute() {
	nlohmann::json msg;
	msg["method"] = "createTrike";
	msg["args"]["player"] = GameHandler::actual_player;
	queue.enqueue(msg);
}

bool ButtonHandlerTrike::canBeEnabled() {
	return (((model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.trikeCost)) &&
	        (model.getPlayer(GameHandler::actual_player).hasBuilding(Building::LIGHT_FACTORY)));
}

bool ButtonHandlerTrike::finishAction() {
	return (!this->model.getPlayer(GameHandler::actual_player).trainingCenter->isTrainingTrike());
}
