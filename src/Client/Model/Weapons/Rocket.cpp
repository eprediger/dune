#include "Rocket.h"
#include "Position.h"
#include "../../../Common/Area.h"
#include <cstdlib>
#include <vector>


Rocket::Rocket(nlohmann::json& j) :
    id(j["id"]),
    pos(j["pos"]["x"],j["pos"]["y"]),
    arrived(j["arrived"])
{}

void Rocket::update(nlohmann::json& j){
    pos.x = j["pos"]["x"];
    pos.y = j["pos"]["y"]; 
    arrived = j["arrived"];
}

Position& Rocket::getPosition(){
    return pos;
}