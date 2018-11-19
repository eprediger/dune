#ifndef __CONSTRUCTION_YARD_H__
#define __CONSTRUCTION_YARD_H__

#include "Building.h"

class ConstructionYard : public Building {
public:
	ConstructionYard(const int x, const int y, int blockWidth, int blockHeight) ;
	~ConstructionYard();
};

#endif	// __CONSTRUCTION_YARD_H__
