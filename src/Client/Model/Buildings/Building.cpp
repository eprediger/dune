#include "Building.h"
#include <nlohmann/json.hpp>
#include "../Map.h"

Building::Building(nlohmann::json& j):
	width(j["width"]),
	height(j["height"]),
	id(j["id"]),
	player_id(j["player_id"]),
	player(nullptr),
	life(j["life"]),
	initial_life(life),
	key(j["type"]),
	all_positions() {
	int x = j["pos"]["x"];
	int y = j["pos"]["y"];
	for (int i = 0 ; i < height ; i++) {
		for (int j = 0 ; j < width ; j++) {
			all_positions.emplace_back(x + j * Map::getBlockWidth(), y + i * Map::getBlockHeight());
		}
	}
}

Building::~Building() {}

bool Building::is(Building::BuildingType type) {
	return this->key == type;
}

Position& Building::getClosestPosition(Position& position) {
	int distance = position.sqrtDistance(all_positions[0]);
	Position& closest = all_positions[0];
	for (unsigned i = 0; i < all_positions.size(); i++) {
		if (position.sqrtDistance(all_positions[i]) < distance) {
			closest = all_positions[i];
			distance = position.sqrtDistance(closest);
		}
	}
	return closest;
}

void Building::update(nlohmann::json& j) {
	life = j["life"];
}

bool Building::isDead() {
	return life <= 0;
}

void Building::setPlayer(Player* player) {
	this->player = player;
}

Player* Building::getPlayer() {
	return this->player;
}

Position& Building::getPosition() {
	return all_positions.front();
}

int Building::getLife() {
	return life;
}

int Building::getInitialLife() {
	return initial_life;
}