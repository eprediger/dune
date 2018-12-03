#include "MainMenu.h"
#include "WindowMenu.h"

WindowMenu::WindowMenu() :
    status(WindowStatus::OPEN) {}

WindowMenu::~WindowMenu() {
    this->status = WindowStatus::CLOSE;
}

bool WindowMenu::keepWindowOpen() {
	return (this->status == WindowStatus::OPEN);
}

WindowStatus WindowMenu::windowStatus() const {
	return this->status;
}
