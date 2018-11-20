#ifndef __HARVESTER_VIEW_H__
#define __HARVESTER_VIEW_H__

#include "../Model/Unit/Harvester.h"
#include "UnitView.h"
#include <map>
#include <vector>

class HarvesterView: public UnitView {
public:
	HarvesterView(Harvester& harvester, SdlWindow& window);
	virtual void draw(Area& camara);
	virtual std::vector<std::unique_ptr<SdlTexture> >& getDeadSprites();
	virtual Area getDeadUnitSrcArea();
	virtual Area getDeadUnitDestArea();
		
private:
	static std::map<int, std::unique_ptr<SdlTexture>> harvester_sprites;
	static std::vector<std::unique_ptr<SdlTexture> > dead_sprites;
};

#endif	// __HARVESTER_VIEW_H__
