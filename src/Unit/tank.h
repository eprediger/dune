#ifndef __TANK_H__
#define __TANK_H__

#include "Unit.h"
#include "../Weapons/cannon.h"

class Tank : public Unit {
public:
	Tank(int x, int y);
	~Tank();
	
};

#endif
