#ifndef __WINDOW_MENU_H__
#define __WINDOW_MENU_H__

#include <Controller/InputHandler.h>

class WindowMenu {
public:
    WindowMenu();

    virtual ~WindowMenu();

    virtual void run() = 0;

    bool keepWindowOpen();

    WindowStatus windowStatus() const;

protected:
    WindowStatus status;
};


#endif  // __WINDOW_MENU_H__
