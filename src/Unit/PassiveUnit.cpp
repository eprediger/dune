#include "PassiveUnit.h"

PassiveUnit::PassiveUnit(const int x, const int y, const int hitPoints, const int speed) :
        Unit(x, y, hitPoints, speed) {}

UnitState *PassiveUnit::makeFollow(Map &map) {
    return state;
}


//int PassiveUnit::makeAction(Map& map){
//    switch (state) {
//        case STOPPED:
//            return 0;
//        case MOVING:
//            this->move(map);
//            return 1;
//    }
//}
