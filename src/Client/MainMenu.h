#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include <WindowMenu.h>
#include <View/MainMenuView.h>
#include <Controller/MainMenuHandler.h>
#include <string>

class MainMenu : public WindowMenu {
public:
	MainMenu();

	virtual ~MainMenu() = default;

	void run() override;

	std::string getHost() const;

	std::string getPort() const;

	int getWindowWidth() const;

	int getWindowHeight() const;

	std::string getPlayerName() const;

private:
	MainMenuView view;
	MainMenuHandler handler;
};

#endif	// __MAIN_MENU_H__
