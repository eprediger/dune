#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <string>
#include "SdlTexture.h"
//#include "ButtonState.h"

class ButtonView {
public:
	// El boton cuenta con tres estados:
	// HIDDEN: no se dibuja el botón
	// ENABLE: botón habilitado se dibuja en pantalla
	// DISABLE: durante la construcción de edificios o
	// creación de unidades se muestra el botón desahabilitado
	enum class State { HIDDEN, ENABLE, DISABLE };

	// 
	ButtonView(const std::string& filename, const SdlWindow& window);
	
	// 
	virtual ~ButtonView();
	
	// 
	void changeState(State newState);

	bool isClicked(const int x, const int y);

	void execute();
	
	virtual void render(const Area &dest);

private:
	SdlTexture buttonImage;
//	ButtonState* currentState;
public:
	int x, y, width, height;
};

#endif	// __BUTTON_H__
