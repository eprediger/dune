#include "PlayerView.h"
#include "PlayerColorMaker.h"
#include "Text.h"
#include <memory>
#include <map>

std::unique_ptr<SdlTexture> PlayerView::background;

PlayerView::PlayerView(Player& player, SdlWindow& window, int x, int width) :
    player(player),
    x(x),
    width(width),
    window(window),
    background_area(Area(0, 0, 32, 32)),
    house_src(0, 0, 300, 300),
    house_dest(x + width / 5, window.height * 2 / 32, width * 3 / 5, window.height * 5 / 32),
    moneyTag(nullptr),
    moneyBalance(nullptr),
    capacityTag(nullptr),
    capacityBalance(nullptr),
    gold(player.gold),
    balances() {
    if (player.getHouse() == "Ordos") {
        house = std::move(std::unique_ptr<SdlTexture>(new SdlTexture("../assets/img/houses/ordos.jpg", window)));
    } else if (player.getHouse() == "Harkonnen") {
        house = std::move(std::unique_ptr<SdlTexture>(new SdlTexture("../assets/img/houses/harkonnen.jpg", window)));
    } else if (player.getHouse() == "Atreides") {
        house = std::move(std::unique_ptr<SdlTexture>(new SdlTexture("../assets/img/houses/atreides.jpg", window)));
    }
    PlayerColorMaker::menuColor(player, &r, &g, &b);
    PlayerColorMaker::textColor(player, &text_r, &text_g, &text_b);
    background = std::move(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002396b2.bmp", window)));
    moneyTag = new  Text("DINERO", 16, window, text_r, text_g, text_b);
    moneyBalance = new Text(std::to_string(player.gold), 16, window, text_r, text_g, text_b);
    capacityTag = new Text("CAPACIDAD", 16, window, text_r, text_g, text_b);
    capacityBalance = new Text(std::to_string(player.getGoldLimit()), 16, window, text_r, text_g, text_b);
    rect.x = x + width / 5;
    rect.y = this->window.height * 2 / 32;
    rect.w = width * 3 / 5;
    rect.h = this->window.height * 5 / 32;
}

PlayerView::~PlayerView() {
    if (moneyTag != nullptr) {
        delete this->moneyTag;
        this->moneyTag = nullptr;
    }
    if (moneyBalance != nullptr) {
        delete this->moneyBalance;
        this->moneyBalance = nullptr;
    }
    if (capacityTag != nullptr) {
        delete this->capacityTag;
        this->capacityTag = nullptr;
    }
    if (capacityBalance != nullptr) {
        delete this->capacityBalance;
        this->capacityBalance = nullptr;
    }
}

void PlayerView::draw() {
    Area dest(0, 0, 32, 32);
    for (int i = 0; i <= width ; i += 32) {
        dest.setX(x + i);
        for (int j = 0; j <= window.height ; j += 32) {
            dest.setY(j);
            background->render(background_area, dest);
        }
        dest.setY(0);
    }
    SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_NONE);

    SDL_SetRenderDrawColor(window.getRenderer(), r, g, b, 130);
    SDL_RenderDrawRect(window.getRenderer(), &rect);
    SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_RenderFillRect(window.getRenderer(), &rect);
    house->render(house_src, house_dest);
    this->moneyTag->render((this->window.width - this->moneyTag->textWidth) * 18 / 20, this->window.height * 9 / 32);
    this->moneyBalance->setText(std::to_string(player.gold), text_r, text_g, text_b);
    this->moneyBalance->render((this->window.width - this->moneyBalance->textWidth) * 18 / 20 + this->moneyTag->textWidth,
                               this->window.height * 9 / 32);
    this->capacityTag->render((this->window.width - this->capacityTag->textWidth) * 18 / 20,
                              this->window.height * 9 / 32 + this->moneyTag->textHeight);
    this->capacityBalance->setText(std::to_string(player.getGoldLimit()), text_r, text_g, text_b);
    this->capacityBalance->render((this->window.width - this->capacityBalance->textWidth) * 18 / 20 + this->capacityTag->textWidth,
                                  this->window.height * 9 / 32 + this->moneyTag->textHeight);
    if (player.gold != gold || !balances.empty()) {
        animateMoney();
    }
}

void PlayerView::animateMoney() {
    int balance = player.gold - gold;
    gold = player.gold;
    if (balance != 0)
        balances.insert(std::make_pair(new Text(std::to_string(balance), 16, window, text_r, text_g, text_b), 25));
    std::map<Text*, int>::iterator it = balances.begin();
    while (it != balances.end()) {
        it->first->render((this->window.width - this->moneyBalance->textWidth) * 18 / 20 + this->moneyTag->textWidth,
                          this->window.height * 9 / 32 - (15 - it->second));
        it->second -= 1;
        if (it->second == 0) {
            delete(it->first);
            it = balances.erase(it);
        } else {
            it++;
        }
    }
}
