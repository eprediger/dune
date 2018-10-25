#ifndef __WEAPON_H__
#define __WEAPON_H__

class Weapon {
private:
    int dammage;
    int frecuency;
public:
    Weapon(int dammage, int frecuency);

    int getDammage();
};

#endif //__WEAPON_H__
