#include "BuildingConstructor.h"
#include "../Model/Buildings/Barracks.h"
#include "../Model/Buildings/LightFactory.h"
#include "../Model/Buildings/HeavyFactory.h"
#include "../Model/Buildings/SpiceRefinery.h"
#include "../Model/Buildings/SpiceSilo.h"
#include "../View/GameView.h"
#include "../View/BuildingViewFactory.h"
#include "GameHandler.h"

BuildingConstructor::BuildingConstructor(Model& model, Player& player, GameView& view):
    model(model),
    player(player),
    view(view),
    on(false),
    pos(0, 0),
    building(),
    width(0),
    height(0),
    cost(0) {
    view.addBuildingConstructorView(this);
}

bool BuildingConstructor::canWeBuild() {
    pos = model.getMap().getCornerPosition(pos);
    return (on && model.canWeBuild(pos, width, height, cost, model.getPlayer(GameHandler::actual_player)));
}

void BuildingConstructor::build() {
    if (on) {
        if (model.canWeBuild(pos, width, height, cost, model.getPlayer(GameHandler::actual_player))) {
            switch (building) {
            case Building::BARRACKS:
            {
                Barracks& barracks = model.createBarracks(pos.x, pos.y, GameHandler::actual_player);
                view.addBuildingView(BuildingViewFactory::createBuildingView(barracks, view.getWindow()));
                model.getPlayer(GameHandler::actual_player).buildingCenter->build(Building::BARRACKS);
                break;
            }
            case Building::LIGHT_FACTORY:
            {
                LightFactory& lightF = model.createLightFactory(pos.x, pos.y, GameHandler::actual_player);
                view.addBuildingView(BuildingViewFactory::createBuildingView(lightF, view.getWindow()));
                model.getPlayer(GameHandler::actual_player).buildingCenter->build(Building::LIGHT_FACTORY);
                break;
            }
            case Building::HEAVY_FACTORY:
            {
                HeavyFactory& heavyF = model.createHeavyFactory(pos.x, pos.y, GameHandler::actual_player);
                view.addBuildingView(BuildingViewFactory::createBuildingView(heavyF, view.getWindow()));
                model.getPlayer(GameHandler::actual_player).buildingCenter->build(Building::HEAVY_FACTORY);
                break;
            }
            case Building::SPICE_REFINERY:
            {
                SpiceRefinery& spiceRef = model.createSpiceRefinery(pos.x, pos.y, GameHandler::actual_player);
                view.addBuildingView(BuildingViewFactory::createBuildingView(spiceRef, view.getWindow()));
                model.getPlayer(GameHandler::actual_player).buildingCenter->build(Building::SPICE_REFINERY);
                break;
            }

            case Building::SPICE_SILO:
            {
                SpiceSilo& spiceSilo = model.createSpiceSilo(pos.x, pos.y, GameHandler::actual_player);
                view.addBuildingView(BuildingViewFactory::createBuildingView(spiceSilo, view.getWindow()));
                model.getPlayer(GameHandler::actual_player).buildingCenter->build(Building::SPICE_SILO);
                break;
            }
            case Building::WIND_TRAP:
            {
                WindTrap& windtrap = model.createWindTrap(pos.x, pos.y, GameHandler::actual_player);
                view.addBuildingView(BuildingViewFactory::createBuildingView(windtrap, view.getWindow()));
                model.getPlayer(GameHandler::actual_player).buildingCenter->build(Building::WIND_TRAP);
                break;
            }
            default:
                break;
            }
            on = false;

        }
    }
}

Player& BuildingConstructor::getPlayer() {
//    return this->player;
    return model.getPlayer(GameHandler::actual_player);
}