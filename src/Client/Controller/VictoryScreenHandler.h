#ifndef __VICTORYSCREENHANDLER_H__
#define __VICTORYSCREENHANDLER_H__


#include <Controller/InputHandler.h>
#include "View/VictoryScreenView.h"

class VictoryScreenHandler : public InputHandler {
public:
    // Handler para menu principal
    explicit VictoryScreenHandler(VictoryScreenView& view);

    // Libera recursos asociados a la instancia
    ~VictoryScreenHandler();

    virtual WindowStatus handleInput() override;
private:
    VictoryScreenView& view;
};


#endif //__VICTORYSCREENHANDLER_H__
