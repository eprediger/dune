#include "ConstructionYard.h"

ConstructionYard::ConstructionYard(const int x, const int y, int blockWidth, int blockHeight) :
        Building(x, y, blockWidth, blockHeight,
                 GlobalConfig.constructionYardEnergy,
                 GlobalConfig.constructionYardCost,
                 GlobalConfig.constructionYardHitPoints,
                 GlobalConfig.constructionYardWidth,
                 GlobalConfig.constructionYardHeight,
                 CONSTRUCTION_YARD)
{}

ConstructionYard::~ConstructionYard() {}
