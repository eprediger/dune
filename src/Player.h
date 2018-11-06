#ifndef __Player_H__
#define __Player_H__


class Player {
private:
    int id;
public:
    Player(int id);

    bool operator==(const Player& other) const;

};


#endif //__Player_H__
