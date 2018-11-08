#ifndef __UNITSTATESTOPPED_H__
#define __UNITSTATESTOPPED_H__


#include "UnitState.h"

class UnitStateStopped : public UnitState {
public:
    virtual UnitState *makeAction(Map &map, Unit &unit) override;
};


#endif //__UNITSTATESTOPPED_H__
