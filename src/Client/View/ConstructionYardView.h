#ifndef __CONSTRUCTION_YARD_VIEW_H__
#define __CONSTRUCTION_YARD_VIEW_H__

#include "BuildingView.h"
#include "../../Common/Area.h"
#include "Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Model/Buildings/ConstructionYard.h"
#include <vector>
#include <map>
#include <string>

class ConstructionYardView: public BuildingView {
public:
	ConstructionYardView(ConstructionYard& constructionYard, SdlWindow& window);
	virtual void draw(Area& camara);
private:
	static std::map<std::string, std::vector<std::unique_ptr<SdlTexture> > > sprites;
	std::vector<std::unique_ptr<SdlTexture> >::iterator anim_it;
};

#endif	// __CONSTRUCTION_YARD_VIEW_H__
