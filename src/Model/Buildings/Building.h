#ifndef __BUILDING_H__
#define __BUILDING_H__

#include "../Attackable.h"
#include "../Positionable.h"
#include "../GlobalConfig.h"

class Building : public Attackable, public Positionable {
public:
    enum BuildingType {
        BARRACKS,
        CONSTRUCTION_YARD,
        HEAVY_FACTORY,
        LIGHT_FACTORY,
        SPICE_REFINERY,
        SPICE_SILO,
        WIND_TRAP
    };


    Building(const int x, const int y, const int hitPoints, const int energy, const int cost, BuildingType type);
    virtual ~Building();

	virtual void reciveBonusDammage(const Weapon &weapon) override;

	bool is(BuildingType type);

private:
	BuildingType key;
	const int energy;
	const int cost;
};

#endif //__BUILDING_H__
