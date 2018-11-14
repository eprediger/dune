#include "SdlWindow.h"
#include "SdlException.h"

SdlWindow::SdlWindow(const int width, const int height) :
	width(width),
	height(height),
	window(nullptr),
	renderer(nullptr),
	iconSurface(nullptr) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		throw SdlException("Error en la inicialización", SDL_GetError());
	}
	if (SDL_CreateWindowAndRenderer(width, height, SDL_RENDERER_ACCELERATED | SDL_WINDOW_BORDERLESS,
	                                &this->window, &this->renderer)) {
		throw SdlException("Error al crear ventana", SDL_GetError());
	}
	SDL_SetWindowTitle(this->window, "Dune");
}

SdlWindow::~SdlWindow() {
	if (this->iconSurface != nullptr) {
		SDL_FreeSurface(this->iconSurface);
		this->iconSurface = nullptr;
	}
	if (this->renderer != nullptr) {
		SDL_DestroyRenderer(this->renderer);
		this->renderer = nullptr;
	}
	if (this->window != nullptr) {
		SDL_DestroyWindow(this->window);
		this->window = nullptr;
	}
	SDL_Quit();
}

void SdlWindow::grabMouse(bool grab) {
	grab ? SDL_SetWindowGrab(window, SDL_TRUE) : SDL_SetWindowGrab(window, SDL_FALSE);
	/*if (grab) {
		SDL_SetWindowGrab(window, SDL_TRUE);
	} else {
		SDL_SetWindowGrab(window, SDL_FALSE);
	}*/
}

void SdlWindow::fill(const Uint8 r, const Uint8 g,
					 const Uint8 b, const Uint8 alpha) {
	SDL_SetRenderDrawColor(this->renderer, r, g, b, alpha);
	SDL_RenderClear(this->renderer);
}

void SdlWindow::fill() {
	this->fill(0x0, 0x0, 0x0, 0x0);
}

void SdlWindow::render() {
	SDL_RenderPresent(this->renderer);
}

SDL_Renderer* SdlWindow::getRenderer() const {
	return this->renderer;
}
