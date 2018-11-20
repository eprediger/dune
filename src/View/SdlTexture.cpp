#include "SdlTexture.h"
#include <string>

SdlTexture::SdlTexture(const std::string& filename, const SdlWindow& window) :
	width(0),
	height(0),
	renderer(window.getRenderer()),
	texture(nullptr) {
	this->texture = loadTexture(filename);
}

SdlTexture::~SdlTexture() {
	if (this->texture != nullptr) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}
	if (this->surface != nullptr) {
		SDL_FreeSurface(surface);
		this->surface = nullptr;
	}
}

SDL_Texture* SdlTexture::loadTexture(const std::string& filename) {
	this->surface = IMG_Load(filename.c_str());
	if (surface == nullptr) {
		throw SdlException("Error al cargar la textura", SDL_GetError());
	} else {
		SDL_SetColorKey(surface, SDL_TRUE,
		                SDL_MapRGB(surface->format, 0, 0, 0));
		this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
		if (this->texture == nullptr) {
			throw SdlException("Error al crear la textura", SDL_GetError());
		}
		SDL_QueryTexture(this->texture, NULL, NULL, &this->width, &this->height);
	}
	return this->texture;
}

int SdlTexture::setColor(int& r, int& g, int& b) {
	return SDL_SetTextureColorMod(texture, r, g, b);
}

int SdlTexture::setBlendMode(SDL_BlendMode mode){
	return SDL_SetTextureBlendMode(texture, mode); 
}

int SdlTexture::render(const Area& src, const Area& dest) {
	SDL_Rect sdlSrc = { src.getX(), src.getY(),
	                    src.getWidth(), src.getHeight()
	                  };
	SDL_Rect sdlDest = { dest.getX(), dest.getY(),
	                     dest.getWidth(), dest.getHeight()
	                   };
	return SDL_RenderCopy(this->renderer, this->texture, &sdlSrc, &sdlDest);
}

int SdlTexture::render(const int x, const int y) {
	SDL_Rect sdlDest = {x, y, this->width, this->height};
	return SDL_RenderCopy(this->renderer, this->texture, NULL, &sdlDest);
}
