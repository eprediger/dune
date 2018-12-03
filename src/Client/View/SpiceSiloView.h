#ifndef __SPICE_SILO_VIEW_H__
#define __SPICE_SILO_VIEW_H__

#include "BuildingView.h"
#include "Model/Buildings/SpiceSilo.h"
#include <Area.h>
#include "Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>

class SpiceSiloView: public BuildingView {
public:
	SpiceSiloView(SpiceSilo& spiceSilo, SdlWindow& window);
	virtual void draw(Area& camara);
private:
	static std::map<std::string, std::vector<std::unique_ptr<SdlTexture>>> sprites;
	std::vector<std::unique_ptr<SdlTexture> >::iterator anim_it;
	std::unique_ptr<SdlTexture> base;
};

#endif	// __SPICE_SILO_VIEW_H__
