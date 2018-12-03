#include "ButtonHandlerBarracks.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>
#include <Model/GameConfiguration.h>

ButtonHandlerBarracks::ButtonHandlerBarracks(Player& player, GameView &view,
    BuildingConstructor& constructor, CommunicationQueue& queue):
	ButtonHandler(
	    view.createBuildingButton("../assets/img/btns/buildings/barracks-atreides.jpg",
	                              GameConfiguration::getConfig().buildingConstructionTime,
								  "../assets/sound/fx/finished barracks.wav"),
	    player,
	    view, queue, GameConfiguration::getConfig().buildingConstructionTime),
	constructor(constructor){
	/*
	"../assets/img/btns/buildings/barracks-harkonnen.jpg"
	"../assets/img/btns/buildings/barracks-ordos.jpg"
	*/
}

ButtonHandlerBarracks::~ButtonHandlerBarracks() { time = 0; }

void ButtonHandlerBarracks::execute() {
	nlohmann::json msg;
	msg["method"] = "beginConstruction";
	msg["args"]["player_id"] = player.getId();
	msg["args"]["building_type"] = Building::BARRACKS;
	queue.enqueue(msg);
	player.buildingCenter->beginConstruction(Building::BARRACKS);
}

bool ButtonHandlerBarracks::canBeEnabled() {
	return (this->player.hasResourcesFor(Building::BARRACKS));
}

bool ButtonHandlerBarracks::finishAction() {
	buttonView.update(((time - player.buildingCenter->remainingTime(Building::BARRACKS)) * 100) / time);
	return player.buildingCenter->buildingReady(Building::BARRACKS);
}

void ButtonHandlerBarracks::executeReady() {
	constructor.building = Building::BARRACKS;
	constructor.cost = GameConfiguration::getConfig().barracksCost;
	constructor.width = GameConfiguration::getConfig().barracksWidth;
	constructor.height = GameConfiguration::getConfig().barracksHeight;
	constructor.on = true;
}

bool ButtonHandlerBarracks::finishReady() {
	return player.buildingCenter->buildingConstructed(Building::BARRACKS);
}
