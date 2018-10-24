//
// Created by emiliano on 24/10/18.
//

#include "SdlWindow.h"
#include "SdlException.h"

SdlWindow::SdlWindow(const int width, const int height) :
    width(width), height(height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw SdlException("Error en la inicialización", SDL_GetError());
    }
    if (SDL_CreateWindowAndRenderer(width, height, SDL_RENDERER_ACCELERATED,
                                    &this->window, &this->renderer)) {
        throw SdlException("Error al crear ventana", SDL_GetError());
    }
    SDL_SetWindowTitle(this->window, "Dune");
}

SdlWindow::~SdlWindow() {
    if (this->renderer != nullptr) {
        SDL_DestroyRenderer(this->renderer);
        this->renderer = nullptr;
    }

    if (this->window != nullptr) {
        SDL_DestroyWindow(this->window);
        this->window = nullptr;
    }
}

void SdlWindow::fill(const Uint8 r, const Uint8 g,
                     const Uint8 b, const Uint8 alpha) {
    SDL_SetRenderDrawColor(this->renderer, r, g, b, alpha);
    SDL_RenderClear(this->renderer);
}

void SdlWindow::fill() {
    this->fill(0xFF,0xFF,0xFF,0xFF);
}

void SdlWindow::render() {
    SDL_RenderPresent(this->renderer);
}

SDL_Renderer* SdlWindow::getRenderer() const {
    return this->renderer;
}
