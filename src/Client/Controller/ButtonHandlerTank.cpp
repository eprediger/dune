#include "ButtonHandlerTank.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>
#include <Path.h>

ButtonHandlerTank::ButtonHandlerTank(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton(Path::rootVar("assets/img/btns/units/tank.gif"),
                                            GameConfiguration::getConfig().tankConstructionTime,
											Path::rootVar("assets/sound/fx/new tank.wav").c_str()),
                      player, view, queue,GameConfiguration::getConfig().tankConstructionTime) {
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
	return this->player.hasResourcesFor(Unit::UnitType::TANK);
}
 
bool ButtonHandlerTank::finishAction() {
	buttonView.update(((time - player.trainingCenter->remainingTime(Unit::TANK)) * 100) / time);  
	return (!this->player.trainingCenter->isTrainingTank());
}
