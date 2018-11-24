#ifndef __HOUSE_SELECTION_HANDLER_H__
#define __HOUSE_SELECTION_HANDLER_H__

#include "InputHandler.h"
#include "View/HouseSelectionView.h"

class HouseSelectionHandler : public InputHandler {
public:
	// Handler para la vista de selección de casa
	explicit HouseSelectionHandler(HouseSelectionView& view);

	// Libera recursos asociados a la instancia
	~HouseSelectionHandler();

	bool handleInput() override;

private:
	HouseSelectionView& view;
};

#endif	// __HOUSE_SELECTION_HANDLER_H__
