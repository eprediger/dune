#ifndef DUNE_BUTTONBUSY_H
#define DUNE_BUTTONBUSY_H

#include "ButtonState.h"

class ButtonBusy : public ButtonState {
public:
    ButtonBusy();

    ~ButtonBusy();

    virtual void handle(ButtonHandler *button, const int x, const int y) override;
};


#endif //DUNE_BUTTONBUSY_H
