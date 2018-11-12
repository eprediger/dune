#ifndef __SAND_H__
#define __SAND_H__

#include "Terrain.h"

#define SAND_KEY 'A'

#define INITIAL_AVAIABLE_FARM 200

class Sand : public Terrain {
public:
	Sand();

	virtual int getFarm() override;
private:
	int availableFarm;
};

#endif //__SAND_H__
