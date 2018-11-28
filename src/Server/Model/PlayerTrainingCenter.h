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
    PlayerTrainingCenter();
    void trainHarvester(Harvester* harvester);
    void trainLightInfantry(LightInfantry* lightInfantry);
    void trainHeavyInfantry(HeavyInfantry* heavyInfantry);
    void trainRaider(Raider* raider);
    void trainTrike(Trike* trike);
    void trainTank(Tank* tank);
    void trainUnits(std::vector<Building*>& buildings);
    std::vector<Unit*>& getReadyUnits(Map& map, std::vector<Building*>& buildings,
                                      ConstructionYard* constructionYard);

    nlohmann::json& getSerialization();
    bool isTrainingLightInfantry();
    bool isTrainingHeavyInfantry();
    bool isTrainingHarvester();
    bool isTrainingTank();
    bool isTrainingRaider();
    bool isTrainingTrike();

private:
    std::pair<int, Harvester*> harvester;
    std::pair<int, LightInfantry*> lightInfantry;
    std::pair<int, HeavyInfantry*> heavyInfantry;
    std::pair<int, Raider*> raider;
    std::pair<int, Tank*> tank;
    std::pair<int, Trike*> trike;
    std::vector<Unit*>readyUnits;
    nlohmann::json serialization;
};

#endif
