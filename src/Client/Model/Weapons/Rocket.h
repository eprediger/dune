#ifndef __ROCKET_H__
#define __ROCKET_H__

#include "Position.h"
#include <nlohmann/json.hpp>

class Map;

class Rocket{
    public:
        Rocket(nlohmann::json& j);
        Position& getPosition(); 
        void update(nlohmann::json& j);

        const int id;
        bool arrived;

    private:
        static int counter;
        Position pos;
};

#endif	// __ROCKET_H__
