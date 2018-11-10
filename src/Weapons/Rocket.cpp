#include "Rocket.h"
#include "../Position.h"
#include <cstdlib>

Rocket::Rocket(Position source, Position dest)
    :pos(source)
    ,dest(dest){}

void Rocket::move(){
    if (pos.x!=dest.x)
        pos.x += (dest.x - pos.x)/abs(dest.x - pos.x);
    if (pos.y!=dest.y)
        pos.y += (dest.y - pos.y)/abs(dest.y - pos.y);
}

bool Rocket::arrived(){
    return (pos == dest);
}

Position& Rocket::getPosition(){
    return pos;
}