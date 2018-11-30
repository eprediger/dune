#include "Barracks.h"
#include <Model/GameConfiguration.h>

Barracks::Barracks(nlohmann::json& j) :
	Building(j) {}

Barracks::~Barracks() {}
