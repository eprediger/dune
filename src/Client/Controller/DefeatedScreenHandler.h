#ifndef __DEFEATEDSCREENHANDLER_H__
#define __DEFEATEDSCREENHANDLER_H__


#include <Controller/InputHandler.h>
#include "View/DefeatedScreenView.h"

class DefeatedScreenHandler : public InputHandler {
public:
    explicit DefeatedScreenHandler(DefeatedScreenView& view);

    ~DefeatedScreenHandler();

    virtual WindowStatus handleInput() override;
private:
    DefeatedScreenView& view;
};


#endif //__DEFEATEDSCREENHANDLER_H__
 