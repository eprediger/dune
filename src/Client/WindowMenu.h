#ifndef __WINDOW_MENU_H__
#define __WINDOW_MENU_H__

#include <Controller/InputHandler.h>

class WindowMenu {
public:
    WindowMenu();

    virtual ~WindowMenu();

    //	Loop de las ventanas de menus
    virtual void run() = 0;

    //	Retorna true si la ventana debe continuar abierta
    bool keepWindowOpen();

    //	Retorna el estado de la ventana
    WindowStatus windowStatus() const;

protected:
    WindowStatus status;
};

#endif  // __WINDOW_MENU_H__
