#include "trike.h"

Trike::Trike(int x, int y) :
	Unit(x, y,
		  GlobalConfig.trikeHitPoints,
		  GlobalConfig.trikeRange,
		  AssaultRifle(),
		  GlobalConfig.trikeSpeed) {}

Trike::~Trike() {}
