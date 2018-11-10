#ifndef __PasiveUnit_H__
#define __PasiveUnit_H__


#include "Unit.h"

#include "../Map.h"

class PassiveUnit : public Unit {
public:
    PassiveUnit (const int x, const int y, const int hitPoints, const int speed);

    virtual UnitState * makeFollow(Map &map) override;
    virtual UnitState * makeAttack(Map &map) override;
    virtual UnitState * makeStopped(Map &map) override;
    virtual UnitState * makeDefending(Map &map) override;
};

#endif //__PasiveUnit_H__
