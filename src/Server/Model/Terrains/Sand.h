#ifndef __SAND_H__
#define __SAND_H__

#include "Terrain.h"

#define SAND_KEY 'A'

class Sand : public Terrain {
public:
	explicit Sand(int spice);
	Sand();
	virtual int farm() override;
	virtual int getSpice() override;
	virtual bool hasFarm() override;
	virtual char getKey() override;
private:
	int availableFarm;
};

#endif //__SAND_H__ 
