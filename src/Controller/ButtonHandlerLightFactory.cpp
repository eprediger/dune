#include "ButtonHandlerLightFactory.h"
#include "../View/BuildingViewFactory.h"
#include <iostream>

ButtonHandlerLightFactory::ButtonHandlerLightFactory(Model &model, GameView &view, BuildingConstructor& constructor) :
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/light-factory.gif"), model, view),
	constructor(constructor){}

ButtonHandlerLightFactory::~ButtonHandlerLightFactory() {}

void ButtonHandlerLightFactory::execute() {
	constructor.building = Building::LIGHT_FACTORY;
    constructor.cost = GlobalConfig.lightFactoryCost;
    constructor.width = GlobalConfig.lightFactoryWidth;
    constructor.height = GlobalConfig.lightFactoryHeight;
    constructor.on = true;
}

bool ButtonHandlerLightFactory::canBeEnabled() {
    return (this->model.getPlayer(0).gold >= GlobalConfig.lightFactoryCost);
}
