//
// Created by emiliano on 24/10/18.
//

#include "SdlTexture.h"

SdlTexture::SdlTexture(const std::string &filename, const SdlWindow &window) :
    renderer(window.getRenderer()) {
    this->texture = loadTexture(filename);
}

SDL_Texture* SdlTexture::loadTexture(const std::string &filename) {
    SDL_Texture* texture;
    SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
    if (loadedSurface == nullptr) {
        throw SdlException("Error al cargar la textura", SDL_GetError());
    } else {
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0) );
        texture = SDL_CreateTextureFromSurface(this->renderer, loadedSurface);
        if (texture == nullptr) {
            throw SdlException("Error al cargar la textura", SDL_GetError());
        }
    }
    return texture;
}

SdlTexture::~SdlTexture() {
    SDL_DestroyTexture(this->texture);
}

int SdlTexture::render(const Area &src, const Area &dest) {
    SDL_Rect sdlSrc = {src.getX(), src.getY(),
                       src.getWidth(), src.getHeight()};
    SDL_Rect sdlDest = {dest.getX(), dest.getY(),
                        dest.getWidth(), dest.getHeight()};

    return SDL_RenderCopy(this->renderer, this->texture, &sdlSrc, &sdlDest);
}
