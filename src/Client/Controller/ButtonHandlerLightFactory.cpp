#include "ButtonHandlerLightFactory.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"
#include <iostream>

ButtonHandlerLightFactory::ButtonHandlerLightFactory(Model &model, GameView &view,
            BuildingConstructor& constructor, CommunicationQueue& queue) :
        ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/light-factory.gif",
                                                GlobalConfig.buildingConstructionTime),
                      model, view, queue),
    constructor(constructor) {}

ButtonHandlerLightFactory::~ButtonHandlerLightFactory() {}

void ButtonHandlerLightFactory::execute() {
    nlohmann::json msg;
    msg["method"] = "beginConstruction";
    msg["args"]["player"] = GameHandler::actual_player;
    msg["args"]["building_type"] = Building::LIGHT_FACTORY;
    queue.enqueue(msg);
    model.getPlayer(GameHandler::actual_player).buildingCenter->newConstruct(Building::LIGHT_FACTORY);
}

bool ButtonHandlerLightFactory::canBeEnabled() {
    return (this->model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.lightFactoryCost);
}

bool ButtonHandlerLightFactory::finishAction() {
    return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingReady(Building::LIGHT_FACTORY);
}

void ButtonHandlerLightFactory::executeReady() {
    constructor.building = Building::LIGHT_FACTORY;
    constructor.cost = GlobalConfig.lightFactoryCost;
    constructor.width = GlobalConfig.lightFactoryWidth;
    constructor.height = GlobalConfig.lightFactoryHeight;
    constructor.on = true;
}

bool ButtonHandlerLightFactory::finishReady() {
    return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingConstructed(Building::LIGHT_FACTORY);
}
