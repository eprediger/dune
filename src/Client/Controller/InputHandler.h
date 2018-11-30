#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include "InputHandler.h"
#include "View/HouseSelectionView.h"
#include "Cursor.h"

class InputHandler {
public:
	// 
	InputHandler();
	
	// Liberación recursos de la instancia
	virtual ~InputHandler();

	// Handler de eventos de teclado/mouse
	// Retorna false si el evento es SDL_QUIT
	virtual bool handleInput() = 0;

	virtual void update();

protected:
	Cursor cursor;
};

#endif	// __INPUT_HANDLER_H__
