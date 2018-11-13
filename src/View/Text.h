#ifndef __TEXT_H__
#define __TEXT_H__

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "SdlWindow.h"
#include "SdlTexture.h"

#define RED		0x55
#define GREEN	0x05
#define BLUE	0x27

class Text {
public:
	// Construye un texto a partir del string text
	// y lo agrega a la ventana window
	Text(const std::string& text, const int fontSize, SdlWindow& window);

	// Libera recursos de la instancia
	~Text();

	// Obtener el texto
	std::string getText();

	// Muestra el texto en la ventana en la posicion (x,y)
	virtual void render(const int x, const int y);

protected:
	// Actualiza el texto
	void createText(const std::string& text);

public:
	int textWidth, textHeight;

protected:
	std::string inputText;
	SdlWindow& window;
	SDL_Renderer* renderer;
	SDL_Surface* surface;
	SDL_Texture* texture;
	TTF_Font* font;
};

#endif	// __TEXT_H__
