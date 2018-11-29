#ifndef __CONSTRUCTION_YARD_H__
#define __CONSTRUCTION_YARD_H__

#include "Building.h"

class ConstructionYard : public Building {
public:
	explicit ConstructionYard(nlohmann::json& j);
	
	~ConstructionYard();
};

#endif	// __CONSTRUCTION_YARD_H__
