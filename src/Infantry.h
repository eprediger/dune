#ifndef __INFANTRY_H__
#define __INFANTRY_H__

#include "Unity.h"
#include "Terrain.h"

class Infantry : public Unity {
public:
    Infantry();

    Infantry(int x, int y);

    virtual bool canMoveAboveTerrain(Terrain &terrain) override;
};

#endif //__INFANTRY_H__
