#ifndef __SDLWINDOW_H__
#define __SDLWINDOW_H__

#include <SDL2/SDL.h>

class SdlWindow {
public:
	// PRE:  width > 0 && height > 0
	// POST: inicializa ventana
	SdlWindow(int width, int height);

	// Libera recursos asociados a la instancia
	~SdlWindow();

	void destroyWindow();

	// 
	void fill();

	// 
	void fill(Uint8 r, Uint8 g, Uint8 b, Uint8 alpha);

	// Dibuja render en pantalla
	void render();

	// 
	void grabMouse(bool grab);

	// Retorna render de la instancia
	SDL_Renderer* getRenderer() const;

	void toggleFullScreen();

	const int width, height;
	
private:
	bool full_screen;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* iconSurface;
};

#endif	// __SDLWINDOW_H__
