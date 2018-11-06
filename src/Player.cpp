#include "Player.h"

Player::Player(int id) : id(id){

}

bool Player::operator==(const Player &other) const {
    return this->id == other.id;
}
