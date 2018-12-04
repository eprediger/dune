#include <Path.h>
#include "ButtonHandlerWindTrap.h"
#include "View/BuildingViewFactory.h"
#include "GameHandler.h"

ButtonHandlerWindTrap::ButtonHandlerWindTrap(Player& player, GameView& view,
            BuildingConstructor& constructor, CommunicationQueue& queue) :
        ButtonHandler(view.createBuildingButton(Path::rootVar("assets/img/btns/buildings/windtrap.gif"),
                                                GameConfiguration::getConfig().buildingConstructionTime,
                                                Path::rootVar("assets/sound/fx/finished windtrap.wav").c_str()),
                      player, view, queue,GameConfiguration::getConfig().buildingConstructionTime),
    constructor(constructor) {
    if (this->canBeEnabled()) {
        this->setState(State::ENABLED);
    }
}

ButtonHandlerWindTrap::~ButtonHandlerWindTrap() {}

void ButtonHandlerWindTrap::execute() {
    nlohmann::json msg;
    msg["method"] = "beginConstruction";
    msg["args"]["player_id"] = player.getId();
    msg["args"]["building_type"] = Building::WIND_TRAP;
    queue.enqueue(msg);
	player.buildingCenter->beginConstruction(Building::WIND_TRAP);
}

bool ButtonHandlerWindTrap::canBeEnabled() {
    return (this->player.hasResourcesFor(Building::WIND_TRAP));
}

bool ButtonHandlerWindTrap::finishAction() {
	buttonView.update(((time - player.buildingCenter->remainingTime(Building::WIND_TRAP)) * 100) / time);  
    return player.buildingCenter->buildingReady(Building::WIND_TRAP);
}

void ButtonHandlerWindTrap::executeReady() {
    constructor.building = Building::WIND_TRAP;
    constructor.cost = GameConfiguration::getConfig().windTrapCost;
    constructor.width = GameConfiguration::getConfig().windTrapWidth;
    constructor.height = GameConfiguration::getConfig().windTrapHeight;
    constructor.on = true;
}

bool ButtonHandlerWindTrap::finishReady() {
    return player.buildingCenter->buildingConstructed(Building::WIND_TRAP);
}
