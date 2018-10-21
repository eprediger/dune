#include "Positionable.h"

Positionable::Positionable(int x, int y) : pos(x,y) {}

Positionable::Positionable(int x, int y, int value) : pos(x,y), value(value) {}

Position Positionable::getPosition() const {
    return pos;
}

int Positionable::getValue() {
    return value;
}


