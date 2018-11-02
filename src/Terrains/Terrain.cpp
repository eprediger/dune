#include "Terrain.h"

Terrain::Terrain() : key(' ') {}

Terrain::Terrain(char key) : key(key) {}

char Terrain::getKey() {
	return key;
}

bool Terrain::operator==(const Terrain &terrain) {
	return terrain.key == key;
}
