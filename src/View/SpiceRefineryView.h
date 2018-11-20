#ifndef __SPICE_REFINERY_VIEW_H__
#define __SPICE_REFINERY_VIEW_H__


#include "BuildingView.h"
#include "../Model/Buildings/SpiceRefinery.h"
#include "Area.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>

class SpiceRefineryView: public BuildingView {
public:
	SpiceRefineryView(SpiceRefinery& spiceRefinery, SdlWindow& window);
	virtual void draw(Area& camara);
private:
	static std::map<std::string, std::vector<std::unique_ptr<SdlTexture> > > sprites;
	std::vector<std::unique_ptr<SdlTexture> >::iterator anim_it;
};

#endif	// __SPICE_REFINERY_VIEW_H__
