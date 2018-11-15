#include "PlayerColorMaker.h"

PlayerColorMaker::PlayerColorMaker() {}

void PlayerColorMaker::makeColor(Player& player, int* r, int* g, int* b) {
    *r = *g = *b = 0;
    switch (player.getId()) {
    case 0:
        *r = 255;
        break;
    case 1:
        *b = 255;
        break;
    case 2:
        *g = 255;
        break;
    default:
        break;
    }
}
