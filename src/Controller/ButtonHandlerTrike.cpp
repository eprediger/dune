#include "ButtonHandlerTrike.h"
#include "../View/UnitViewFactory.h"
#include <iostream>

ButtonHandlerTrike::ButtonHandlerTrike(Model &model, GameView &view) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/trike.jpg"), model, view) {
}

ButtonHandlerTrike::~ButtonHandlerTrike() {}

void ButtonHandlerTrike::execute() {
	Trike& newUnit = model.createTrike(500, 500, 0);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}
