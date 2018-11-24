#include "ButtonHandlerWindTrap.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"

ButtonHandlerWindTrap::ButtonHandlerWindTrap(Model& model, GameView& view,
            BuildingConstructor& constructor, CommunicationQueue& queue) :
        ButtonHandler(view.createBuildingButton("../assets/img/btns/buildings/windtrap.gif",
                                                GlobalConfig.buildingConstructionTime),
                      model, view, queue),
    constructor(constructor) {
    if (this->canBeEnabled()) {
        this->setState(State::ENABLED);
    }
}

ButtonHandlerWindTrap::~ButtonHandlerWindTrap() {}

void ButtonHandlerWindTrap::execute() {
    nlohmann::json msg;
    msg["method"] = "beginConstruction";
    msg["args"]["player"] = GameHandler::actual_player;
    msg["args"]["building_type"] = Building::WIND_TRAP;
    queue.enqueue(msg);
}

bool ButtonHandlerWindTrap::canBeEnabled() {
    return (this->model.getPlayer(GameHandler::actual_player).gold >= GlobalConfig.windTrapCost);
}

bool ButtonHandlerWindTrap::finishAction() {
    return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingReady(Building::WIND_TRAP);
}

void ButtonHandlerWindTrap::executeReady() {
    constructor.building = Building::WIND_TRAP;
    constructor.cost = GlobalConfig.windTrapCost;
    constructor.width = GlobalConfig.windTrapWidth;
    constructor.height = GlobalConfig.windTrapHeight;
    constructor.on = true;
}

bool ButtonHandlerWindTrap::finishReady() {
    return model.getPlayer(GameHandler::actual_player).buildingCenter->buildingConstructed(Building::WIND_TRAP);
}
