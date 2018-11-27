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

PlayerTrainingCenter::PlayerTrainingCenter(nlohmann::json& j)
{
        update(j);
}


void PlayerTrainingCenter::update(nlohmann::json& j){
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
}

bool PlayerTrainingCenter::isTrainingLightInfantry() {
    return ((lightInfantry.first > 0) && (lightInfantry.second == true));
}

bool PlayerTrainingCenter::isTrainingHeavyInfantry() {
    return ((heavyInfantry.first > 0) && (heavyInfantry.second == true));
}

bool PlayerTrainingCenter::isTrainingHarvester() {
    return ((harvester.first > 0) && (harvester.second == true));
}

bool PlayerTrainingCenter::isTrainingTank() {
    return ((tank.first > 0) && (tank.second == true));
}

bool PlayerTrainingCenter::isTrainingRaider() {
    return ((raider.first > 0) && (raider.second == true));
}

bool PlayerTrainingCenter::isTrainingTrike() {
    return ((trike.first > 0) && (trike.second == true));
}
