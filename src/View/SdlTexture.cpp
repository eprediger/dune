//
// Created by emiliano on 24/10/18.
//

#include "SdlTexture.h"
#include <iostream>
SdlTexture::SdlTexture(const std::string &filename, const SdlWindow &window) :
    renderer(window.getRenderer()),
    texture(nullptr),
    textureWidth(0),
    textureHeight(0) {
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
        SDL_QueryTexture(this->texture, NULL, NULL, &this->textureWidth, &this->textureHeight);
    }
    return texture;
}

int SdlTexture::getWidth() {
    return this->textureWidth;
}

int SdlTexture::getHeigth() {
    return this->textureHeight;
}

int SdlTexture::setColor(){
    SDL_SetTextureColorMod(this->texture,128,32,32);
}

SdlTexture::~SdlTexture() {
    SDL_DestroyTexture(this->texture);
}

int SdlTexture::render(const Area &src, const Area &dest) {
    SDL_Rect sdlSrc = {src.getX(), src.getY(),
                       src.getWidth(), src.getHeight()};
    SDL_Rect sdlDest = {dest.getX(), dest.getY(),
                        dest.getWidth(), dest.getHeight()};
    int a = SDL_RenderCopy(this->renderer, this->texture, &sdlSrc, &sdlDest);
}
