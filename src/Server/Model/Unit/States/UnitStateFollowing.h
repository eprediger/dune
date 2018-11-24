#ifndef __UNITSTATEFOLLOWING_H__
#define __UNITSTATEFOLLOWING_H__

#include "UnitState.h"

class UnitStateFollowing : public UnitState {
public:
    virtual UnitState *makeAction(Map &map, Unit &unit) override;
};

#endif //__UNITSTATEFOLLOWING_H__
