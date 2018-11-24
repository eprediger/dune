#include "ButtonHandlerRaider.h"
#include "../View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerRaider::ButtonHandlerRaider(Model &model, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/raider.gif",
                                            GlobalConfig.raiderConstructionTime),
                      model, view, queue) {
}

ButtonHandlerRaider::~ButtonHandlerRaider() {}

void ButtonHandlerRaider::execute() {
	nlohmann::json msg;
	msg["method"] = "createRaider";
	msg["args"]["player"] = GameHandler::actual_player;
	queue.enqueue(msg);
}

bool ButtonHandlerRaider::canBeEnabled() {
	return (((model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.raiderCost)) &&
	        (model.getPlayer(GameHandler::actual_player).hasBuilding(Building::LIGHT_FACTORY)));
}

bool ButtonHandlerRaider::finishAction() {
	return (!this->model.getPlayer(GameHandler::actual_player).trainingCenter->isTrainingRaider());
}
