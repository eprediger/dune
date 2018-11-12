#include "Map.h"

#include "Terrains/Precipice.h"
#include "Terrains/Summit.h"
#include "AStar.h"
#include "Common/CustomException.h"
#include "View/Area.h"
#include <algorithm>

Map::Map(int width, int height) :
    matrix(width * height / (BLOCK_HEIGHT * BLOCK_WIDTH)),
    rows(height / BLOCK_HEIGHT),
    cols(width / BLOCK_WIDTH) {
    //// TMP /////
    if (width % BLOCK_WIDTH != 0) {
        throw CustomException("Incorrect Width: %d", width); // Modificar luego
    }
    if  (height % BLOCK_HEIGHT) {
        throw CustomException("Incorrect Height: %d", height); // Modificar luego
    }

    for (int i = 0; i < width * height / (BLOCK_HEIGHT * BLOCK_WIDTH) ; i++) {
        matrix[i] = std::unique_ptr<Terrain>(new Sand());
    }

//    matrix.at(8*cols + 0) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(8*cols + 1) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(8*cols + 2) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(8*cols + 3) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(3*cols + 9) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(3*cols + 8) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(3*cols + 7) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(3*cols + 6) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(3*cols + 5) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(3*cols + 4) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(3*cols + 3) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(3*cols + 2) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(3*cols + 1) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(3*cols + 0) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(2*cols + 9) = std::unique_ptr<Terrain>(new Precipice());
//    matrix.at(1*cols + 9) = std::unique_ptr<Terrain>(new Sand());
//    matrix.at(0*cols + 9) = std::unique_ptr<Terrain>(new Precipice());
}

Map::Map() : matrix(640 * 480), rows(640), cols(480)  {}

Map::~Map() {}

int Map::getWidth() {
    return cols * BLOCK_WIDTH;
}

int Map::getHeight() {
    return rows * BLOCK_HEIGHT;
}

int Map::getWidthInBlocks() {
    return cols;
}

int Map::getHeightInBlocks() {
    return rows;
}

Terrain& Map::at(int x, int y) {
    return *matrix.at((y / BLOCK_HEIGHT) * cols + (x / BLOCK_WIDTH));
}

Terrain& Map::blockAt(int x, int y) {
    return *matrix.at(y * cols + x);
}

Terrain& Map::at(const Position& pos) {
    return *matrix.at((pos.getY() / BLOCK_HEIGHT) * cols + (pos.getX() / BLOCK_WIDTH));
}

bool Map::isValid(Position &pos) {
    return pos.getX() >= 0 && pos.getY() >= 0 && pos.getX() < cols * BLOCK_HEIGHT && pos.getY() < rows * BLOCK_WIDTH;
}

/*void Map::put(Attackable &attackable) {
   attackables.push_back(&attackable);
}
*/

void Map::put(Unit &unit) {
    units.push_back(&unit);
    this->at(unit.getPosition()).occupy();
}
void Map::put(Building &building) {
    buildings.push_back(&building);
    this->at(building.getPosition()).occupy();
}

bool Map::canMove(Unit& unit, Position pos) {
    return unit.canMoveAboveTerrain(this->at(pos)) && !this->at(pos).isOccupied();
}
//
//bool Map::moveUnits() {
//    bool result = false;
//    for (auto u : units) {
//        if (u->move()) {
//            result = true;
//        }
//    }
//    return result;
//}

void Map::setDestiny(Unit &unit, int x_dest, int y_dest) {
    AStar algorithm(*this);
    Position p_destiny(x_dest, y_dest);
    std::stack<Position> path = algorithm.makePath(unit, p_destiny);
    if (!path.empty()){
        this->at(unit.getPosition()).free();
    }
    unit.setPath(path, p_destiny);
}

Unit* Map::getClosestUnit(Unit &unit, int limitRadius) {
    Unit* closest_unit = nullptr;
    int closest_unit_distance = limitRadius;
    for (auto current_unit : units) {
        int distance = current_unit->getPosition().sqrtDistance(unit.getPosition());
        if (distance < limitRadius
                && distance < closest_unit_distance
                && !(*current_unit == unit)) {
            closest_unit = current_unit;
            closest_unit_distance = distance;
        }
    }

    return closest_unit;
}

Unit *Map::getClosestUnit(Position &position, int limitRadius) {
    Unit* closest_unit = nullptr;
    int closest_unit_distance = limitRadius;
    for (auto current_unit : units) {
        int distance = current_unit->getPosition().sqrtDistance(position);
        if (distance < limitRadius
                && distance < closest_unit_distance) {
            closest_unit = current_unit;
            closest_unit_distance = distance;
        }
    }

    return closest_unit;
}

Unit* Map::getClosestUnit(Position pos, int limitRadius, Player& player){
    Unit* closest_unit = nullptr;
    int closest_unit_distance = limitRadius;
    for (auto current_unit : units) {
        if (current_unit->getPlayer() == player){    
            int distance = current_unit->getPosition().sqrtDistance(pos);
            if (distance < limitRadius
                    && distance < closest_unit_distance) {
                closest_unit = current_unit;
                closest_unit_distance = distance;
            }
        }
    }

    return closest_unit;
}

std::vector<Unit*> Map::getUnitsInArea(Area& area, Player& player){
    std::vector<Unit*> answer;
    for (auto unit: units){
        if (unit->getPlayer() == player)
            if (unit->getPosition().x > area.getX())
                if (unit->getPosition().x < area.getX()+area.getWidth())
                    if (unit->getPosition().y > area.getY())
                        if (unit->getPosition().y < area.getY()+area.getHeight())
                            answer.emplace_back(unit);
    }
    if (answer.empty()){
        Unit* unit = getClosestUnit(Position(area.getX()+area.getWidth(),area.getY()+area.getHeight()),120,player);
        if (unit!=nullptr)
            answer.emplace_back(unit);
    }
    return (std::move(answer));
}


void Map::cleanDeadUnits() {
    bool has_dead_unit = false;
    for (auto u : units){
        if (Unit::isDead(u)){
            has_dead_unit = true;
            this->at(u->getPosition()).free();
        }
    }
    if (has_dead_unit) {
        units.erase(std::remove_if(units.begin(), units.end(), Unit::isDead));
    }
}


Building * Map::getClosestBuilding(Position &position, int limitRadius) {
    Building* closest_unit = nullptr;
    int closest_unit_distance = limitRadius;
    for (auto current_building : buildings) {
        int distance = current_building->getPosition().sqrtDistance(position);
        if (distance < limitRadius
            && distance < closest_unit_distance) {
            closest_unit = current_building;
            closest_unit_distance = distance;
        }
    }

    return closest_unit;
}

//Unit *Map::getClosestAllyUnit(Position &position, int limitRadius, Player &player) {
//    Unit* closest_unit = nullptr;
//    int closest_unit_distance = limitRadius;
//    for (auto current_unit : units){
//        int distance = current_unit->getPosition().sqrtDistance(position);
//        if (distance < limitRadius
//            && distance < closest_unit_distance
//            && player.hasUnit(current_unit)){
//            closest_unit = current_unit;
//            closest_unit_distance = distance;
//        }
//    }
//
//    return closest_unit;
//}


//Unit *Map::getClosestEnemyUnit(Position &position, int limitRadius, Unit &ally_unit) {
//    Unit* closest_unit = nullptr;
//    int closest_unit_distance = limitRadius;
//    for (auto current_unit : units){
//        int distance = current_unit->getPosition().sqrtDistance(position);
//        if (distance < limitRadius
//            && distance < closest_unit_distance
////            && !(current_unit->getPlayer() == ally_unit.getPlayer())
//            ){
//            closest_unit = current_unit;
//            closest_unit_distance = distance;
//        }
//    }
//
//    return closest_unit;
//}

void Map::cleanUnit(Unit *unit) {
    units.erase(std::find(units.begin(), units.end(), unit));
}

Unit *Map::getClosestUnit(Position &position, int limitRadius, Player& player, bool has) {
    Unit* closest_unit = nullptr;
    int closest_unit_distance = limitRadius;
    for (auto current_unit : units){
        int distance = current_unit->getPosition().sqrtDistance(position);
        if (distance < limitRadius
            && distance < closest_unit_distance
            && !( player == current_unit->getPlayer() ^  has)){
            closest_unit = current_unit;
            closest_unit_distance = distance;
        }
    }

    return closest_unit;
}


