#include "ButtonHandlerHeavyFactory.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerHeavyFactory::ButtonHandlerHeavyFactory(Player& player, GameView &view,
    BuildingConstructor& constructor, CommunicationQueue& queue) :
    ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/heavy-factory.gif",
                                            GameConfiguration::getConfig().buildingConstructionTime),
                  player, view, queue,GameConfiguration::getConfig().buildingConstructionTime),
    constructor(constructor)
    {}

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
    return (this->player.hasResourcesFor(Building::HEAVY_FACTORY));
}

bool ButtonHandlerHeavyFactory::finishAction() {
	buttonView.update(((time - player.buildingCenter->remainingTime(Building::HEAVY_FACTORY)) * 100) / time);
    return player.buildingCenter->buildingReady(Building::HEAVY_FACTORY);
}

void ButtonHandlerHeavyFactory::executeReady() {
    constructor.building = Building::HEAVY_FACTORY;
    constructor.cost = GameConfiguration::getConfig().heavyFactoryCost;
    constructor.width = GameConfiguration::getConfig().heavyFactoryWidth;
    constructor.height = GameConfiguration::getConfig().heavyFactoryHeight;
    constructor.on = true;
}

bool ButtonHandlerHeavyFactory::finishReady() {
    return player.buildingCenter->buildingConstructed(Building::HEAVY_FACTORY);
}
