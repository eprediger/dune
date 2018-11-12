#include "MainMenuHandler.h"

MainMenuHandler::MainMenuHandler(MainMenuView& view) :
	InputHandler(),
	view(view) {
	SDL_StartTextInput();
}

MainMenuHandler::~MainMenuHandler() {
	SDL_StopTextInput();
}

bool MainMenuHandler::handleInput() {
	SDL_Event event;
	SDL_PollEvent(&(event));
	switch (event.type) {
	case SDL_QUIT:
		return false;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT) {
			this->cursor.currentPosition();
			return this->view.setFocusOn(this->cursor.current_x, this->cursor.current_y);
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
			this->view.getTextBoxContent();
			return false;
		}
		break;
	// Insertar texto
	case SDL_TEXTINPUT:
		this->view.insertTextToTextBox(event.text.text);
		break;
	}
	return true;
}
