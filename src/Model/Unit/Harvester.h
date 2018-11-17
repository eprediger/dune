#ifndef __HARVESTER_H__
#define __HARVESTER_H__

#include "Unit.h"
#include "../Weapons/AssaultRifle.h"
#include "../Buildings/SpiceRefinery.h"

class Harvester : public Unit {
public:
	Harvester(int x, int y);

	~Harvester();

	virtual bool canMoveAboveTerrain(Terrain &terrain);

	virtual void reciveBonusDammage(const Weapon &weapon) override;

	virtual void actionOnPosition(Map& map, Position& pos) override;

	virtual UnitState* makeFollow(Map &map) override;
	virtual UnitState* makeFarming(Map &map) override;
	virtual UnitState* makeLoading(Map &map) override;
	virtual UnitState* makeBacking(Map &map) override;

	bool farm(Map& map);
	bool isFull();

private:
	const int spiceCapacity;
	int spiceCollected;
	Position farming_position;
	SpiceRefinery* refinery;
	int farm_speed;
	int actual_farm_speed;
	int load_speed;
	int actual_load_speed;


};

#endif
