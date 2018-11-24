#ifndef __MAIN_MENU_HANDLER_H__
#define __MAIN_MENU_HANDLER_H__

#include "InputHandler.h"
#include "View/MainMenuView.h"

class MainMenuHandler : public InputHandler {
public:
	// Handler para menu principal
	explicit MainMenuHandler(MainMenuView& view);

	// Libera recursos asociados a la instancia
	~MainMenuHandler();
	
	bool handleInput() override;

private:
	MainMenuView& view;
};

#endif	// __MAIN_MENU_HANDLER_H__
