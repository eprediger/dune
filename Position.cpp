#include "Position.h"

#include "Map.h"

Position::Position() : x(0), y(0) {}

Position::Position(int x, int y) {
//    if (x < 0 || x > Map::getInstance()->getWidth()){
//        throw "Incorrect Pos";
//    }
//    if (y < 0 || y > Map::getInstance()->getHeight()){
//        throw "Incorrect Pos";
//    }
    this->x = x;
    this->y = y;

}

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

bool Position::operator==(const Position &other) const{
    return other.x == this->x && other.y == this->y;
}

bool Position::operator<(const Position &other) const {
    return this->y * 10 + this->x < other.y * 10 + other.x;
}


