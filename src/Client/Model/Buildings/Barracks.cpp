#include "Barracks.h"
#include "Model/GlobalConfig.h"

Barracks::Barracks(nlohmann::json& j) :
	Building(j) {}

Barracks::~Barracks() {}
