#include "Terrain.h"

Terrain::Terrain() : key(' '), occupied(false) {}

Terrain::Terrain(char key) : key(key), occupied(false), builtOn(false) {}

char Terrain::getKey() {
	return key;
}

bool Terrain::operator==(const Terrain &terrain) {
	return terrain.key == key;
}

void Terrain::occupy(){
	occupied = true;
}

void Terrain::buildOn(){
	occupied = true;
	builtOn = true;
}

void Terrain::free(){
	occupied = false;
}

bool Terrain::isOccupied(){
	return occupied;
}

bool Terrain::isBuiltOn(){
	return builtOn;
}

int Terrain::getFarm() {
	return 0;
}
