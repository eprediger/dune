#include "ButtonHandlerLightFactory.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerLightFactory::ButtonHandlerLightFactory(Player& player, GameView &view,
            BuildingConstructor& constructor, CommunicationQueue& queue) :
        ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/light-factory.gif",
                                                GlobalConfig.buildingConstructionTime),
                      player, view, queue),
    constructor(constructor) {}

ButtonHandlerLightFactory::~ButtonHandlerLightFactory() {}

void ButtonHandlerLightFactory::execute() {
    nlohmann::json msg;
    msg["method"] = "beginConstruction";
    msg["args"]["player_id"] = player.getId();
    msg["args"]["building_type"] = Building::LIGHT_FACTORY;
    queue.enqueue(msg);
	player.buildingCenter->beginConstruction(Building::LIGHT_FACTORY);
}

bool ButtonHandlerLightFactory::canBeEnabled() {
    return (this->player.gold >= GlobalConfig.lightFactoryCost);
}

bool ButtonHandlerLightFactory::finishAction() {
    return player.buildingCenter->buildingReady(Building::LIGHT_FACTORY);
}

void ButtonHandlerLightFactory::executeReady() {
    constructor.building = Building::LIGHT_FACTORY;
    constructor.cost = GlobalConfig.lightFactoryCost;
    constructor.width = GlobalConfig.lightFactoryWidth;
    constructor.height = GlobalConfig.lightFactoryHeight;
    constructor.on = true;
}

bool ButtonHandlerLightFactory::finishReady() {
    return player.buildingCenter->buildingConstructed(Building::LIGHT_FACTORY);
}
