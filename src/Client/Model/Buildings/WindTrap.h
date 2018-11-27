#ifndef __WIND_TRAP_H__
#define __WIND_TRAP_H__

#include "Building.h"

class WindTrap : public Building {
public:
	WindTrap(nlohmann::json& j);
	~WindTrap();	
};

#endif	// __WIND_TRAP_H__
