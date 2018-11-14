#include "ConstructionYard.h"

ConstructionYard::ConstructionYard(const int x, const int y) :
        Building(x, y,
                 GlobalConfig.constructionYardEnergy,
                 GlobalConfig.constructionYardCost,
                 GlobalConfig.constructionYardHitPoints,
                 GlobalConfig.constructionYardWidth,
                 GlobalConfig.constructionYardHeight,
                 CONSTRUCTION_YARD) {}

ConstructionYard::~ConstructionYard() {}
