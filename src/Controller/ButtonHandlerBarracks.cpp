#include "ButtonHandlerBarracks.h"
#include "../View/BuildingViewFactory.h"
#include <iostream>

ButtonHandlerBarracks::ButtonHandlerBarracks(Model &model, GameView &view) :
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/barracks-atreides.jpg"), model, view) {
	/*
	"../assets/img/btns/buildings/barracks-harkonnen.jpg"
	"../assets/img/btns/buildings/barracks-ordos.jpg"
	*/
}

ButtonHandlerBarracks::~ButtonHandlerBarracks() {}

void ButtonHandlerBarracks::execute() {
	Barracks& newBuilding = model.createBarracks(500, 500, 0);
	view.addBuildingView(BuildingViewFactory::createBuildingView(newBuilding, view.getWindow()));
}

bool ButtonHandlerBarracks::canBeEnabled() {
    return (this->model.getPlayer(0).gold >= GlobalConfig.barracksCost);
}
