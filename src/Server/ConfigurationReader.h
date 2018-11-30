#ifndef __CONFIGURATION_READER_H__
#define __CONFIGURATION_READER_H__

#include "YAMLReader.h"
#include <Model/Buildings/Building.h>

class ConfigurationReader : public YAMLReader {
public:
	ConfigurationReader(const char *filename);
	~ConfigurationReader();

	unsigned getSpeedFactor() const;
	unsigned getRangeFactor() const;
	unsigned getTimeFactor() const;

	unsigned getBuildingConstructionTime() const;
	unsigned getEnergyFor(const Building::BuildingType buildingType) const;
	unsigned getCostFor(const Building::BuildingType buildingType) const;
	unsigned getHitPointsFor(const Building::BuildingType buildingType) const;
	unsigned getWidthFor(const Building::BuildingType buildingType) const;
	unsigned getHeightFor(const Building::BuildingType buildingType) const;
	unsigned getSpiceCapacityFor(const Building::BuildingType buildingType) const;

private:
	std::string parseType(const Building::BuildingType buildingType) const;	
};


#endif	// __CONFIGURATION_READER_H__
