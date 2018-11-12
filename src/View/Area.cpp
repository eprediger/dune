//
// Created by emiliano on 24/10/18.
//

#include "Area.h"
#include "../Position.h"
#include <cstdlib>

Area::Area(int x, int y, int width, int height) :
    x(x), y(y), width(width), height(height) {
}

Area::Area(const Position& pos1,const Position& pos2){
    if (pos1.x < pos2.x)
        x = pos1.x;
    else
        x = pos2.x;
    if (pos1.y < pos2.y)
        y = pos1.y;
    else 
        y = pos2.y;
    width = abs(pos1.x - pos2.x);
    height = abs(pos1.y - pos2.y);
}

void Area::setX(int x){
	this->x = x;
}

void Area::setY(int y){
	this->y = y;
}

int Area::getX() const {
    return this->x;
}
int Area::getY() const {
    return this->y;
}
int Area::getWidth() const {
    return this->width;
}
int Area::getHeight() const {
    return this->height;
}
