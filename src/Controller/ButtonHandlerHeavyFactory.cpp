#include "ButtonHandlerHeavyFactory.h"
#include "../View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHeavyFactory::ButtonHandlerHeavyFactory(Model &model, GameView &view,BuildingConstructor& constructor) :
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/heavy-factory.gif", 0), model, view)
	,constructor(constructor){}

ButtonHandlerHeavyFactory::~ButtonHandlerHeavyFactory() {}

void ButtonHandlerHeavyFactory::execute() {
	constructor.building = Building::HEAVY_FACTORY;
    constructor.cost = GlobalConfig.heavyFactoryCost;
    constructor.width = GlobalConfig.heavyFactoryWidth;
    constructor.height = GlobalConfig.heavyFactoryHeight;
    constructor.on = true;
}

bool ButtonHandlerHeavyFactory::canBeEnabled() {
    return (this->model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.heavyFactoryCost);
}

bool ButtonHandlerHeavyFactory::finishAction() {
	return true;
}
