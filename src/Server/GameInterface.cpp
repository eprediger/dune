#include "GameInterface.h"

GameInterface::GameInterface(Model &model) :
    model(model) {}

void GameInterface::execute(nlohmann::json json) {
    if ( json["method"] == "createWindTrap"){
        this->createWindTrap(json["args"]["x"],json["args"]["y"],json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "createBarracks"){
        this->createBarracks(json["args"]["x"],json["args"]["y"],json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "createLightFactory"){
        this->createLightFactory(json["args"]["x"],json["args"]["y"],json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "createHeavyFactory"){
        this->createHeavyFactory(json["args"]["x"],json["args"]["y"],json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "createSpiceRefinery"){
        this->createSpiceRefinery(json["args"]["x"],json["args"]["y"],json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "createSpiceSilo"){
        this->createSpiceSilo(json["args"]["x"],json["args"]["y"],json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "beginConstruction"){
        this->beginConstruction(json["args"]["player_id"],json["args"]["building_type"]);
        return;
    }
    if ( json["method"] == "createHarvester"){
        this->createHarvester(json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "createHeavyInfantry"){
        this->createHeavyInfantry(json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "createLightInfantry"){
        this->createLightInfantry(json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "createRaider"){
        this->createRaider(json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "createTank"){
        this->createTank(json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "createTrike"){
        this->createTrike(json["args"]["player_id"]);
        return;
    }
    if ( json["method"] == "sellBuilding"){
        this->sellBuilding(json["args"]["player_id"], json["args"]["building_id"]);
        return;
    }
    if ( json["method"] == "actionOnPosition"){
        this->setActionOnPosition(json["args"]["player_id"],json["args"]["unit_id"],json["args"]["x"],json["args"]["y"]);
    }
}

void GameInterface::createWindTrap(int x, int y, int player_id) {
    // WindTrap& windtrap =
    model.createWindTrap(x, y, player_id);
    model.getPlayer(player_id).buildingCenter->build(Building::WIND_TRAP);
}

void GameInterface::createBarracks(int x, int y, int player_id) {
    // Barracks& barracks =
    model.createBarracks(x, y, player_id);
    model.getPlayer(player_id).buildingCenter->build(Building::BARRACKS);
}

void GameInterface::createLightFactory(int x, int y, int player_id) {
    // LightFactory& lightF =
    model.createLightFactory(x, y, player_id);
    model.getPlayer(player_id).buildingCenter->build(Building::LIGHT_FACTORY);
}

void GameInterface::createHeavyFactory(int x, int y, int player_id) {
    // HeavyFactory& heavyF =
    model.createHeavyFactory(x, y, player_id);
    model.getPlayer(player_id).buildingCenter->build(Building::HEAVY_FACTORY);
}
void GameInterface::createSpiceRefinery(int x, int y, int player_id) {
    // SpiceRefinery& spiceRef =
    model.createSpiceRefinery(x, y, player_id);
    model.getPlayer(player_id).buildingCenter->build(Building::SPICE_REFINERY);
}

void GameInterface::createSpiceSilo(int x, int y, int player_id) {
    // SpiceSilo& spiceSilo =
    model.createSpiceSilo(x, y, player_id);
    model.getPlayer(player_id).buildingCenter->build(Building::SPICE_SILO);
}

void GameInterface::beginConstruction(int player_id, Building::BuildingType type) {
    model.getPlayer(player_id).buildingCenter->newConstruct(type);
}

void GameInterface::createHarvester(int player_id) {
    // Harvester& newUnit =
    model.createHarvester(0, 0, player_id);
}
void GameInterface::createHeavyInfantry(int player_id) {
    // HeavyInfantry& newUnit =
    model.createHeavyInfantry(0, 0, player_id);
}
void GameInterface::createLightInfantry(int player_id) {
    // LightInfantry& newUnit =
    model.createLightInfantry(0, 0, player_id);
}
void GameInterface::createRaider(int player_id) {
    // Raider& newUnit =
    model.createRaider(0, 0, player_id);
}
void GameInterface::createTank(int player_id) {
    // Tank& newUnit =
    model.createTank(0, 0, player_id);
}
void GameInterface::createTrike(int player_id) {
    // Trike& newUnit =
    model.createTrike(0, 0, player_id);
}

void GameInterface::sellBuilding(int player_id, int building_id) {
    try {
        model.getPlayer(player_id).sellBuilding(&model.getBuildingById(building_id));
    }
    catch (std::out_of_range& e) {

    }
}

void GameInterface::setActionOnPosition(int player_id, int unit_id, int x, int y) {
    try {
        Unit& unit = model.getUnitById(unit_id);
        Position pos(x, y);
        model.actionOnPosition(pos, unit);
    }
    catch (std::out_of_range& ) {

    }
}
