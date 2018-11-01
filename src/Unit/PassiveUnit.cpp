#include "PassiveUnit.h"

PassiveUnit::PassiveUnit(const int x, const int y, const int hitPoints, const int speed) :
        Unit(x, y, hitPoints, speed) {}


int PassiveUnit::makeAction(Map& map){
    switch (state) {
        case STOPPED:
            return 0;
        case MOVING:
            this->move();
            return 1;
    }
}
