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

void Terrain::buildOn(Building* building){}

void Terrain::free(){
	occupied = false;
	builtOn = false;
}

Building* Terrain::getBuilding(){
	return nullptr;
}
bool Terrain::isOccupied(){
	return occupied || builtOn;
}

bool Terrain::isBuiltOn(){
	return builtOn;
}

int Terrain::getSpice(){ 
	return 0;
}

int Terrain::farm() {
	return 0;
}

bool Terrain::hasFarm() {
	return false;
}
