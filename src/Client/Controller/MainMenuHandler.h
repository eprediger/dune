#ifndef __MAIN_MENU_HANDLER_H__
#define __MAIN_MENU_HANDLER_H__

#include <Controller/InputHandler.h>
#include <View/MainMenuView.h>
#include <string>

class MainMenuHandler : public InputHandler {
public:
	// Handler para menu principal
	explicit MainMenuHandler(MainMenuView& view);

	// Libera recursos asociados a la instancia
	~MainMenuHandler();
	
	bool handleInput() override;

	std::string getHost() const;

	std::string getPort() const;

private:
	MainMenuView& view;
	std::string host, port;
};

#endif	// __MAIN_MENU_HANDLER_H__
