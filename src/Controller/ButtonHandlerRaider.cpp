#include "ButtonHandlerRaider.h"
#include "../View/UnitViewFactory.h"
#include <iostream>

ButtonHandlerRaider::ButtonHandlerRaider(Model &model, GameView &view) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/raider.gif"), model, view) {
}

ButtonHandlerRaider::~ButtonHandlerRaider() {}

void ButtonHandlerRaider::execute() {
	Raider& newUnit = model.createRaider(500, 500, 0);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}
