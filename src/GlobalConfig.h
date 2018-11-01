#ifndef __GLOBALCONFIG_H__
#define __GLOBALCONFIG_H__

#define SPEED_FACTOR (84*6)
#define RANGE_FACTOR 2000

typedef struct {
// Building Stats
	// Centro de Construcción
	const int constructionYardEnergy	= 0;
	const int constructionYardCost		= 0;
	const int constructionYardHitPoints	= 3000;
	// Trampas de Aire
	const int windTrapEnergy	= 500;
	const int windTrapCost		= 800;
	const int windTrapHitPoints	= 500;
	// Fabrica Ligera
	const int lightFactoryEnergy	= -500;
	const int lightFactoryCost		= 800;
	const int lightFactoryHitPoints	= 500;
	// Fabrica Pesada
	const int heavyFactoryEnergy	= -800;
	const int heavyFactoryCost		= 1500;
	const int heavyFactoryHitPoints	= 1500;
	// Refinera
	const int spiceRefineryEnergy			= -400;
	const int spiceRefineryCost				= 500;
	const int spiceRefineryHitPoints		= 500;	// el enunciado no dice
	const int spiceRefinerySpiceCapacity	= 5000;
	// Silo
	const int spiceSiloEnergy			= 100;
	const int spiceSiloCost				= 200;
	const int spiceSiloHitPoints		= 200;
	const int spiceSiloSpiceCapacity	= 1000;
	// Cuartel
	const int barracksEnergy	= 100;
	const int barracksCost		= 300;
	const int barracksHitPoints	= 300;
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
	const int lightInfantryRange		= RANGE_FACTOR*3;
	const int lightInfantrySpeed		= SPEED_FACTOR/16;
	const int lightInfantryTrainingTime	= 60;
	const int lightInfantryCost			= 50;
	// Infanteria Pesada
	const int heavyInfantryHitPoints	= 80;
	const int heavyInfantryRange		= RANGE_FACTOR*3;
	const int heavyInfantrySpeed		= SPEED_FACTOR/12;
	const int heavyInfantryTrainingTime	= 78;
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
	const int harvesterRange			= RANGE_FACTOR*0;
	const int harvesterSpeed			= SPEED_FACTOR/12;
	const int harvesterConstructionTime	= 180;
	const int harvesterCost				= 300;
	// Trike
	const int trikeHitPoints		= 80;
	const int trikeRange			= RANGE_FACTOR*4;
	const int trikeSpeed			= SPEED_FACTOR/64;
	const int trikeConstructionTime	= 120;
	const int trikeCost				= 100;
	// Raider
	const int raiderHitPoints			= 80;
	const int raiderRange				= RANGE_FACTOR*4;
	const int raiderSpeed				= SPEED_FACTOR/84;
	const int raiderConstructionTime	= 120;
	const int raiderCost				= 100;
	// Tanque
	const int tankHitPoints			= 30;
	const int tankRange				= RANGE_FACTOR*4;
	const int tankSpeed				= SPEED_FACTOR/40;
	const int tankConstructionTime	= 240;
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
} config_t;

extern config_t GlobalConfig;

#endif
