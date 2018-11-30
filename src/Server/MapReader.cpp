#include "MapReader.h"

MapReader::MapReader(const char *filename) :
	YAMLReader(filename) {}

MapReader::~MapReader() {}

unsigned MapReader::getPlayers() const {
	return this->config["max_players"].as<unsigned>();
}
