#include "ConstructionYard.h"

ConstructionYard::ConstructionYard(nlohmann::json& j):
	Building(j) {}

ConstructionYard::~ConstructionYard() {}
