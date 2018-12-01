#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include <nlohmann/json.hpp>
#include "Terrains/Terrain.h"
#include "Model/Buildings/Building.h"
#include "Unit/Unit.h"
#include "Player.h"
#include <memory>
#include <map>
#include <Area.h>
#include "Position.h"
// Configurar aca el tamaño de los bloques
#define BLOCK_HEIGHT 32
#define BLOCK_WIDTH 32

class Map {
private:
    std::vector<std::unique_ptr<Terrain> > matrix;
    int rows, cols;
    std::vector<Position> constructionYardPositions;
    // Esto deberia reemplazarse luego por un vector de Attackable. Hay que reemplazar Unit en getClosestUnit para hacer esto
    std::vector<Attackable*> attackables;
    std::vector<Unit*> units;
    std::vector<Building*> buildings;
    nlohmann::json serialization;
    bool news;
    nlohmann::json spiceUpdate;

public:
    explicit Map(const char* filePath);

    std::vector<Position>& getInitialPositions();

    bool isValid(Position& pos);
    bool canMove(Unit& unit, Position pos);
    void put(Unit& unit);
    void put(Building* building);
    void occupy(Building* building);
    void free(Building& building);

    nlohmann::json& getSerialization();
    bool hasNews();
    void updateSpice(int x, int y);
    nlohmann::json& getSpiceUpdate();
    int getHeight();
    int getWidth();

    int getWidthInBlocks();
    int getHeightInBlocks();

    int getBlockWidth();
    int getBlockHeight();

    Unit * getClosestUnit(Position position, int limitRadius, Player& player);
    Attackable * getClosestAttackable(Position &position, int limitRadius, Player& player);

    std::vector<Unit*> getUnitsInArea(Area& area, Player& player);
    std::vector<Unit*> getUnitsInArea(Area& area);

    std::vector<Building*> getBuildingsInArea(Area& area, Player& player);
    std::vector<Building*> getBuildingsInArea(Area& area);

    void setDestiny(Unit& unit, int x_dest, int y_dest);

    void cleanUnit(Unit* unit);
    void cleanBuilding(Building* building);

    bool canWeBuild(Position& pos, int width, int height, Player& player);

    Position getClosestFreePosition(Building* building);
    Position getCornerPosition(Position& pos);
    Position getClosestSpeciaPosition(Position pos, int radius);

    Terrain& at(int x, int y);
    Terrain& blockAt(int x, int y);
    Terrain& at(const Position& pos);

    int getSpeedFactorAt(Position& pos);

    ~Map();
};

#endif //__MAP_H__
