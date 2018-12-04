#include "ButtonHandlerHeavyInfantry.h"
#include "View/UnitViewFactory.h"
#include "GameHandler.h"
#include <iostream>
#include <Path.h>

ButtonHandlerHeavyInfantry::ButtonHandlerHeavyInfantry(Player& player, GameView &view, CommunicationQueue& queue) :
        ButtonHandler(view.createUnitButton(Path::rootVar("assets/img/btns/units/hinfantry.gif"),
                                            GameConfiguration::getConfig().heavyInfantryTrainingTime,
											Path::rootVar("assets/sound/fx/new heavy inf.wav").c_str()),
                     player, view, queue,GameConfiguration::getConfig().heavyInfantryTrainingTime) {
}

ButtonHandlerHeavyInfantry::~ButtonHandlerHeavyInfantry() {}

void ButtonHandlerHeavyInfantry::execute() {
	nlohmann::json msg;
	msg["method"] = "createHeavyInfantry";
	msg["args"]["player_id"] = player.getId();
	queue.enqueue(msg);
	player.trainingCenter->beginTraining(Unit::HEAVY_INFANTRY);
	this->update();
}

bool ButtonHandlerHeavyInfantry::canBeEnabled() {
	return this->player.hasResourcesFor(Unit::UnitType::HEAVY_INFANTRY);
}

bool ButtonHandlerHeavyInfantry::finishAction() {
	buttonView.update(((time - player.trainingCenter->remainingTime(Unit::HEAVY_INFANTRY)) * 100) / time);  
	return !(this->player.trainingCenter->isTrainingHeavyInfantry());
}
