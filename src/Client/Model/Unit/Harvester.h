#ifndef __HARVESTER_H__
#define __HARVESTER_H__

#include "Unit.h"

class Harvester : public Unit {
public:
	explicit Harvester(nlohmann::json& j);

	~Harvester();
};

#endif
