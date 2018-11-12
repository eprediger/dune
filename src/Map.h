#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include "Terrains/Terrain.h"
#include "Positionable.h"
#include "Buildings/Building.h"
#include "Unit/Unit.h"
#include "Player.h"
#include <memory>
#include "View/Area.h"
// Configurar aca el tamaño de los bloques
#define BLOCK_HEIGHT 32
#define BLOCK_WIDTH 32

class Map {
private:
    std::vector<std::unique_ptr<Terrain>> matrix;
    int rows, cols;
    // Esto deberia reemplazarse luego por un vector de Attackable. Hay que reemplazar Unit en getClosestUnit para hacer esto
    std::vector<Attackable*> attackables;
    std::vector<Unit*> units;
    std::vector<Building*> buildings;
public:
    Map();
    Map(int width, int height);

    bool isValid(Position& pos);
    bool canMove(Unit& unit, Position pos);
//    void put(Attackable& attackable);
    void put(Unit& unit);
    void put(Building& building);
//    bool moveUnits();

    int getHeight();
    int getWidth();

    int getWidthInBlocks();
    int getHeightInBlocks();

    Unit * getClosestUnit(Unit &unit, int limitRadius);
    Unit * getClosestUnit(Position& position, int limitRadius);
    Unit * getClosestUnit(Position position, int limitRadius, Player& player);
    Building * getClosestBuilding(Position &position, int limitRadius);
//    Unit *getClosestAllyUnit(Position &position, int limitRadius, Player &player);
    Unit * getClosestUnit(Position &position, int limitRadius, Player& player, bool has);


    std::vector<Unit*> getUnitsInArea(Area& area, Player& player );

//    Unit* getClosestEnemyUnit(Position &position, int limitRadius, Unit &ally_unit);

    std::vector<Unit*> getUnitsInArea(Area& area, Player& player );


    void setDestiny(Unit& unit, int x_dest, int y_dest);

    void cleanDeadUnits();
    void cleanUnit(Unit* unit);

    Terrain& at(int x, int y);
    Terrain& blockAt(int x, int y);
    Terrain& at(const Position& pos);

    ~Map();

};

#endif //__MAP_H__
