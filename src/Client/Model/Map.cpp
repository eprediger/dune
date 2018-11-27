#include "Map.h"
#include <nlohmann/json.hpp>
#include "Terrains/Terrain.h"
#include "Terrains/Sand.h"
#include "Terrains/Dunes.h"
#include "Terrains/Rocks.h"
#include "Terrains/Summit.h"
#include "Terrains/Precipice.h"
#include "CustomException.h"
#include "../../Common/Area.h"
#include <stack>
#include <vector>

Map::Map(nlohmann::json& file):
    matrix(),
    rows(file["height"]),
    cols(file["width"])
{

    nlohmann::json keys = file["matrix"];
    
    for (auto it = keys.begin() ; it!=keys.end() ; it++){
        int key = *it;
        if (key == file["sand_key"]) {
            matrix.emplace_back(std::unique_ptr<Terrain>(new Sand(0)));
        } else if (key == file["spiced_sand_key"]) {
            matrix.emplace_back(std::unique_ptr<Terrain>(new Sand(file["initial_spice"])));
        } else if (key == file["dune_key"]) {
            matrix.emplace_back(std::unique_ptr<Terrain>(new Dunes()));
        } else if (key == file["rocks_key"]) {
            matrix.emplace_back(std::unique_ptr<Terrain>(new Rocks()));
        } else if (key == file["summit_key"]) {
            matrix.emplace_back(std::unique_ptr<Terrain>(new Summit()));
        } else if (key == file["precipice_key"]) {
            matrix.emplace_back(std::unique_ptr<Terrain>(new Precipice()));
        }
    }
}

Map::~Map() {}


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
    for (auto& building : buildings) {
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

bool Map::canWeBuild(Position& pos, int width, int height) {
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
                    return false;
                }
            }
        }
    }
    return true;
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


Position Map::getCornerPosition(Position& pos) {
    return Position((pos.x / BLOCK_WIDTH) * BLOCK_WIDTH, (pos.y / BLOCK_HEIGHT) * BLOCK_HEIGHT);
}

