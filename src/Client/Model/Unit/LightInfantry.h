#ifndef __LIGHT_INFANTRY_H__
#define __LIGHT_INFANTRY_H__

#include "OffensiveUnit.h"

class LightInfantry : public OffensiveUnit {
public:
	LightInfantry(nlohmann::json& j);
	
	~LightInfantry();
};

#endif
