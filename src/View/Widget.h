#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Area.h"

class Widget {
public:
	// PRE:  filename ruta a archivo valida
	// POST: Se inicializa Widget
	Widget(SdlWindow& window, const std::string& filename);

	// Se libera recurso asociado
	~Widget();

	void draw();
private:
	SdlWindow& window;
	SdlTexture* texture;
};

#endif	// __WIDGET_H__
