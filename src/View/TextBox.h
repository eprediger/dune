#ifndef __TEXT_BOX_H__
#define __TEXT_BOX_H__

#include "Text.h"
/*
#define RED		0xCD
#define GREEN	0x65
#define BLUE	0x32
*/
#define BKG_RED		0xFF //0x04
#define BKG_GREEN	0xFF //0x09
#define BKG_BLUE	0xFF //0x26

#define MIN_BOX_WIDTH 200

class TextBox : public Text {
public:
	// Construye un texto EDITABLE a partir del string text
	// y lo agrega a la ventana window
	TextBox(const std::string& text, const int fontSize, SdlWindow& window);
	
	// Libera recursos de la instancia
	~TextBox();

	// Borra el ultimo caracter de la instancia
	void deleteText();

	// Inserta al final del texto el caracter 'text'
	void insert(const char* text);

	// Muestra el texto en la ventana en la posicion (x,y) con fondo
	void render(const int x, const int y) override;
};

#endif	// __TEXT_BOX_H__
