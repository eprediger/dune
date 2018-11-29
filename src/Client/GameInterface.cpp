#include "GameInterface.h"
#include "View/BuildingViewFactory.h"
#include "View/UnitViewFactory.h"
#include <iostream>

GameInterface::GameInterface(Model &model, GameView &view) :
    model(model), view(view) {}

void GameInterface::execute(nlohmann::json j) {
    if (j["class"] == "Player"){
        if (model.playerExists(j["id"]))
            model.updatePlayer(j);
        else
            model.addPlayer(j);
    }
    else if (j["class"] == "Unit"){
        std::cout<<j["subclass"]<<std::endl;
        if (model.unitExists(j["id"])){
            model.updateUnit(j);
        }
        else {
            if (j["subClass"] == "Harvester"){
                Harvester& harvester = model.createHarvester(j);
                view.addUnitView(UnitViewFactory::createUnitView(harvester,view.getWindow()));
            }
            else if (j["subClass"] == "LightInfantry"){
                LightInfantry& unit = model.createLightInfantry(j);
                view.addUnitView(UnitViewFactory::createUnitView(unit,view.getWindow()));
            }
            else if (j["subClass"] == "HeavyInfantry"){
                HeavyInfantry& unit = model.createHeavyInfantry(j); 
                view.addUnitView(UnitViewFactory::createUnitView(unit,view.getWindow())); 
            }
            else if (j["subClass"] == "Trike"){
                Trike& unit = model.createTrike(j);
                view.addUnitView(UnitViewFactory::createUnitView(unit,view.getWindow()));
            }
            else if (j["subClass"] == "Raider"){
                Raider& unit = model.createRaider(j);
                view.addUnitView(UnitViewFactory::createUnitView(unit,view.getWindow()));
            }
            else if (j["subClass"] == "Tank"){
                Tank& unit = model.createTank(j);
                view.addUnitView(UnitViewFactory::createUnitView(unit,view.getWindow()));
            }
        }
    }
    else if (j["class"] == "Building"){
        if (model.buildingExists(j["id"])){
            model.updateBuilding(j);
        }
        else {
            if (j["type"] == Building::BARRACKS){
                Barracks& building = model.createBarracks(j);
                view.addBuildingView(BuildingViewFactory::createBuildingView(building,view.getWindow()));
            } 
            if (j["type"] == Building::LIGHT_FACTORY){
                LightFactory& building = model.createLightFactory(j);
                view.addBuildingView(BuildingViewFactory::createBuildingView(building,view.getWindow()));
            } 
            if (j["type"] == Building::HEAVY_FACTORY){
                HeavyFactory& building = model.createHeavyFactory(j);
                view.addBuildingView(BuildingViewFactory::createBuildingView(building,view.getWindow()));
            } 
            if (j["type"] == Building::CONSTRUCTION_YARD){
                ConstructionYard& building = model.createConstructionYard(j);
                view.addBuildingView(BuildingViewFactory::createBuildingView(building,view.getWindow()));
            } 
            if (j["type"] == Building::SPICE_REFINERY){
                SpiceRefinery& building = model.createSpiceRefinery(j);
                view.addBuildingView(BuildingViewFactory::createBuildingView(building,view.getWindow()));
            } 
            if (j["type"] == Building::SPICE_SILO){
                SpiceSilo& building = model.createSpiceSilo(j);
                view.addBuildingView(BuildingViewFactory::createBuildingView(building,view.getWindow()));
            } 
            if (j["type"] == Building::WIND_TRAP){
                WindTrap& building = model.createWindTrap(j);
                view.addBuildingView(BuildingViewFactory::createBuildingView(building,view.getWindow()));
            } 
        }
    }
    else if (j["class"] == "Rocket"){
        if (model.rocketExists(j["id"])){
            model.updateRocket(j);
        }
        else{
            Rocket& rocket = model.createRocket(j);
            view.addRocketView(new RocketView(rocket,view.getWindow()));
        }
    }

}
