#ifndef __BUTTON_HANDLER_HARVESTER_H__
#define __BUTTON_HANDLER_HARVESTER_H__

#include "ButtonHandler.h"

class ButtonHandlerHarvester : public ButtonHandler {
public:
    ButtonHandlerHarvester(Model &model, GameView &view);

    virtual void execute();
};


#endif  // __BUTTON_HANDLER_HARVESTER_H__
