#ifndef __RAIDER_H__
#define __RAIDER_H__

#include "OffensiveUnit.h"

class Raider : public OffensiveUnit {
public:
	Raider(nlohmann::json& j);
	~Raider();
};

#endif	// __RAIDER_H__