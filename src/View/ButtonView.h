#ifndef __BUTTON_H__
#define __BUTTON_H__

// #include "ButtonViewState.h"
#include "SdlTexture.h"
#include "TimerView.h"
#include <string>

// El boton cuenta con tres estados:
// HIDDEN: no se dibuja el botón
// ENABLE: botón habilitado se dibuja en pantalla
// DISABLE: si no hay dinero disponible se deshabilita el boton
// BUSY: durante la construcción de edificios o
// creación de unidades se muestra el botón desahabilitado
enum class ViewState { HIDDEN, ENABLED, DISABLED, BUSY, READY };

class ButtonView {
public:
	// 
    ButtonView(const std::string &filename, const SdlWindow &window, int number_steps);
	
	// 
	virtual ~ButtonView();
	
	bool isClicked(const int x, const int y);
	

	void update();

	// 
	void setState(const ViewState newState);

	virtual void render(const Area &dest);

private:
	ViewState buttonState;
	// ButtonViewState* currentState;
	SdlTexture buttonImage;
	TimerView timer;
public:
	int x, y;
	int width, height;
};

#endif	// __BUTTON_H__
