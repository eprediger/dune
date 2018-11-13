#ifndef __UNITSTATE_H__
#define __UNITSTATE_H__

class Unit;
class Map;

class UnitState {
public:
	virtual UnitState *makeAction(Map &map, Unit &unit) = 0;
	virtual bool isAttacking();
};

#endif	// __UNITSTATE_H__
