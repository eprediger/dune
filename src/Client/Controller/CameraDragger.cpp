#include "CameraDragger.h"

CameraDragger::CameraDragger(GameView &view) : view(view), sensivity(SENSIVITY), drag_on(false) {}

void CameraDragger::on(Position initial) {
    drag_on = true;
    reference = initial;
}

void CameraDragger::move(Position move_pos) {
    if (reference.x > move_pos.x){
        view.moveLeft((reference.x - move_pos.x) / sensivity);
    } else {
        view.moveRight((move_pos.x - reference.x) / sensivity);
    }
    if (reference.y > move_pos.y){
        view.moveUp((reference.y - move_pos.y) / sensivity);
    } else {
        view.moveDown((move_pos.y - reference.y) / sensivity);
    }

}

void CameraDragger::off() {
    drag_on = false;
}

bool CameraDragger::isOn() {
    return drag_on;
}

