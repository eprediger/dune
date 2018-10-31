//
// Created by emiliano on 24/10/18.
//

#ifndef WINDOW_SDLTEXTURE_H
#define WINDOW_SDLTEXTURE_H

#include <SDL2/SDL_image.h>
#include "SdlWindow.h"
#include "SdlException.h"
#include "Area.h"
#include <string>

class SdlTexture {
public:
    SdlTexture(const std::string &filename, const SdlWindow& window);
    ~SdlTexture();

    SDL_Texture* loadTexture(const std::string &filename);

    int render(const Area &src, const Area &dest);

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};


#endif //WINDOW_SDLTEXTURE_H
