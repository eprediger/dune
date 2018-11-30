#ifndef __GAME_CONFIGURATION_H__
#define __GAME_CONFIGURATION_H__

#include <nlohmann/json.hpp>

class GameConfiguration {
private:
	static std::unique_ptr<GameConfiguration> instance;

	explicit GameConfiguration(nlohmann::json& j);

public:
	~GameConfiguration() = default;

	static void init(nlohmann::json& j);

	static GameConfiguration& getConfig();

	void initwithJson(nlohmann::json j);

// Building Stats
	// Tiempo de costruccion de edificios
	const int buildingConstructionTime;
	// Centro de Construcción
	const int constructionYardCost;
	const int constructionYardWidth;
	const int constructionYardHeight;
	// Trampas de Aire
	const int windTrapCost;
	const int windTrapWidth;
	const int windTrapHeight;
	// Fabrica Ligera
	const int lightFactoryCost;
	const int lightFactoryWidth;
	const int lightFactoryHeight;
	// Fabrica Pesada
	const int heavyFactoryCost;
	const int heavyFactoryWidth;
	const int heavyFactoryHeight;
	// Refinera
	const int spiceRefineryCost;
	const int spiceRefinerySpiceCapacity;
	const int spiceRefineryWidth;
	const int spiceRefineryHeight;
	// Silo
	const int spiceSiloCost;
	const int spiceSiloSpiceCapacity;
	const int spiceSiloWidth;
	const int spiceSiloHeight;
	// Cuartel
	const int barracksCost;
	const int barracksWidth;
	const int barracksHeight;
// Infantry Stats
	// Infanteria Ligera
	const int lightInfantryTrainingTime;
	const int lightInfantryCost;
	// Infanteria Pesada
	const int heavyInfantryTrainingTime;
	const int heavyInfantryCost;
// Vehicles
	// Cosechadora
	const int harvesterConstructionTime;
	const int harvesterCost;
	// Trike
	const int trikeConstructionTime;
	const int trikeCost;
	// Raider
	const int raiderConstructionTime;
	const int raiderCost;
	// Tanque
	const int tankConstructionTime;
	const int tankCost;
};

#endif	// __GAME_CONFIGURATION_H__
