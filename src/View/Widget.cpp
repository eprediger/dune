#include "Widget.h"

Widget::Widget(SdlWindow& window, const std::string& filename) :
    window(window),
    texture(nullptr) {
    this->texture = new SdlTexture(filename, window);
//    this->texture = new SdlTexture("../imgs/Ordos.jpg", window);
//    this->texture = new SdlTexture("../imgs/House_Atreides_Insignia.jpg", window);
//    this->texture = new SdlTexture("../imgs/House_Harkonnen_Insignia.jpg", window);
//    this->texture = new SdlTexture("../imgs/atreides.jpg", window);
//    this->texture = new SdlTexture("../imgs/dune2000_5.jpg", window);
//    this->texture = new SdlTexture("../imgs/dune2000_6.jpg", window);
//    this->texture = new SdlTexture("../imgs/dune2000_4.jpg", window);
//    this->texture = new SdlTexture("../imgs/dune.jpg", window);
}

Widget::~Widget() {
    if (this->texture != nullptr) {
        free(this->texture);
        this->texture = nullptr;
    }
}

void Widget::draw() {
    Area src(0, 0, 66, 66);
    int scaledWidth = texture->getWidth(), scaledHeight = texture->getHeigth();
    Area dest(650, 500, 66, 66);
    this->texture->render(src, dest);
}