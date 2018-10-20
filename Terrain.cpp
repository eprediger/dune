#include "Terrain.h"

Terrain::Terrain(int movility) : movility(movility) {}

int Terrain::getMovility() {
    return movility;
}

Terrain::Terrain() : movility(0){}

std::ostream &operator<<(std::ostream &os, const Terrain &terrain) {
    os << terrain.movility;
    return os;
}

void Terrain::setMovility(int movility) {
    this->movility = movility;
}
