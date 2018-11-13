#ifndef __RAIDER_VIEW_H__
#define __RAIDER_VIEW_H__

#include "UnitView.h"
#include "../Model/Unit/Raider.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Area.h"
#include "../Position.h"
#include "Orientation.h"
#include <map>

class RaiderView: public UnitView {
public:
    RaiderView(Raider& raider, SdlWindow& window);
    virtual void draw(Area& area);
private:
    static std::map<int, SdlTexture*> raider_sprites;
    void comenzar_ataque();
    Raider& raider;
    static std::map<int, std::vector<SdlTexture*> > attack_sprites;
    bool attacking;
    std::vector<SdlTexture*>::iterator anim_it;
    int update_sprite;
};

#endif  // __RAIDER_VIEW_H__
