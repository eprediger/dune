#include "DeadUnitView.h"
#include <vector>
#include "../Position.h"
#include "Area.h"


DeadUnitView::DeadUnitView(Position pos, Area area
                            ,std::vector<SdlTexture*>& sprites)
    :dead_sprites(sprites)
    ,anim_it()
    ,update(0){} 