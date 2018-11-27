#ifndef __TANK_H__
#define __TANK_H__

#include "OffensiveUnit.h"

class Tank : public OffensiveUnit {
public:
	Tank(nlohmann::json& j);
	~Tank();
};

#endif
