#include "ButtonHandlerHarvester.h"
#include "UnitViewFactory.h"
#include <iostream>

ButtonHandlerHarvester::ButtonHandlerHarvester(Model &model, GameView &view) :
        ButtonHandler(view.createUnitButton("../assets/img/btns/units/harvest.gif"), model, view) {
}

void ButtonHandlerHarvester::execute() {
    Harvester& newHarvester = model.createHarvester(500, 500, 0);
    view.addUnitView(UnitViewFactory::createUnitView(newHarvester, view.getWindow()));
}
