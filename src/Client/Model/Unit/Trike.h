#ifndef __TRIKE_H__
#define __TRIKE_H__

#include "OffensiveUnit.h"

class Trike : public OffensiveUnit {
public:
	Trike(nlohmann::json& j);

	~Trike();
};

#endif