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
	virtual std::vector<SdlTexture*>& getDeadSprites();
	virtual Area getDeadUnitSrcArea();
	virtual Area getDeadUnitDestArea();
		
private:
	static std::map<int, SdlTexture*> harvester_sprites;
	static std::vector<SdlTexture*> dead_sprites;
};

#endif	// __HARVESTER_VIEW_H__
