#include "Widget.h"

Widget::Widget(SdlWindow& window, const std::string& filename) :
    window(window),
    texture(nullptr) {
    this->texture = new SdlTexture(filename, window);
}

Widget::~Widget() {
    if (this->texture != nullptr) {
        free(this->texture);
        this->texture = nullptr;
    }
}

void Widget::draw() {
    Area src(0, 0, 80, 80*4/3);
//    int scaledWidth = texture->getWidth(), scaledHeight = texture->getHeigth();
    Area dest(650, 500, 80, 80*4/3);
    this->texture->render(src, dest);
}
