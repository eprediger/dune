#include "MainMenu.h"
#include "WindowMenu.h"

MainMenu::MainMenu() :
	WindowMenu(),
	view(WINDOW_WIDTH, WINDOW_HEIGHT),
	handler(view) {}

void MainMenu::run() {
	do {
		this->view.render();
		this->status = this->handler.handleInput();
	} while (this->keepWindowOpen());
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
