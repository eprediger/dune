#ifndef __PLAYER_VIEW_H__
#define __PLAYER_VIEW_H__

#include "Model/Player.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <Area.h>
#include "Text.h"
#include <map>
#include <memory>

class PlayerView {
public:
    PlayerView(Player& player, SdlWindow& window, int x, int width);

    ~PlayerView();

    void draw();

    void animateMoney();

    Player& player;

private:
    int x;
    int width;
    int r, g, b;
    int text_r, text_g, text_b;
    SdlWindow& window;
    Area background_area, house_src, house_dest;
    SDL_Rect rect;
    std::unique_ptr<SdlTexture> house;
    static std::unique_ptr<SdlTexture> background;
    Text* moneyTag, *moneyBalance;
    Text* capacityTag, *capacityBalance;
    int gold;
    std::map<Text*, int> balances;
};

#endif
