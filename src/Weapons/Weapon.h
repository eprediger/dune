#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "../GlobalConfig.h"

class Weapon {
private:
    const int damage;
    const int frecuency;
    const int bonus;
public:
    Weapon(int damage, int frecuency, int bonus);
    ~Weapon();
    int getDamage();
};

#endif //__WEAPON_H__
