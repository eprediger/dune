#ifndef __VIEW_H__
#define __VIEW_H__

#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Sound.h"
#include "Text.h"
#include "TextBox.h"

#define TITLE_FONT_SIZE 80

#define WINDOW_WIDTH  1240
#define WINDOW_HEIGHT 768

class View {
public:
	// Se inicializan recursos asociados a la vista
	View(const int width, const int height);

	// Se liberan recursos asociados a la instancia
	virtual ~View();

	// Se dibuja vista en la pantalla
	virtual void render() = 0;

	void closeWindow();

public:
	const int windowWidth, windowHeight;

protected:
	SdlWindow window;
};

#endif	// __VIEW_H__
