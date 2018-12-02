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

    std::string getWindowWidth() const;

    std::string getWindowHeight() const;

private:
	MainMenuView& view;
	std::string host, port;
    std::string windowWidth, windowHeight;
};

#endif	// __MAIN_MENU_HANDLER_H__
