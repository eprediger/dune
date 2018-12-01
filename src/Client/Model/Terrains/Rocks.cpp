#include "Rocks.h"

Rocks::Rocks() : Terrain(ROCKS_KEY),building(nullptr){}

void Rocks::buildOn(Building* newBuilding){
    occupied = true;
    builtOn = true;
    this->building = newBuilding;
}

Building* Rocks::getBuilding(){
    return this->building;
}

void Rocks::free(){
    this->building = nullptr;
    Terrain::free();
}