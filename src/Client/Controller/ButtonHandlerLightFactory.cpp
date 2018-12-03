#include "ButtonHandlerLightFactory.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerLightFactory::ButtonHandlerLightFactory(Player& player, GameView &view,
            BuildingConstructor& constructor, CommunicationQueue& queue) :
        ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/light-factory.gif",
                                                GameConfiguration::getConfig().buildingConstructionTime,
                                                "../assets/sound/fx/fin light fac.wav"),
                      player, view, queue,GameConfiguration::getConfig().buildingConstructionTime),
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
    return (this->player.hasResourcesFor(Building::BuildingType::LIGHT_FACTORY));
}

bool ButtonHandlerLightFactory::finishAction() {
	buttonView.update(((time - player.buildingCenter->remainingTime(Building::LIGHT_FACTORY)) * 100) / time);  
    return player.buildingCenter->buildingReady(Building::LIGHT_FACTORY);
}

void ButtonHandlerLightFactory::executeReady() {
    constructor.building = Building::LIGHT_FACTORY;
    constructor.cost = GameConfiguration::getConfig().lightFactoryCost;
    constructor.width = GameConfiguration::getConfig().lightFactoryWidth;
    constructor.height = GameConfiguration::getConfig().lightFactoryHeight;
    constructor.on = true;
}

bool ButtonHandlerLightFactory::finishReady() {
    return player.buildingCenter->buildingConstructed(Building::LIGHT_FACTORY);
}
