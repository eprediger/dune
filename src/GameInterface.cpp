//
// Created by demian on 22/11/18.
//

#include "GameInterface.h"
#include "View/BuildingViewFactory.h"

GameInterface::GameInterface(Model &model, GameView &view) :
    model(model), view(view) {}

void GameInterface::execute(nlohmann::json json) {
    if ( json["method"] == "createWindTrap"){
        this->createWindTrap(json["args"]["x"],json["args"]["y"],json["args"]["player"]);
        return;
    }
    if ( json["method"] == "createBarracks"){
        this->createBarracks(json["args"]["x"],json["args"]["y"],json["args"]["player"]);
        return;
    }
    if ( json["method"] == "createLightFactory"){
        this->createLightFactory(json["args"]["x"],json["args"]["y"],json["args"]["player"]);
        return;
    }
    if ( json["method"] == "createHeavyFactory"){
        this->createHeavyFactory(json["args"]["x"],json["args"]["y"],json["args"]["player"]);
        return;
    }
    if ( json["method"] == "createSpiceRefinery"){
        this->createSpiceRefinery(json["args"]["x"],json["args"]["y"],json["args"]["player"]);
        return;
    }
    if ( json["method"] == "createSpiceSilo"){
        this->createSpiceSilo(json["args"]["x"],json["args"]["y"],json["args"]["player"]);
        return;
    }
    if ( json["method"] == "beginConstruction"){
        this->beginConstruction(json["args"]["player"],json["args"]["building_type"]);
        return;
    }
}

void GameInterface::createWindTrap(int x, int y, int player_id) {
    WindTrap& windtrap = model.createWindTrap(x,y,player_id);
    view.addBuildingView(BuildingViewFactory::createBuildingView(windtrap, view.getWindow()));
    model.getPlayer(player_id).buildingCenter->build(Building::WIND_TRAP);
}

void GameInterface::createBarracks(int x, int y, int player_id) {
    Barracks& barracks = model.createBarracks(x, y, player_id);
    view.addBuildingView(BuildingViewFactory::createBuildingView(barracks, view.getWindow()));
    model.getPlayer(player_id).buildingCenter->build(Building::BARRACKS);
}

void GameInterface::createLightFactory(int x, int y, int player_id) {
    LightFactory& lightF = model.createLightFactory(x, y, player_id);
    view.addBuildingView(BuildingViewFactory::createBuildingView(lightF, view.getWindow()));
    model.getPlayer(player_id).buildingCenter->build(Building::LIGHT_FACTORY);
}

void GameInterface::createHeavyFactory(int x, int y, int player_id) {
    HeavyFactory& heavyF = model.createHeavyFactory(x, y, player_id);
    view.addBuildingView(BuildingViewFactory::createBuildingView(heavyF, view.getWindow()));
    model.getPlayer(player_id).buildingCenter->build(Building::HEAVY_FACTORY);
}
void GameInterface::createSpiceRefinery(int x, int y, int player_id) {
    SpiceRefinery& spiceRef = model.createSpiceRefinery(x, y, player_id);
    view.addBuildingView(BuildingViewFactory::createBuildingView(spiceRef, view.getWindow()));
    model.getPlayer(player_id).buildingCenter->build(Building::SPICE_REFINERY);
}

void GameInterface::createSpiceSilo(int x, int y, int player_id) {
    SpiceSilo& spiceSilo = model.createSpiceSilo(x, y, player_id);
    view.addBuildingView(BuildingViewFactory::createBuildingView(spiceSilo, view.getWindow()));
    model.getPlayer(player_id).buildingCenter->build(Building::SPICE_SILO);
}

void GameInterface::beginConstruction(int player_id, Building::BuildingType type) {
    model.getPlayer(player_id).buildingCenter->newConstruct(type);
}