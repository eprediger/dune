#ifndef __OffensiveUnit_H__
#define __OffensiveUnit_H__

#include "../Attacker.h"

#include "Unit.h"

#include "../Map.h"

class OffensiveUnit : public Unit, Attacker {
public:
    OffensiveUnit(const int x, const int y, const int hitPoints, const int range,
                                 Weapon weapon, const int speed);

    virtual int makeAction(Map& map) override;

    bool automaticAttack(Map &map);

    Position& getVictimPosition();
    bool attacking;
private:
    Position victim_pos;
//    void follow(Unit* other, Map& map);
//private:
//    Unit* foll_unit;
//    Position prev_foll_unit_pos;
};


#endif //__OffensiveUnit_H__
