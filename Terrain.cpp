#include "Terrain.h"

Terrain::Terrain(int movility) : movility(movility) {}

int Terrain::getMovility() {
    return movility;
}

Terrain::Terrain() : key(' '), movility(0){}

std::ostream &operator<<(std::ostream &os, const Terrain &terrain) {
    os << terrain.movility;
    return os;
}

void Terrain::setMovility(int movility) {
    this->movility = movility;
}

Terrain::Terrain(char key) : key(key){

}

bool Terrain::operator==(const Terrain &terrain) {
    return terrain.key == key;
}

char Terrain::getKey() {
    return key;
}


