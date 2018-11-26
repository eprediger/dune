#include "ButtonHandlerBarracks.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>
#include "Model/GlobalConfig.h"

ButtonHandlerBarracks::ButtonHandlerBarracks(Model &model, GameView &view,
			BuildingConstructor& constructor, CommunicationQueue& queue):
        ButtonHandler(
                view.createBuildingButton("../assets/img/btns/buildings/barracks-atreides.jpg",
                                          GlobalConfig.buildingConstructionTime),
                model,
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
	msg["args"]["player"] = GameHandler::actual_player;
	msg["args"]["building_type"] = Building::BARRACKS;
	queue.enqueue(msg);
	model.getPlayer(GameHandler::actual_player).buildingCenter->newConstruct(Building::BARRACKS);
}

bool ButtonHandlerBarracks::canBeEnabled() {
    return (this->model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.barracksCost);
}

bool ButtonHandlerBarracks::finishAction() {
    if (model.getPlayer(GameHandler::actual_player).buildingCenter->buildingReady(Building::BARRACKS)){
        std::cout << "Accion finalizada" << std::endl;
    }
    return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingReady(Building::BARRACKS);
}

void ButtonHandlerBarracks::executeReady() {
	constructor.building = Building::BARRACKS;
	constructor.cost = GlobalConfig.barracksCost;
	constructor.width = GlobalConfig.barracksWidth;
	constructor.height = GlobalConfig.barracksHeight;
	constructor.on = true;
}

bool ButtonHandlerBarracks::finishReady() {
    if (model.getPlayer(GameHandler::actual_player).buildingCenter->buildingConstructed(Building::BARRACKS)){
        std::cout << "Ready listo" << std::endl;
    }
	return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingConstructed(Building::BARRACKS);
}
