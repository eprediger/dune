#ifndef __BARRACKS_H__
#define __BARRACKS_H__

#include "Building.h"

class Barracks : public Building {
public:
	Barracks(nlohmann::json& j);
	~Barracks();
};

#endif	// __BARRACKS_H__
