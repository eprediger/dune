#ifndef __SDLTEXTURE_H__
#define __SDLTEXTURE_H__

#include <SDL2/SDL_image.h>
#include "SdlWindow.h"
#include "SdlException.h"
#include "Area.h"
#include <string>

class SdlTexture {
public:
	SdlTexture(const std::string& filename, const SdlWindow& window);

	~SdlTexture();

	SDL_Texture* loadTexture(const std::string &filename);

	int setColor(const int& playerKey);

	int render(const Area &src, const Area &dest);

	// renderiza la textura completa en su tamaño original,
	// en la posición (x, y) de la ventana
	int render(const int x, const int y);

	int width, height;
private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
};

#endif  // __SDLTEXTURE_H__
