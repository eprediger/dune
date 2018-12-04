#ifndef __DEFEATED_SCREEN_H__
#define __DEFEATED_SCREEN_H__


#include "View/DefeatedScreenView.h"
#include "Controller/DefeatedScreenHandler.h"

class DefeatedScreen {
public:
    DefeatedScreen(DefeatedScreenView& view, DefeatedScreenHandler& handler);

    void run();

private:
    DefeatedScreenView& view;
    DefeatedScreenHandler& handler;
};


#endif //__DEFEATED_SCREEN_H__
