#ifndef __ROCKET_H__
#define __ROCKET_H__

#include "../../Position.h"

class Rocket{
    public:
        Rocket(Position source, Position dest);
        void move();
        bool arrived();
        Position& getPosition(); 
    private:
        Position pos;
        Position dest;
};

#endif