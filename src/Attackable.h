#ifndef __ATTACKABLE_H__
#define __ATTACKABLE_H__

#include "Attacker.h"

class Attackable {
protected:
    int life;
public:
    Attackable(int life);

    virtual int getLife();

    virtual void reciveAttack(Attacker &attacker);
};

#endif //__ATTACKABLE_H__
