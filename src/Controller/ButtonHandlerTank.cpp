#include "ButtonHandlerTank.h"
#include "../View/UnitViewFactory.h"
#include <iostream>

ButtonHandlerTank::ButtonHandlerTank(Model &model, GameView &view) :
	ButtonHandler(view.createUnitButton("../assets/img/btns/units/tank.gif"), model, view) {
}

ButtonHandlerTank::~ButtonHandlerTank() {}

void ButtonHandlerTank::execute() {
	Tank& newUnit = model.createTank(500, 500, 0);
	view.addUnitView(UnitViewFactory::createUnitView(newUnit, view.getWindow()));
}
