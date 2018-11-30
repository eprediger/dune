#ifndef __GAME_CONFIGURATION_H__
#define __GAME_CONFIGURATION_H__

#include <ConfigurationReader.h>

class GameConfiguration {
private:
	explicit GameConfiguration(const ConfigurationReader& config);
	static std::unique_ptr<GameConfiguration> instance;

public:

	~GameConfiguration() = default;

	static void init(const char *string);
	static GameConfiguration& getConfig();

// private:
	const int SPEED_FACTOR; // (84*3)
	const int RANGE_FACTOR; // 2000
	const int TIME_FACTOR; // 1
// Building Stats
	// Tiempo de costruccion de edificios
	const int buildingConstructionTime;
	// Centro de Construcción
	const int constructionYardEnergy;
	const int constructionYardCost;
	const int constructionYardHitPoints;
	const int constructionYardWidth ;
	const int constructionYardHeight;
	// Trampas de Aire
	const int windTrapEnergy;
	const int windTrapCost;
	const int windTrapHitPoints;
	const int windTrapWidth ;
	const int windTrapHeight;
	// Fabrica Ligera
	const int lightFactoryEnergy;
	const int lightFactoryCost;
	const int lightFactoryHitPoints;
	const int lightFactoryWidth ;
	const int lightFactoryHeight;
	// Fabrica Pesada
	const int heavyFactoryEnergy;
	const int heavyFactoryCost;
	const int heavyFactoryHitPoints;
	const int heavyFactoryWidth ;
	const int heavyFactoryHeight;
	// Refinera
	const int spiceRefineryEnergy;
	const int spiceRefineryCost;
	const int spiceRefineryHitPoints;		// el enunciado no dice
	const int spiceRefinerySpiceCapacity;
	const int spiceRefinerySpicWidth ;		// enunciado no dice
	const int spiceRefinerySpicHeight;		// enunciado no dice
	// Silo
	const int spiceSiloEnergy;
	const int spiceSiloCost;
	const int spiceSiloHitPoints;
	const int spiceSiloSpiceCapacity;
	const int spiceSiloSpicWidth ;
	const int spiceSiloSpicHeight;
	// Cuartel
	const int barracksEnergy;
	const int barracksCost;
	const int barracksHitPoints;
	const int barracksWidth ;
	const int barracksHeight;
	// Palacio
	/*const int palaceEnergy		= 800;
	const int palaceCost		= 2000;
	const int palaceHitPoints	= 1000;*/
// Weaponry -> frecuencias de disparo por segundo
	// Rifles de asalto
	const int assaultRifleDamage		= 2;
	const int assaultRifleShootingRate	= 6;
	const int assaultRifleBonus			= 1;	// a infanteria
	// Cañon
	const int cannonDamage			= 7;
	const int cannonShootingRate	= 1;
	const int cannonBonus			= 0;
	// Lanzamisiles
	const int rocketLauncherDamage			= 8;
	const int rocketLauncherShootingRate	= 1;
	const int rocketLauncherBonus			= 0;
	// Cañon 22mm
	const int smallCannonDamage			= 6;
	const int smallCannonShootingRate	= 6;
	const int smallCannonBonus			= 2;	// vehiculos y edificios
	// Ondas de sonido
	/*
	const int soundWaveDamage			= 4;
	const int soundWaveShootingRate		= 1;
	const int soundWaveBonus			= 4;	// a infanteria
	*/
	// Cañon de Plasma
	/*
	const int plasmaCannonDamage		= 8;
	const int plasmaCannonShootingRate	= 1;
	const int plasmaCannonBonus			= 2;	// vehiculos y edificios
	*/
// Infantry Stats
	// Infanteria Ligera
	const int lightInfantryHitPoints	= 50;
	const int lightInfantryRange		= RANGE_FACTOR * 3;
	const int lightInfantrySpeed		= SPEED_FACTOR / 16;
	const int lightInfantryTrainingTime	= 60 * TIME_FACTOR;
	const int lightInfantryCost			= 50;
	// Infanteria Pesada
	const int heavyInfantryHitPoints	= 80;
	const int heavyInfantryRange		= RANGE_FACTOR * 3;
	const int heavyInfantrySpeed		= SPEED_FACTOR / 14;
	const int heavyInfantryTrainingTime	= 78 * TIME_FACTOR;
	const int heavyInfantryCost			= 70;
	// Fremen
	/*
	const int fremenHitPoints	= 50;
	const int fremenRange		= 3;
	const int fremenSpeed		= 20;
	const int fremenTrainingTime	= 120;
	const int fremenCost			= 100;
	*/
	// Sardaukar
	/*
	const int sardaukarHitPoints	= 80;
	const int sardaukarRange		= 3;
	const int sardaukarSpeed		= 12;
	const int sardaukarTrainingTime	= 120;
	const int sardaukarCost			= 100;
	*/
// Vehicles
	// Cosechadora
	const int harvesterHitPoints		= 600;
	const int harvesterSpeed			= SPEED_FACTOR / 12;
	const int harvesterConstructionTime	= 180 * TIME_FACTOR;
	const int harvesterCost				= 300;
	const int harvesterSpiceCapacity	= 200;
	const int harvesterFarmSpeed        = 20 * TIME_FACTOR;
	const int harvesterLoadSpeed        = 5 * TIME_FACTOR;
	// Trike
	const int trikeHitPoints		= 80;
	const int trikeRange			= RANGE_FACTOR * 4;
	const int trikeSpeed			= SPEED_FACTOR / 64;
	const int trikeConstructionTime	= 120 * TIME_FACTOR;
	const int trikeCost				= 100;
	// Raider
	const int raiderHitPoints			= 80;
	const int raiderRange				= RANGE_FACTOR * 4;
	const int raiderSpeed				= SPEED_FACTOR / 84;
	const int raiderConstructionTime	= 120 * TIME_FACTOR;
	const int raiderCost				= 100;
	// Tanque
	const int tankHitPoints			= 30;
	const int tankRange				= RANGE_FACTOR * 4;
	const int tankSpeed				= SPEED_FACTOR / 40;
	const int tankConstructionTime	= 240 * TIME_FACTOR;
	const int tankCost				= 300;
	// Tanque Sonico
	/*
	const int sonicTankHitPoints		= 300;
	const int sonicTankRange			= 4;
	const int sonicTankSpeed			= 12;
	const int sonicTankConstructionTime	= 240;
	const int sonicTankCost				= 300;
	*/
	// Desviador
	/*
	const int deviatorHitPoints			= 300;
	const int deviatorRange				= 5;
	const int deviatorSpeed				= 12;
	const int deviatorConstructionTime	= 240;
	const int deviatorCost				= 400;
	*/
	// Devastador
	/*
	const int desvastatorHitPoints			= 400;
	const int desvastatorRange				= 4;
	const int desvastatorSpeed				= 12;
	const int desvastatorConstructionTime	= 300;
	const int desvastatorCost				= 400;
	*/

	nlohmann::json initwithJson();

};

#endif	// __GAME_CONFIGURATION_H__
