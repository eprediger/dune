#include "ButtonHandlerBarracks.h"
#include "../View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerBarracks::ButtonHandlerBarracks(Model &model, GameView &view, BuildingConstructor& constructor):
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/barracks-atreides.jpg"), model, view)
	,constructor(constructor) {
	/*
	"../assets/img/btns/buildings/barracks-harkonnen.jpg"
	"../assets/img/btns/buildings/barracks-ordos.jpg"
	*/
}

ButtonHandlerBarracks::~ButtonHandlerBarracks() {}

void ButtonHandlerBarracks::execute() {
	constructor.building = Building::BARRACKS;
    constructor.cost = GlobalConfig.barracksCost;
    constructor.width = GlobalConfig.barracksWidth;
    constructor.height = GlobalConfig.barracksHeight;
    constructor.on = true;
}

bool ButtonHandlerBarracks::canBeEnabled() {
    return (this->model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.barracksCost);
}
