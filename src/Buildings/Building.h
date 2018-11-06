#ifndef __BUILDING_H__
#define __BUILDING_H__

#include "../Attackable.h"
#include "../Positionable.h"
#include "../GlobalConfig.h"

class Building : public Attackable, public Positionable {
public:
    Building(const int x, const int y, const int hitPoints, const int energy, const int cost);
    ~Building();

private:
	const int energy;
	const int cost;
};

#endif //__BUILDING_H__
