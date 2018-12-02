#ifndef __HOUSE_SELECTION_H__
#define __HOUSE_SELECTION_H__

#include <View/HouseSelectionView.h>
#include <Controller/HouseSelectionHandler.h>
#include <string>

class HouseSelection {
public:
	HouseSelection(HouseSelectionView& view, HouseSelectionHandler& handler);
	
	~HouseSelection();

	std::string run();

private:
	bool wasHouseSelected;
	HouseSelectionView& view;
	HouseSelectionHandler& handler;
};

#endif	// __HOUSE_SELECTION_H__