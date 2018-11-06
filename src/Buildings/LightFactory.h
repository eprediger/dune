#ifndef __LIGHT_FACTORY_H__
#define __LIGHT_FACTORY_H__

#include "Building.h"

class LightFactory : public Building {
public:
	LightFactory(const int x, const int y);
	~LightFactory();
	
};

#endif
