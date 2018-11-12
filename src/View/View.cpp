#include "View.h"

View::View(const int width, const int height) :
        window(width, height) {
    this->window.fill();
}

View::~View() {}
