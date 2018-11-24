#include "ButtonHandlerHeavyFactory.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHeavyFactory::ButtonHandlerHeavyFactory(Model &model, GameView &view,
            BuildingConstructor& constructor, CommunicationQueue& queue) :
        ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/heavy-factory.gif",
                                                GlobalConfig.buildingConstructionTime),
                      model, view, queue),
    constructor(constructor) {}

ButtonHandlerHeavyFactory::~ButtonHandlerHeavyFactory() {}

void ButtonHandlerHeavyFactory::execute() {
    nlohmann::json msg;
    msg["method"] = "beginConstruction";
    msg["args"]["player"] = GameHandler::actual_player;
    msg["args"]["building_type"] = Building::HEAVY_FACTORY;
    queue.enqueue(msg);
}

bool ButtonHandlerHeavyFactory::canBeEnabled() {
    return (this->model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.heavyFactoryCost);
}

bool ButtonHandlerHeavyFactory::finishAction() {
    return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingReady(Building::HEAVY_FACTORY);
}

void ButtonHandlerHeavyFactory::executeReady() {
    constructor.building = Building::HEAVY_FACTORY;
    constructor.cost = GlobalConfig.heavyFactoryCost;
    constructor.width = GlobalConfig.heavyFactoryWidth;
    constructor.height = GlobalConfig.heavyFactoryHeight;
    constructor.on = true;
}

bool ButtonHandlerHeavyFactory::finishReady() {
    return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingConstructed(Building::HEAVY_FACTORY);
}
