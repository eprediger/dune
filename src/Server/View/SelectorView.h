#ifndef __SELECTOR_VIEW_H__
#define __SELECTOR_VIEW_H__

#include "Selector.h"
#include "SdlWindow.h"
#include "Area.h"

class SelectorView {
public:
	SelectorView(Selector& selector, SdlWindow& window);
	void draw(Area& camara);
	SdlWindow& window;
private:
	Selector& selector;
	void drawLife(Building* building, Area& camara);
	void drawLife(Unit* unit, Area& camara);
	void drawSelection(Area& camara);
	SDL_Rect drag_rect, max_life, current_life;
};

#endif  // __SELECTOR_VIEW_H__
