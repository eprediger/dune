#include "ButtonHandlerHeavyFactory.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHeavyFactory::ButtonHandlerHeavyFactory(Player& player, GameView &view,
        BuildingConstructor& constructor, CommunicationQueue& queue) :
    ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/heavy-factory.gif",
                                            GlobalConfig.buildingConstructionTime),
                  player, view, queue),
    constructor(constructor) {}

ButtonHandlerHeavyFactory::~ButtonHandlerHeavyFactory() {}

void ButtonHandlerHeavyFactory::execute() {
    nlohmann::json msg;
    msg["method"] = "beginConstruction";
    msg["args"]["player_id"] = player.getId();
    msg["args"]["building_type"] = Building::HEAVY_FACTORY;
    queue.enqueue(msg);
    player.buildingCenter->beginConstruction(Building::HEAVY_FACTORY);

}

bool ButtonHandlerHeavyFactory::canBeEnabled() {
    return (this->player.gold >= GlobalConfig.heavyFactoryCost);
}

bool ButtonHandlerHeavyFactory::finishAction() {
    return player.buildingCenter->buildingReady(Building::HEAVY_FACTORY);
}

void ButtonHandlerHeavyFactory::executeReady() {
    constructor.building = Building::HEAVY_FACTORY;
    constructor.cost = GlobalConfig.heavyFactoryCost;
    constructor.width = GlobalConfig.heavyFactoryWidth;
    constructor.height = GlobalConfig.heavyFactoryHeight;
    constructor.on = true;
}

bool ButtonHandlerHeavyFactory::finishReady() {
    return player.buildingCenter->buildingConstructed(Building::HEAVY_FACTORY);
}
