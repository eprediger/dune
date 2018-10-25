#include "Weapon.h"

Weapon::Weapon(int dammage, int frecuency) : dammage(dammage), frecuency(frecuency) {}

int Weapon::getDammage() {
    return dammage;
}
