#include "OffensiveUnit.h"

OffensiveUnit::OffensiveUnit(nlohmann::json& j) :
    Unit(j),
    attacking(j["attacking"]),
    shooting(j["shooting"]),
    victim_pos() {
    if (attacking) {
        this->victim_pos.x = j["victim_pos"]["x"];
        this->victim_pos.y = j["victim_pos"]["y"];
    }
}

Position& OffensiveUnit::getVictimPosition() {
    return this->victim_pos;
}

bool OffensiveUnit::isShooting() {
    return this->shooting;
}

bool OffensiveUnit::isAttacking() {
    return this->attacking;
}

void OffensiveUnit::update(nlohmann::json& j) {
    this->attacking = j["attacking"];
    this->shooting = j["shooting"];
    if (attacking) {
        this->victim_pos.x = j["victim_pos"]["x"];
        this->victim_pos.y = j["victim_pos"]["y"];
    }
    Unit::update(j);
}
