#include "ButtonHandlerSpiceSilo.h"
#include "../View/BuildingViewFactory.h"
#include <iostream>

ButtonHandlerSpiceSilo::ButtonHandlerSpiceSilo(Model &model, GameView &view, BuildingConstructor& constructor) :
	ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/silo.gif"), model, view)
	,constructor(constructor){}

ButtonHandlerSpiceSilo::~ButtonHandlerSpiceSilo() {}

void ButtonHandlerSpiceSilo::execute() {
	constructor.building = Building::SPICE_SILO;
    constructor.cost = GlobalConfig.spiceSiloCost;
    constructor.width = GlobalConfig.spiceSiloSpicWidth;
    constructor.height = GlobalConfig.spiceSiloSpicHeight;
    constructor.on = true;
}

bool ButtonHandlerSpiceSilo::canBeEnabled() {
    return (this->model.getPlayer(0).gold >= GlobalConfig.spiceSiloCost);
}
