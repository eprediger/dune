#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include "Terrains/Terrain.h"
#include "Buildings/Building.h"
#include "Unit/Unit.h"
#include "Player.h"
#include <memory>
#include <map>
#include "../../Common/Area.h"
#include "Position.h"
#include <nlohmann/json.hpp>

// Configurar aca el tamaño de los bloques
#define BLOCK_HEIGHT 32
#define BLOCK_WIDTH 32

class Map {
private:
    std::vector<std::unique_ptr<Terrain> > matrix;
    int rows, cols;

    std::vector<Unit*> units;
    std::vector<Building*> buildings;

public:
    explicit Map(nlohmann::json& j);

    bool isValid(Position& pos);
    void put(Unit& unit);
    void put(Building& building);
    void occupy(Building& building);
    void free(Building& building);

    int getHeight();
    int getWidth();

    int getWidthInBlocks();
    int getHeightInBlocks();

    static int getBlockWidth();
    static int getBlockHeight();

    Unit * getClosestUnit(Position position, int limitRadius, Player& player);

    std::vector<Unit*> getUnitsInArea(Area& area, Player& player);
    std::vector<Unit*> getUnitsInArea(Area& area);

    std::vector<Building*> getBuildingsInArea(Area& area, Player& player);
    std::vector<Building*> getBuildingsInArea(Area& area);

    void cleanUnit(Unit* unit);
    void cleanBuilding(Building* building);

    bool canWeBuild(Position& pos, int width, int height);

    Position getClosestFreePosition(Building* building);
    Position getCornerPosition(Position& pos);

    Terrain& at(int x, int y);
    Terrain& blockAt(int x, int y);
    Terrain& at(const Position& pos);

    ~Map();
};

#endif //__MAP_H__
