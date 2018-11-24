#include "PlayerColorMaker.h"

PlayerColorMaker::PlayerColorMaker() {}

void PlayerColorMaker::makeColor(Player& player, int* r, int* g, int* b) {
    *r = *g = *b = 0;
    switch (player.getId()) {
    case 0:
        *r = 150;
        break;
    case 1:
        *b = 150;
        break;
    case 2:
        *g = 150;
        break;
    default:
        break;
    }
}

void PlayerColorMaker::menuColor(Player& player, int*r, int*g, int*b) {
    switch (player.getId()) {
    case 0:
        *r = 150;
        *b = 25;
        *g = 25;
        break;
    case 1:
        *r = 25;
        *b = 150;
        *g = 25;
        break;
    case 2:
        *r = 25;
        *b = 25;
        *g = 150;
        break;
    default:
        break;
    }
}

void PlayerColorMaker::textColor(Player& player, int*r, int*g, int*b) {
    switch (player.getId()) {
    case 0:
        *r = 204;
        *g = 0;
        *b = 0;
        break;
    case 1:
        *r = 0;
        *g = 0;
        *b = 150;
        break;
    case 2:
        *r = 0;
        *g = 80;
        *b = 0;
        break;
    default:
        break;
    }
}
