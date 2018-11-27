#ifndef __ROCKET_H__
#define __ROCKET_H__

#include "Position.h"
#include <nlohmann/json.hpp>

class Map;

class Rocket{
    public:
        Rocket(Position source, Position dest);
        void move();
        bool arrived();
        void explode(Map& map);
        Position& getPosition(); 
        nlohmann::json& getSerialization();

        const int id;
    private:
        static int counter;
        Position pos;
        Position dest;
        nlohmann::json serialization;
};

#endif	// __ROCKET_H__
