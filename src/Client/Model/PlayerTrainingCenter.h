#ifndef __PLAYER_TRAINING_CENTER_H__
#define __PLAYER_TRAINING_CENTER_H__

class Harvester;
class HeavyInfantry;
class LightInfantry;
class Raider;
class Trike;
class Tank;
class Unit;
class Building;
class ConstructionYard;
class Map;
#include <vector>
#include <utility>
#include <nlohmann/json.hpp>
class PlayerTrainingCenter {
public:
    PlayerTrainingCenter(nlohmann::json& j);

    void update(nlohmann::json& j);

    bool isTrainingLightInfantry();
    bool isTrainingHeavyInfantry();
    bool isTrainingHarvester();
    bool isTrainingTank();
    bool isTrainingRaider();
    bool isTrainingTrike();

private:
    std::pair<int, bool> harvester;
    std::pair<int, bool> lightInfantry;
    std::pair<int, bool> heavyInfantry;
    std::pair<int, bool> raider;
    std::pair<int, bool> tank;
    std::pair<int, bool> trike;
};

#endif
