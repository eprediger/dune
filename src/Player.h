#ifndef __Player_H__
#define __Player_H__


class Player {
private:
    int id;
    int energy; //Se sumara durante el constructor de la trampa de viento y se restara durante su destructor
    int gold; //Se restara durante los constructores
    int gold_limit; //Se sumara dentro del constructor de la refineria o el silo
public:
    Player(int id);

    void addGold(int gold_to_add);
    void subGold(int gold_to_sub);
    void addEnergy(int energy_to_add);
    void subEnergy(int energy_to_sub);


    bool operator==(const Player& other) const;

};


#endif //__Player_H__
