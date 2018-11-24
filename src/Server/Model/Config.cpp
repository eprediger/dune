#include "Config.h"

int Config::unit_id = 0;

int Config::getNextId() {
    return unit_id++;
}

void Config::init() {
    unit_id = 0;
}

