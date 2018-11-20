#ifndef __UNITSTATEDEFENDING_H__
#define __UNITSTATEDEFENDING_H__

#include "UnitState.h"

class UnitStateDefending : public UnitState {
public:
    virtual UnitState *makeAction(Map &map, Unit &unit) override;
    virtual bool isAttacking() override;
};

#endif //__UNITSTATEDEFENDING_H__
