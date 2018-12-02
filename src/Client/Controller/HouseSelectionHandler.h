#ifndef __HOUSE_SELECTION_HANDLER_H__
#define __HOUSE_SELECTION_HANDLER_H__

#include <Controller/InputHandler.h>
#include <View/HouseSelectionView.h>
#include <string>

class HouseSelectionHandler : public InputHandler {
public:
	// Handler para la vista de selección de casa
	explicit HouseSelectionHandler(HouseSelectionView& view);

	// Libera recursos asociados a la instancia
	virtual ~HouseSelectionHandler();

	// Controla el input del usuario.
	// Retorna false frente al evento de cierre
	bool handleInput() override;

	// Retorna la casa elegida por el usuario
	std::string getSelectedHouse() const;

private:
	HouseSelectionView& view;
	std::string selectedHouse;
};

#endif	// __HOUSE_SELECTION_HANDLER_H__
