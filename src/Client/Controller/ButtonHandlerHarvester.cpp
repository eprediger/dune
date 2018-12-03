#include "ButtonHandlerHarvester.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHarvester::ButtonHandlerHarvester(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/harvest.gif",
                                            GameConfiguration::getConfig().harvesterConstructionTime,
											"../assets/sound/fx/new harvester.wav"),
                      player, view, queue, GameConfiguration::getConfig().harvesterConstructionTime){ }
ButtonHandlerHarvester::~ButtonHandlerHarvester() {}

void ButtonHandlerHarvester::execute() {
	nlohmann::json msg;
	msg["method"] = "createHarvester";
	msg["args"]["player_id"] = player.getId();
	queue.enqueue(msg);
	player.trainingCenter->beginTraining(Unit::HARVESTER);
	this->update();
}

bool ButtonHandlerHarvester::canBeEnabled() {
	return this->player.hasResourcesFor(Unit::UnitType::HARVESTER);
}

bool ButtonHandlerHarvester::finishAction() {
	buttonView.update(((time - player.trainingCenter->remainingTime(Unit::HARVESTER)) * 100) / time);  
	return (!this->player.trainingCenter->isTrainingHarvester());
}
