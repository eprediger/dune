#include "PlayerTrainingCenter.h"
#include "Model/GlobalConfig.h"

#include "Unit/HeavyInfantry.h"
#include "Unit/LightInfantry.h"
#include "Unit/Raider.h"
#include "Unit/Trike.h"
#include "Unit/Tank.h"
#include "Unit/Harvester.h"
#include "Unit/Unit.h"
#include "Model/Buildings/Building.h"
#include <vector>

PlayerTrainingCenter::PlayerTrainingCenter(nlohmann::json& j) :
        harvesterPressed(false),
        lightInfantryPressed(false),
        heavyInfantryPressed(false),
        raiderPressed(false),
        tankPressed(false),
        trikePressed(false) {
    update(j);
}

void PlayerTrainingCenter::update(nlohmann::json& j) {
    harvester.first = (j["harvesterTime"]);
    harvester.second = (j["trainingHarvester"]);
    lightInfantry.first = j["lightInfantryTime"];
    lightInfantry.second = j["trainingLightInfantry"];
    heavyInfantry.first = j["heavyInfantryTime"];
    heavyInfantry.second = j["trainingHeavyInfantry"];
    raider.first = j["raiderTime"];
    raider.second = j["trainingRaider"];
    tank.first = j["tankTime"];
    tank.second = j["trainingTank"];
    trike.first = j["trikeTime"];
    trike.second = j["trainingTrike"];

    if(harvesterPressed && harvester.first > 0){
        harvesterPressed = false;
    }
    if(lightInfantryPressed && (lightInfantry.first > 0)){
        lightInfantryPressed = false;
    }
    if(heavyInfantryPressed && heavyInfantry.first > 0){
        heavyInfantryPressed = false;
    }
    if(raiderPressed && raider.first > 0){
        raiderPressed = false;
    }
    if(tankPressed && tank.first > 0){
        tankPressed = false;
    }
    if(trikePressed && trike.first > 0){
        trikePressed = false;
    }
}

bool PlayerTrainingCenter::isTrainingLightInfantry() {
    return ((lightInfantry.first > 0) && (lightInfantry.second == true))||lightInfantryPressed;
}

bool PlayerTrainingCenter::isTrainingHeavyInfantry() {
    return ((heavyInfantry.first > 0) && (heavyInfantry.second == true))||heavyInfantryPressed;
}

bool PlayerTrainingCenter::isTrainingHarvester() {
    return ((harvester.first > 0) && (harvester.second == true))||harvesterPressed;
}

bool PlayerTrainingCenter::isTrainingTank() {
    return ((tank.first > 0) && (tank.second == true))||tankPressed;
}

bool PlayerTrainingCenter::isTrainingRaider() {
    return ((raider.first > 0) && (raider.second == true))||raiderPressed;
}

bool PlayerTrainingCenter::isTrainingTrike() {
    return ((trike.first > 0) && (trike.second == true))||trikePressed;
}


void PlayerTrainingCenter::beginTrainingLightInfantry(){
    lightInfantryPressed = true;
}
void PlayerTrainingCenter::beginTrainingHeavyInfantry(){
    heavyInfantryPressed = true;
}
void PlayerTrainingCenter::beginTrainingHarvester(){
    harvesterPressed = true;
}
void PlayerTrainingCenter::beginTrainingTank(){
    tankPressed = true;
}
void PlayerTrainingCenter::beginTrainingRaider(){
    raiderPressed = true;
}
void PlayerTrainingCenter::beginTrainingTrike(){
    trikePressed = true;
}