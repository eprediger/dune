#include "Positionable.h"

Positionable::Positionable(int x, int y) : pos(x,y) {
    this->pos.normalizeToBlock();
    value = 9;
}

Position Positionable::getPosition() const {
    return pos;
}

int Positionable::getValue() {
    return value;
}


