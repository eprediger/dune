#ifndef __LIGHT_FACTORY_H__
#define __LIGHT_FACTORY_H__

#include "Building.h"

class LightFactory : public Building {
public:
	LightFactory(nlohmann::json& j);
	~LightFactory();
};

#endif	// __LIGHT_FACTORY_H__
