#include "ButtonHandlerHarvester.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>
#include <Path.h>

ButtonHandlerHarvester::ButtonHandlerHarvester(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton(Path::rootVar("assets/img/btns/units/harvest.gif"),
                                            GameConfiguration::getConfig().harvesterConstructionTime,
											Path::rootVar("assets/sound/fx/new harvester.wav").c_str()),
                      player, view, queue, GameConfiguration::getConfig().harvesterConstructionTime){ }

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
