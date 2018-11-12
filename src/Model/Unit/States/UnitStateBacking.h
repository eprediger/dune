#ifndef __UNITSTATEBACKING_H__
#define __UNITSTATEBACKING_H__

#include "UnitState.h"

class UnitStateBacking : public UnitState {
public:
    virtual UnitState *makeAction(Map &map, Unit &unit) override;

};


#endif //__UNITSTATEBACKING_H__
