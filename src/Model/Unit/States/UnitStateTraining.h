#ifndef __UNIT_STATE_TRAINING_H__
#define __UNIT_STATE_TRAINING_H__

#include "UnitState.h"


class UnitStateTraining: public UnitState {
    public:
        virtual UnitState *makeAction(Map &map, Unit &unit) override;
        virtual bool isTraining() override;
};

#endif