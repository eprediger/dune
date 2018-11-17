#include "Map.h"
#include "Terrains/Precipice.h"
#include "Terrains/Summit.h"
#include "AStar.h"
#include "../Common/CustomException.h"
#include "../View/Area.h"
#include <algorithm>
#include <stack>
#include <vector>

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
    if (x < 0 || y < 0){
        throw (std::out_of_range("Out of range"));
    }
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
    this->occupy(building);
}

void Map::occupy(Building &building) {
    for (int i = 0; i < building.height; i++) {
        for (int j = 0; j < building.width; j++) {
            this->at(building.getPosition().x + j * BLOCK_WIDTH, building.getPosition().y + i * BLOCK_HEIGHT).buildOn();
        }
    }
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
    if (!path.empty()) {
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

Unit* Map::getClosestUnit(Position pos, int limitRadius, Player& player) {
    Unit* closest_unit = nullptr;
    int closest_unit_distance = limitRadius;
    for (auto current_unit : units) {
        if (current_unit->getPlayer() == player) {
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

std::vector<Unit*> Map::getUnitsInArea(Area& area, Player& player) {
    std::vector<Unit*> answer;
    for (auto unit : units) {
        if (unit->getPlayer() == player)
            if (unit->getPosition().x > area.getX())
                if (unit->getPosition().x < area.getX() + area.getWidth())
                    if (unit->getPosition().y > area.getY())
                        if (unit->getPosition().y < area.getY() + area.getHeight())
                            answer.emplace_back(unit);
    }
    if (answer.empty()) {
        Unit* unit = getClosestUnit(Position(area.getX() + area.getWidth(), area.getY() + area.getHeight()), 120, player);
        if (unit != nullptr)
            answer.emplace_back(unit);
    }
    return (std::move(answer));
}

void Map::cleanDeadUnits() {
    bool has_dead_unit = false;
    for (auto u : units) {
        if (Unit::isDead(u)) {
            has_dead_unit = true;
            this->at(u->getPosition()).free();
        }
    }
    if (has_dead_unit) {
        units.erase(std::remove_if(units.begin(), units.end(), Unit::isDead), units.end());
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
    this->at(unit->getPosition()).free();
    units.erase(std::find(units.begin(), units.end(), unit));
}

void Map::cleanBuilding(Building *building) {
    this->free(*building);
    buildings.erase(std::find(buildings.begin(), buildings.end(), building));
}

void Map::free(Building &building) {
    for (int i = 0; i<building.height; i++){
        for (int j = 0; j<building.width; j++){
            this->at(building.getPosition().x + j*BLOCK_WIDTH,building.getPosition().y + i*BLOCK_HEIGHT).free();
        }
    }
}

bool Map::canWeBuild(Position& pos, int width, int height){
    try{
        for (int i = 0; i<height; i++){
            for (int j = 0; j<width;j++){
                if (this->at(pos.getX()+j*BLOCK_WIDTH,pos.getY()+i*BLOCK_HEIGHT).isOccupied()){
                   return false;
                }
            }
        }

        for (int i = -5; i <= height + 5; i++) {
            for (int j = -5; j <= height + 5; j++) {
                if (this->at(pos.getX() + j * BLOCK_WIDTH, pos.getY() + i * BLOCK_HEIGHT).isBuiltOn()) {
                   return false;
                }
            }
        }
        return true;
    } catch (std::out_of_range& e) {
        return false;
    }
}


Position Map::getClosestFreePosition(Building* building){
    int dist = 1;
    bool found = false;
    Position& pos = building->getPosition();
    while(!found){
        for (int i = - dist; i<=building->height + dist; i++){
            for (int j =  - dist; j<=building->width + dist; j++){
                try{
                    if (!(this->at(pos.x + j*BLOCK_WIDTH, pos.y + i*BLOCK_HEIGHT).isOccupied())){
                        return Position(pos.x + j*BLOCK_WIDTH, pos.y + i*BLOCK_HEIGHT);
                    }
                }
                catch(std::out_of_range& e){}
            }
        }
        dist+=1;
    }
    return pos;
}

Unit *Map::getClosestUnit(Position &position, int limitRadius, Player& player, bool has) {
    Unit* closest_unit = nullptr;
    int closest_unit_distance = limitRadius;
    for (auto current_unit : units) {
        int distance = current_unit->getPosition().sqrtDistance(position);
        if (distance < limitRadius
                && distance < closest_unit_distance
                && !( (player == current_unit->getPlayer()) ^  has)) {
            closest_unit = current_unit;
            closest_unit_distance = distance;
        }
    }
    return closest_unit;
}

Attackable *Map::getClosestAttackable(Position &position, int limitRadius, Player& player) {
    Attackable* closest_attackable = nullptr;
    int closest_unit_distance = limitRadius;
    for (auto current_unit : units){
        int distance = current_unit->getPosition().sqrtDistance(position);
        if (distance < limitRadius
            && distance < closest_unit_distance
            && !( player == current_unit->getPlayer())){
            closest_attackable = current_unit;
            closest_unit_distance = distance;
        }
    }

    for (auto current_building : buildings){
        int distance = current_building->getPosition().sqrtDistance(position);
        if (distance < limitRadius
            && distance < closest_unit_distance
            && !player.hasBuilding(*current_building) ){
            closest_attackable = current_building;
            closest_unit_distance = distance;
        }
    }

    return closest_attackable;
}

Position Map::getCornerPosition(Position& pos){
    return Position((pos.x/BLOCK_WIDTH)*BLOCK_WIDTH, (pos.y/BLOCK_HEIGHT)*BLOCK_HEIGHT);
}
Position Map::getClosestSpeciaPosition(Position pos, int radius) {
    int block_x = (pos.x / BLOCK_HEIGHT);
    int block_y = (pos.y / BLOCK_WIDTH);
    int min_distance = radius + 1;
    Position min_position = pos;
    for (int i = -radius; i<=+radius; ++i){
        for (int j = -(radius - abs(i)); j<=+(radius - abs(i)); ++j){
            int cur_pos_x = (block_x + j);
            int cur_pos_y = (block_y + i);
            if ((cur_pos_y + i) >= 0 &&
                    (cur_pos_y + i) < cols &&
                    (cur_pos_x + j)>=0 &&
                    (cur_pos_x + j) <rows){
                if ( abs(i) + abs(j) < min_distance
                        && this->blockAt(cur_pos_x, cur_pos_y).hasFarm()){
                    min_distance = abs(i) + abs(j);
                    min_position = Position(cur_pos_x*BLOCK_HEIGHT, cur_pos_y*BLOCK_WIDTH);
                }
            }
        }
    }

    return min_position;
}



