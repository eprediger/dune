#include "MainMenuHandler.h"
#include <string>

MainMenuHandler::MainMenuHandler(MainMenuView& view) :
	InputHandler(),
	view(view),
	host(),
	port() {
	SDL_StartTextInput();
}

MainMenuHandler::~MainMenuHandler() {
	SDL_StopTextInput();
}

WindowStatus MainMenuHandler::handleInput() {
	WindowStatus handleResult = WindowStatus::OPEN;
	SDL_Event event;
	SDL_WaitEvent(&(event));
	switch (event.type) {
	case SDL_QUIT:
		handleResult = WindowStatus::CLOSE;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT) {
			this->cursor.currentPosition();
			if (!(this->view.setFocusOn(this->cursor.current_x,
			                            this->cursor.current_y))) {
				handleResult = WindowStatus::NEXT_WINDOW;
			}
		}
		break;
	case SDL_KEYDOWN:
		// Handle backspace
		if (event.key.keysym.sym == SDLK_BACKSPACE) {
			this->view.deleteFromTextBox();
		}
		// Con tabulación paso al siguiente textBox
		if (event.key.keysym.sym == SDLK_TAB) {
			this->view.selectNextTextBox();
		}
		// Enter pasa a la siguiente pantalla
		if (event.key.keysym.sym == SDLK_RETURN) {
			handleResult = WindowStatus::NEXT_WINDOW;
		}
		break;
	// Insertar texto
	case SDL_TEXTINPUT:
		this->view.insertTextToTextBox(event.text.text);
		break;
	default:
		break;
	}
	this->host = this->view.getHost();
	this->port = this->view.getPort();
	this->windowWidth = this->view.getWindowWidth();
	this->windowHeight = this->view.getWindowHeight();
	this->playerName = this->view.getPlayerName();
	return handleResult;
}

std::string MainMenuHandler::getHost() const {
	return this->host;
}

std::string MainMenuHandler::getPort() const {
	return this->port;
}

std::string MainMenuHandler::getWindowWidth() const {
	return this->windowWidth;
}

std::string MainMenuHandler::getWindowHeight() const {
	return this->windowHeight;
}

std::string MainMenuHandler::getPlayerName() const {
	return this->playerName;
}
