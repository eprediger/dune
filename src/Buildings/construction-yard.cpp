#include "construction-yard.h"

ConstructionYard::ConstructionYard() :
	Building(GlobalConfig.constructionYardEnergy,
			 GlobalConfig.constructionYardCost,
			 GlobalConfig.constructionYardHitPoints) {}

ConstructionYard::~ConstructionYard() {}
