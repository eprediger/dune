#ifndef __TRIKE_VIEW_H__
#define __TRIKE_VIEW_H__

#include "Model/Unit/Trike.h"
#include "Position.h"
#include "Orientation.h"
#include "OffensiveUnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <map>
#include <vector>

class TrikeView: public OffensiveUnitView {
public:
    TrikeView(Trike& trike, SdlWindow& window);
    
    virtual void draw(Area& camara);
    
    virtual std::vector<std::unique_ptr<SdlTexture> >& getDeadSprites();
    
    virtual Area getDeadUnitSrcArea();
    
    virtual Area getDeadUnitDestArea();

private:
    static std::map<int, std::unique_ptr<SdlTexture>> trike_sprites;
    static std::map<int, std::vector<std::unique_ptr<SdlTexture> > > attack_sprites;
    static std::vector<std::unique_ptr<SdlTexture> > dead_sprites;
};

#endif  // __TRIKE_VIEW_H__
