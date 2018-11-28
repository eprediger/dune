#include "ButtonHandlerBarracks.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>
#include "Model/GlobalConfig.h"

ButtonHandlerBarracks::ButtonHandlerBarracks(Player& player, GameView &view,
			BuildingConstructor& constructor, CommunicationQueue& queue):
        ButtonHandler(
                view.createBuildingButton("../assets/img/btns/buildings/barracks-atreides.jpg",
                                          GlobalConfig.buildingConstructionTime),
                player,
                view, queue)
	,constructor(constructor) {
	/*
	"../assets/img/btns/buildings/barracks-harkonnen.jpg"
	"../assets/img/btns/buildings/barracks-ordos.jpg"
	*/
}

ButtonHandlerBarracks::~ButtonHandlerBarracks() { time = 0; }

void ButtonHandlerBarracks::execute() {
	nlohmann::json msg;
	msg["method"] = "beginConstruction";
	msg["args"]["player"] = player.getId();
	msg["args"]["building_type"] = Building::BARRACKS;
	queue.enqueue(msg);
	player.buildingCenter->beginConstruction(Building::BARRACKS);
}

bool ButtonHandlerBarracks::canBeEnabled() {
    return (this->player.gold >= GlobalConfig.barracksCost);
}

bool ButtonHandlerBarracks::finishAction() {
    return player.buildingCenter->buildingReady(Building::BARRACKS);
}

void ButtonHandlerBarracks::executeReady() {
	constructor.building = Building::BARRACKS;
	constructor.cost = GlobalConfig.barracksCost;
	constructor.width = GlobalConfig.barracksWidth;
	constructor.height = GlobalConfig.barracksHeight;
	constructor.on = true;
}

bool ButtonHandlerBarracks::finishReady() {

	return player.buildingCenter->buildingConstructed(Building::BARRACKS);
}
