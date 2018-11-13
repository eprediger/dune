#ifndef __UNITSTATEMOVING_H__
#define __UNITSTATEMOVING_H__

#include "UnitState.h"

class UnitStateMoving : public UnitState {
public:
    virtual UnitState *makeAction(Map &map, Unit &unit) override;
};

#endif //__UNITSTATEMOVING_H__
