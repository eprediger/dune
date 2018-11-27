#include "Building.h"
#include "../Player.h"

int Building::counter = 0;
Building::Building(const int x, const int y, int blockWidth, int blockHeight, const int energy, const int cost,
                   const int hitPoints, const int width,
                   const int height, BuildingType type):
	Attackable(hitPoints, x, y),
	id(counter),
	width(width),
	height(height),
	energy(energy),
	cost(cost),
	player(nullptr),
	key(type),
	all_positions(),
	serialization()
{
	for (int i = 0 ; i < height ; i++) {
		for (int j = 0 ; j < width ; j++) {
			all_positions.emplace_back(x + j * blockWidth, y + i * blockHeight);
		}
	}
	counter+=1;
	serialization["class"] = "Building";
	serialization["type"] = type;
	serialization["life"] = hitPoints;
	serialization["width"] = width;
	serialization["height"] = height;
	serialization["pos"]["x"] = x;
	serialization["pos"]["y"] = y;
}

Building::~Building() {}

void Building::reciveBonusDammage(const Weapon &weapon) {
	life -= weapon.getBuildingBonus();
}

bool Building::is(Building::BuildingType type) {
	return this->key == type;
}

void Building::setPlayer(Player* player) {
	this->player = player;
	serialization["player_id"] = player->getId();
}

Player* Building::getPlayer() {
	return this->player;
}

void Building::demolish() {
	this->life = 0;
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

nlohmann::json& Building::getSerialization(){
	serialization["life"] = this->getLife();
	return serialization;
}