#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <string>
#include "SdlTexture.h"
//#include "ButtonState.h"

class Button {
public:
	// El boton cuenta con tres estados:
	// HIDDEN: no se dibuja el botón
	// ENABLE: botón habilitado se dibuja en pantalla
	// DISABLE: durante la construcción de edificios o
	// creación de unidades se muestra el botón desahabilitado
	enum class State { HIDDEN, ENABLE, DISABLE };

	// 
	Button(const std::string& filename, const SdlWindow& window);
	
	// 
	virtual ~Button();
	
	// 
	void changeState(State newState);
	
	virtual void render(const Area &dest);

private:
	SdlTexture buttonImage;
//	ButtonState* currentState;
};

#endif	// __BUTTON_H__
