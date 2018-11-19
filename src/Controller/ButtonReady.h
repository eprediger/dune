#ifndef DUNE_BUTTONREADY_H
#define DUNE_BUTTONREADY_H

#include "ButtonState.h"

class ButtonReady : public ButtonState {
public:
    ButtonReady();

    ~ButtonReady();

    virtual void handle(ButtonHandler *button, const int x, const int y) override;
    virtual void update(ButtonHandler *button) override;
};


#endif  // DUNE_BUTTONREADY_H
