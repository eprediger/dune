#include "Tank.h"

Tank::Tank(nlohmann::json& j) :
        OffensiveUnit(j) {}

Tank::~Tank() {}
