#include "Text.h"
#include <string>

Text::Text(const std::string& text, const int fontSize, SdlWindow& window) :
	textWidth(0),
	textHeight(0),
	inputText(text),
	window(window),
	renderer(window.getRenderer()),
	surface(nullptr),
	texture(nullptr),
	font(nullptr) {
	if (TTF_Init() == -1) {
		throw SdlException("Error al inicializar fuente", TTF_GetError());
	}
	this->font = TTF_OpenFont("../assets/font/Dune2k.ttf", fontSize);
	if (this->font == nullptr) {
		throw SdlException("Error al cargar la fuente", TTF_GetError());
	}
	this->createText(text);
}

Text::Text(const std::string& text, const int fontSize, SdlWindow& window, int r, int g, int b) :
	textWidth(0),
	textHeight(0),
	inputText(text),
	window(window),
	renderer(window.getRenderer()),
	surface(nullptr),
	texture(nullptr),
	font(nullptr) {
	if (TTF_Init() == -1) {
		throw SdlException("Error al inicializar fuente", TTF_GetError());
	}
	this->font = TTF_OpenFont("../assets/font/Dune2k.ttf", fontSize);
	if (this->font == nullptr) {
		throw SdlException("Error al cargar la fuente", TTF_GetError());
	}
	this->createText(text, r, g, b);
}

Text::~Text() {
	if (this->font != nullptr) {
		TTF_CloseFont(this->font);
		this->font = nullptr;
	}
	if (this->surface != nullptr) {
		SDL_FreeSurface(this->surface);
		this->surface = nullptr;
	}
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}
	TTF_Quit();
}

void Text::createText(const std::string& text) {
	SDL_Color fntColor = {RED, GREEN, BLUE};
	// SDL_Color fntColor = { 0x0, 0xFF, 0x0 };
	if (this->surface != nullptr) {
		SDL_FreeSurface(this->surface);
	}
	this->surface = TTF_RenderText_Blended(this->font, text.c_str(), fntColor);
	// SDL_Color bkgColor = { 0x33, 0x33, 0x33 };
	// this->surface = TTF_RenderText_Shaded(this->font, text.c_str(), fntColor, bkgColor);
	if (this->surface == nullptr) {
		throw SdlException("Error al crear superficie", SDL_GetError());
	}
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
	}
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (this->texture == nullptr) {
		throw SdlException("Error al crear textura", SDL_GetError());
	}
	SDL_QueryTexture(this->texture, NULL, NULL,
	                 &(this->textWidth), &(this->textHeight));
}

void Text::createText(const std::string& text, int r, int g, int b) {
	SDL_Color fntColor = { (Uint8) r, (Uint8) g, (Uint8) b };
	// SDL_Color fntColor = { 0x0, 0xFF, 0x0 };
	if (this->surface != nullptr) {
		SDL_FreeSurface(this->surface);
	}
	this->surface = TTF_RenderText_Blended(this->font, text.c_str(), fntColor);
	// SDL_Color bkgColor = { 0x33, 0x33, 0x33 };
	// this->surface = TTF_RenderText_Shaded(this->font, text.c_str(), fntColor, bkgColor);
	if (this->surface == nullptr) {
		throw SdlException("Error al crear superficie", SDL_GetError());
	}
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
	}
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (this->texture == nullptr) {
		throw SdlException("Error al crear textura", SDL_GetError());
	}
	SDL_QueryTexture(this->texture, NULL, NULL,
	                 &(this->textWidth), &(this->textHeight));
}

std::string Text::getText() const {
	return this->inputText;
}

void Text::setText(const std::string& newText) {
	this->inputText = newText;
	this->createText(this->inputText);
}

void Text::setText(const std::string& newText, int r, int g, int b) {
	this->inputText = newText;
	this->createText(this->inputText, r, g, b);
}

void Text::render(const int x, const int y) {
	// Rectangulo
	// SDL_SetRenderDrawColor(this->renderer, 0x33, 0x33, 0x33, 0xFF);
	/*SDL_SetRenderDrawColor(this->renderer, BKG_RED, BKG_GREEN, BKG_BLUE, 0xFF);
	SDL_Rect boxRect = {x, y, textWidth, textHeight};
	SDL_RenderFillRect(this->renderer, &boxRect);*/

	SDL_Rect dstrect = {x, y, textWidth, textHeight};
	SDL_RenderCopy(this->renderer, this->texture, NULL, &dstrect);
}

/*void Text::render(const Area& dest) {
	SDL_Rect dstrect = {dest.getX(), dest.getY(),
	                    dest.getWidth(), dest.getHeight()
	                   };

	SDL_RenderCopy(this->renderer, this->texture, NULL, &dstrect);
}*/
