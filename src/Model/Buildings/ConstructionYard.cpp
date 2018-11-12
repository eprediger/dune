#include "ConstructionYard.h"

ConstructionYard::ConstructionYard(const int x, const int y) :
	Building(x, y,
			 GlobalConfig.constructionYardEnergy,
			 GlobalConfig.constructionYardCost,
			 GlobalConfig.constructionYardHitPoints) {}

ConstructionYard::~ConstructionYard() {}
