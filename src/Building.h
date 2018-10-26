#ifndef __BUILDING_H__
#define __BUILDING_H__

#include "Attackable.h"
#include "Positionable.h"

class Building : public Attackable, public Positionable {
public:
    Building();
};

#endif //__BUILDING_H__
