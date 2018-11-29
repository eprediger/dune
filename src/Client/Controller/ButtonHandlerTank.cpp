#include "ButtonHandlerTank.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerTank::ButtonHandlerTank(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/tank.gif",
                                            GlobalConfig.tankConstructionTime),
                      player, view, queue) {
}

ButtonHandlerTank::~ButtonHandlerTank() {}

void ButtonHandlerTank::execute() {
	nlohmann::json msg;
	msg["method"] = "createTank";
	msg["args"]["player_id"] = player.getId();
	queue.enqueue(msg);
	player.trainingCenter->beginTraining(Unit::TANK);
	this->update();
}

bool ButtonHandlerTank::canBeEnabled() {
	return (((player.gold >= GlobalConfig.tankCost)) &&
	        (player.hasBuilding(Building::HEAVY_FACTORY)));
}
 
bool ButtonHandlerTank::finishAction() {
	return (!this->player.trainingCenter->isTrainingTank());
}
