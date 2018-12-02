#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include <View/MainMenuView.h>
#include <Controller/MainMenuHandler.h>

class MainMenu {
public:
	MainMenu(MainMenuView& view, MainMenuHandler& handler);
	
	~MainMenu();

	void run();

	std::string getHost() const;

	std::string getPort() const;

	int getWindowWidth() const;

	int getWindowHeight() const;

private:
	MainMenuView& view;
	MainMenuHandler& handler;
};

#endif	// __MAIN_MENU_H__
