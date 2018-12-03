#include "TextBox.h"
#include <string>

TextBox::TextBox(const std::string& text,
                 const int fontSize, SdlWindow& window) :
	Text(text, fontSize, window) {
	this->createText(this->inputText);
}

TextBox::~TextBox() {}

void TextBox::deleteText() {
	if (this->inputText.length() > 0) {
		this->inputText.pop_back();
	}
	if (this->inputText.length() == 0) {
		this->createText(" ");
	} else {
		this->createText(this->inputText);
	}
}

void TextBox::insert(const char* text) {
	this->inputText.append(text);
	this->createText(this->inputText);
}

void TextBox::render(const int x, const int y) {
	// Rectangulo
	SDL_SetRenderDrawColor(this->renderer, BKG_RED, BKG_GREEN, BKG_BLUE, 0xFF);
	int boxWidth = 200 > textWidth ? 200 : textWidth;
	SDL_Rect boxRect = {x, y, boxWidth, (textHeight * 9 / 10)};
	SDL_RenderFillRect(this->renderer, &boxRect);

	SDL_Rect dstrect = {x, y, textWidth, textHeight};
	SDL_RenderCopy(this->renderer, this->texture, NULL, &dstrect);
}
