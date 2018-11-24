#ifndef __UNITSTATEFARMING_H__
#define __UNITSTATEFARMING_H__

#include "UnitState.h"

class UnitStateFarming : public UnitState {
public:
    virtual UnitState *makeAction(Map &map, Unit &unit) override;
};

#endif //__UNITSTATEFARMING_H__
