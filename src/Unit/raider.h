#ifndef __RAIDER_H__
#define __RAIDER_H__

#include "Unit.h"
#include "../Weapons/small-cannon.h"

class Raider : public Unit {
public:
	Raider(int x, int y);
	~Raider();
	
};

#endif