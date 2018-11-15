#include "ButtonHandlerLightFactory.h"
#include "../View/BuildingViewFactory.h"
#include <iostream>

ButtonHandlerLightFactory::ButtonHandlerLightFactory(Model &model, GameView &view) :
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/light-factory.gif"), model, view) {
}

ButtonHandlerLightFactory::~ButtonHandlerLightFactory() {}

void ButtonHandlerLightFactory::execute() {
	LightFactory& newBuilding = model.createLightFactory(500, 500, 0);
	view.addBuildingView(BuildingViewFactory::createBuildingView(newBuilding, view.getWindow()));
}
