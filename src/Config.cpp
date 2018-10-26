#include "Config.h"

int Config::unity_id = 0;

int Config::getNextId() {
    return unity_id++;
}

void Config::init() {
    unity_id = 0;
}


