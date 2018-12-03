#include "ButtonHandlerLightInfantry.h"
#include "View/UnitViewFactory.h"
#include <Model/GameConfiguration.h>
#include "GameHandler.h"
#include <iostream>

ButtonHandlerLightInfantry::ButtonHandlerLightInfantry(Player& player, GameView &view, CommunicationQueue& queue) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/linfantry.gif",
	                                    GameConfiguration::getConfig().lightInfantryTrainingTime,
										"../assets/sound/fx/new light inf.wav"),
	              player, view, queue,GameConfiguration::getConfig().lightInfantryTrainingTime){}

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
	return this->player.hasResourcesFor(Unit::UnitType::LIGHT_INFANTRY);
}

bool ButtonHandlerLightInfantry::finishAction() {
	buttonView.update(((time - player.trainingCenter->remainingTime(Unit::LIGHT_INFANTRY)) * 100) / time);  
	return (!this->player.trainingCenter->isTrainingLightInfantry());
}
