#ifndef __BUTTON_VIEW_H__
#define __BUTTON_VIEW_H__

#include "SdlTexture.h"
#include "TimerView.h"
#include <string>

// El boton cuenta con tres estados:
// HIDDEN: no se dibuja el botón
// ENABLE: botón habilitado se dibuja en pantalla
// DISABLE: si no hay dinero disponible se deshabilita el boton
// BUSY: durante la construcción de edificios o
// creación de unidades se muestra el botón desahabilitado
enum class ViewState { HIDDEN, ENABLED, DISABLED, BUSY };

class ButtonView {
public:
	// Constructor para botones con timer
	// PRE: la imagen debe contener todos los sprites dispuestos horizontalmente
	ButtonView(const std::string &filename, const SdlWindow &window, int number_steps);

	// Constructor para botones sin timer
	ButtonView(const std::string &filename, const SdlWindow &window);

	virtual ~ButtonView();

	bool isClicked(const int x, const int y);

	void update();

	// Setea el estado de la vista para determinar que se renderiza
	void setState(const ViewState newState);

	// PRE:
	// en base al estado del botón se renderizan distintas imagenes.
	virtual void render(const Area &dest);

private:
	ViewState buttonState;
	SdlTexture buttonImage;
	TimerView timer;

public:
	int x, y;
	int width, height;
};

#endif	// __BUTTON_VIEW_H__
