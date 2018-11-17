#include "Sand.h"

Sand::Sand() : Terrain(SAND_KEY), availableFarm(INITIAL_AVAIABLE_FARM) {}

int Sand::getFarm() {
    if (availableFarm > 0){
        availableFarm--;
        return 1;
    } else {
        return 0;
    }
}

bool Sand::hasFarm() {
    return availableFarm > 0;
}