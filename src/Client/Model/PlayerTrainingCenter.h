#ifndef __PLAYER_TRAINING_CENTER_H__
#define __PLAYER_TRAINING_CENTER_H__

#include <map>
#include <utility>
#include <nlohmann/json.hpp>
#include "Unit/Unit.h"
#include <mutex> 

class PlayerTrainingCenter {
public:
    explicit PlayerTrainingCenter(nlohmann::json& j);

    void update(nlohmann::json& j);

    bool isTrainingLightInfantry();
    bool isTrainingHeavyInfantry();
    bool isTrainingHarvester();
    bool isTrainingTank();
    bool isTrainingRaider();
    bool isTrainingTrike();

    void beginTraining(Unit::UnitType type);

    int remainingTime(Unit::UnitType unitType);

private:
    std::map<Unit::UnitType,int> units;
    std::mutex m;
};

#endif
