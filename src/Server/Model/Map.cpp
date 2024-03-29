#include "Map.h"
#include "yaml-cpp/yaml.h"
#include <nlohmann/json.hpp>
#include "Terrains/Terrain.h"
#include "Model/AStar.h"
#include "CustomException.h"
#include <Area.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <fstream>

Map::Map(const char* filePath) :
    matrix(),
    rows(),
    cols(),
    constructionYardPositions(),
    serialization(),
    news(false),
    spiceUpdate() {
    YAML::Node file = YAML::LoadFile(filePath);
    cols = file["width"].as<int>();
    rows = file["height"].as<int>();
    serialization["class"] = "Map";
    char sand_key = file["SAND_KEY"].as<char>();
    serialization["sand_key"] = sand_key;
    char spiced_sand_key = file["SPICED_SAND_KEY"].as<char>();
    serialization["spiced_sand_key"] = spiced_sand_key;
    char dune_key = file["DUNE_KEY"].as<char>();
    serialization["dune_key"] = dune_key;
    char rocks_key = file["ROCK_KEY"].as<char>();
    serialization["rocks_key"] = rocks_key;
    char summit_key = file["SUMMIT_KEY"].as<char>();
    serialization["summit_key"] = summit_key;
    char precipice_key = file["PRECIPICE_KEY"].as<char>();
    serialization["precipice_key"] = precipice_key;
    int initial_spice = file["INITIAL_SPICE"].as<int>();
    serialization["initial_spice"] = initial_spice;
    int max_players = file["max_players"].as<int>();
    serialization["width"] = cols;
    serialization["height"] = rows;
    nlohmann::json keys = nlohmann::json::array();
    for (int i = 0; i < max_players ; i++) {
        int x = file["initial_positions"][i][0].as<int>() * BLOCK_WIDTH;
        int y = file["initial_positions"][i][1].as<int>() * BLOCK_HEIGHT;
        constructionYardPositions.emplace_back(Position(x, y));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char key = file["rows"][i][j].as<char>();
            if (key == sand_key) {
                matrix.emplace_back(std::unique_ptr<Terrain>(new Sand(0)));
            } else if (key == spiced_sand_key) {
                matrix.emplace_back(std::unique_ptr<Terrain>(new Sand(initial_spice)));
            } else if (key == dune_key) {
                matrix.emplace_back(std::unique_ptr<Terrain>(new Dunes()));
            } else if (key == rocks_key) {
                matrix.emplace_back(std::unique_ptr<Terrain>(new Rocks()));
            } else if (key == summit_key) {
                matrix.emplace_back(std::unique_ptr<Terrain>(new Summit()));
            } else if (key == precipice_key) {
                matrix.emplace_back(std::unique_ptr<Terrain>(new Precipice()));
            }
            keys.push_back(key);
        }
    }
    serialization["matrix"] = keys;

    spiceUpdate["class"] = "SpiceUpdate";
}

Map::~Map() {}

nlohmann::json& Map::getSerialization() {
    return this->serialization;
}

bool Map::hasNews(){
    return this->news;
}

void Map::updateSpice(int x, int y){
    if (!news){
        spiceUpdate["updates"].clear();
        news = true;
    }
    spiceUpdate["updates"].push_back({x,y});
}

nlohmann::json& Map::getSpiceUpdate(){
    news = false;
    return spiceUpdate;
}
std::vector<Position>& Map::getInitialPositions() {
    return constructionYardPositions;
}

int Map::getWidth() {
    return cols * BLOCK_WIDTH;
}

int Map::getHeight() {
    return rows * BLOCK_HEIGHT;
}

int Map::getBlockWidth() {
    return BLOCK_WIDTH;
}

int Map::getBlockHeight() {
    return BLOCK_HEIGHT;
}

int Map::getWidthInBlocks() {
    return cols;
}

int Map::getHeightInBlocks() {
    return rows;
}

Terrain& Map::at(int x, int y) {
    if ((x < 0) || (y < 0)) {
        throw std::out_of_range("Out of range");
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

void Map::put(Unit &unit) {
    units.push_back(&unit);
    this->at(unit.getPosition()).occupy();
}

void Map::put(Building* building) {
    buildings.push_back(building);
    this->occupy(building);
}

void Map::occupy(Building* building) {
    for (int i = 0; i < building->height; i++) {
        for (int j = 0; j < building->width; j++) {
            this->at(building->getPosition().x + j * BLOCK_WIDTH, building->getPosition().y + i * BLOCK_HEIGHT).buildOn(building);
        }
    }
}

bool Map::canMove(Unit& unit, Position pos) {
    return unit.canMoveAboveTerrain(this->at(pos)) && !this->at(pos).isOccupied();
}

void Map::setDestiny(Unit &unit, int x_dest, int y_dest) {
    AStar algorithm(*this);
    Position p_destiny(x_dest, y_dest);
    std::stack<Position> path = algorithm.makePath(unit, p_destiny);
    if (!path.empty()) {
        this->at(unit.getPosition()).free();
    }
    unit.setPath(path, p_destiny);
}

Unit* Map::getClosestUnit(Position pos, int limitRadius, Player& player) {
    Unit* closest_unit = nullptr;
    int closest_unit_distance = limitRadius;
    for (auto& current_unit : units) {
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
    for (auto& unit : units) {
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

std::vector<Unit*> Map::getUnitsInArea(Area& area) {
    std::vector<Unit*> answer;
    for (auto& unit : units) {
        if (unit->getPosition().x > area.getX())
            if (unit->getPosition().x < area.getX() + area.getWidth())
                if (unit->getPosition().y > area.getY())
                    if (unit->getPosition().y < area.getY() + area.getHeight())
                        answer.emplace_back(unit);
    }
    return (std::move(answer));
}

std::vector<Building*> Map::getBuildingsInArea(Area& area, Player& player) {
    std::vector<Building*> answer;
    Position pos(area.getX() + area.getWidth(), area.getY() + area.getHeight());
    for (auto& building : buildings) {
        if ((*building->getPlayer()) == player) {
            if ( (building->getPosition().x > area.getX()) &&
                    (building->getPosition().x + building->width * BLOCK_WIDTH < area.getX() + area.getWidth()) &&
                    (building->getPosition().y > area.getY()) &&
                    (building->getPosition().y + building->height * BLOCK_HEIGHT < area.getY() + area.getHeight())) {
                answer.emplace_back(building);
            } else {
                if ((pos.x > building->getPosition().x) && (pos.x < building->getPosition().x + building->width * BLOCK_WIDTH) &&
                        (pos.y > building->getPosition().y) && (pos.y < building->getPosition().y + building->height * BLOCK_HEIGHT)) {
                    answer.emplace_back(building);
                }
            }
        }
    }
    return std::move(answer);
}

std::vector<Building*> Map::getBuildingsInArea(Area& area) {
    std::vector<Building*> answer;
    Position pos(area.getX() + area.getWidth(), area.getY() + area.getHeight());
    Position areaCenter(area.getX() + area.getWidth() / 2, area.getY() + area.getHeight() / 2);
    for (auto& building : buildings) {
        if ( (building->getClosestPosition(areaCenter).x > area.getX()) &&
                (building->getClosestPosition(areaCenter).x + building->width * BLOCK_WIDTH < area.getX() + area.getWidth()) &&
                (building->getClosestPosition(areaCenter).y > area.getY()) &&
                (building->getClosestPosition(areaCenter).y + building->height * BLOCK_HEIGHT < area.getY() + area.getHeight())) {
            answer.emplace_back(building);
        } else {
            if ((pos.x > building->getClosestPosition(areaCenter).x) && (pos.x < building->getClosestPosition(areaCenter).x + building->width * BLOCK_WIDTH) &&
                    (pos.y > building->getClosestPosition(areaCenter).y) && (pos.y < building->getClosestPosition(areaCenter).y + building->height * BLOCK_HEIGHT)) {
                answer.emplace_back(building);
            }
        }
    }
    return std::move(answer);
}

void Map::cleanUnit(Unit *unit) {
    this->at(unit->getPosition()).free();
    units.erase(std::find(units.begin(), units.end(), unit));
}

void Map::cleanBuilding(Building *building) {
    this->free(*building);
    buildings.erase(std::find(buildings.begin(), buildings.end(), building));
}

void Map::free(Building &building) {
    for (int i = 0; i < building.height; i++) {
        for (int j = 0; j < building.width; j++) {
            this->at(building.getPosition().x + j * BLOCK_WIDTH, building.getPosition().y + i * BLOCK_HEIGHT).free();
        }
    }
}

bool Map::canWeBuild(Position& pos, int width, int height, Player& player) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Position aux(pos.getX() + j * BLOCK_WIDTH, pos.getY() + i * BLOCK_HEIGHT);
            if (isValid(aux)) {
                if ((this->at(aux).getKey() != Rocks().getKey()) || this->at(aux).isOccupied()) {
                    return false;
                }
            } else {
                return false;
            }
        }
    }

    for (int i = -5; i <= height + 5; i++) {
        for (int j = -5; j <= width + 5; j++) {
            Position aux(pos.getX() + j * BLOCK_WIDTH, pos.getY() + i * BLOCK_HEIGHT);
            if (isValid(aux)) {
                if (this->at(aux).isBuiltOn()) {
                    if (*(this->at(aux).getBuilding()->getPlayer()) == player)
                        return true;
                }
            }
        }
    }

    return false;
}

Position Map::getClosestFreePosition(Building* building) {
    int dist = 1;
    bool found = false;
    Position& pos = building->getPosition();
    while (!found) {
        for (int i = - dist; i <= building->height + dist; i++) {
            for (int j =  - dist; j <= building->width + dist; j++) {
                try {
                    if (!(this->at(pos.x + j * BLOCK_WIDTH, pos.y + i * BLOCK_HEIGHT).isOccupied())) {
                        return Position(pos.x + j * BLOCK_WIDTH, pos.y + i * BLOCK_HEIGHT);
                    }
                }
                catch (std::out_of_range& e) {}
            }
        }
        dist += 1;
    }
    return pos;
}

Attackable *Map::getClosestAttackable(Position &position, int limitRadius, Player& player) {
    Attackable* closest_attackable = nullptr;
    int closest_unit_distance = limitRadius;
    for (auto& current_unit : units) {
        int distance = current_unit->getPosition().sqrtDistance(position);
        if ((distance < limitRadius) && (distance < closest_unit_distance) &&
            !(player == current_unit->getPlayer())) {
            closest_attackable = current_unit;
            closest_unit_distance = distance;
        }
    }
    for (auto& current_building : buildings) {
        Position& pos = current_building->getClosestPosition(position);
        int distance = pos.sqrtDistance(position);
        if (distance < limitRadius
                && distance < closest_unit_distance
                && !(*(current_building->getPlayer()) == player)) {
            closest_attackable = current_building;
            closest_unit_distance = distance;
        }
    }
    return closest_attackable;
}

Position Map::getCornerPosition(Position& pos) {
    return Position((pos.x / BLOCK_WIDTH) * BLOCK_WIDTH, (pos.y / BLOCK_HEIGHT) * BLOCK_HEIGHT);
}

Position Map::getClosestSpeciaPosition(Position pos, int radius) {
    int block_x = (pos.x / BLOCK_HEIGHT);
    int block_y = (pos.y / BLOCK_WIDTH);
    int min_distance = radius + 1;
    Position min_position = pos;
    for (int i = -radius; i <= +radius; ++i) {
        for (int j = -(radius - abs(i)); j <= +(radius - abs(i)); ++j) {
            int cur_pos_x = (block_x + j);
            int cur_pos_y = (block_y + i);
            if ((cur_pos_y + i) >= 0 &&
                    (cur_pos_y + i) < cols &&
                    (cur_pos_x + j) >= 0 &&
                    (cur_pos_x + j) < rows) {
                if ( abs(i) + abs(j) < min_distance
                        && this->blockAt(cur_pos_x, cur_pos_y).hasFarm()) {
                    min_distance = abs(i) + abs(j);
                    min_position = Position(cur_pos_x * BLOCK_HEIGHT, cur_pos_y * BLOCK_WIDTH);
                }
            }
        }
    }

    return min_position;
}

int Map::getSpeedFactorAt(Position &pos) {
    return this->at(pos).getSpeedFactor();
}

