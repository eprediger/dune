#include "MainMenu.h"

MainMenu::MainMenu(MainMenuView& view, MainMenuHandler& handler) :
	view(view),
	handler(handler) {}

MainMenu::~MainMenu() {}

void MainMenu::run() {
	do {
		this->view.render();
	} while (this->handler.handleInput());
	this->view.closeWindow();
}

std::string MainMenu::getHost() const {
	return this->handler.getHost();
}

std::string MainMenu::getPort() const {
	return this->handler.getPort();
}

int MainMenu::getWindowWidth() const {
	return std::stoi(this->handler.getWindowWidth());
}

int MainMenu::getWindowHeight() const {
	return std::stoi(this->handler.getWindowHeight());
}

