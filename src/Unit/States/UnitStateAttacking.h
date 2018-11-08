#ifndef __UNITSTATEATTACKING_H__
#define __UNITSTATEATTACKING_H__

#include "UnitState.h"

class UnitStateAttacking : public UnitState {
public:
    virtual UnitState *makeAction(Map &map, Unit &unit) override;
};


#endif //__UNITSTATEATTACKING_H__
