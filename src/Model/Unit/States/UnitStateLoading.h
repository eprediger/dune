#ifndef __UNITSTATELOADING_H__
#define __UNITSTATELOADING_H__


#include "UnitState.h"

class UnitStateLoading : public UnitState {
public:
    virtual UnitState *makeAction(Map &map, Unit &unit) override;

};


#endif //__UNITSTATELOADING_H__
