#ifndef __HOUSE_SELECTION_H__
#define __HOUSE_SELECTION_H__

#include <View/HouseSelectionView.h>
#include <Controller/HouseSelectionHandler.h>
#include <string>
#include "WindowMenu.h"

class HouseSelection : public WindowMenu {
public:
	HouseSelection();

	~HouseSelection();

	void run() override;

	std::string getSelectedHouse() const;

private:
	std::string selectedHouse;
	HouseSelectionView view;
	HouseSelectionHandler handler;
};

#endif	// __HOUSE_SELECTION_H__
