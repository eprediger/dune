#ifndef DUNE_WIDGET_H
#define DUNE_WIDGET_H

#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Area.h"

class Widget {
public:
    // PRE:  window en estado valido
    // POST: Se inicializa Widget
    Widget(SdlWindow& window, const std::string& filename);

    // Se libera recurso asociado
    ~Widget();


    void draw();
private:
    SdlWindow& window;
    SdlTexture* texture;
};


#endif //DUNE_WIDGET_H
