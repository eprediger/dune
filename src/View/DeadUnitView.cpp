#include "DeadUnitView.h"
#include <vector>
#include "../Position.h"
#include "Area.h"


DeadUnitView::DeadUnitView(Position pos, Area area
                            ,std::vector<SdlTexture*>& sprites)
    :dead_sprites(sprites)
    ,anim_it()
    ,src_area(area)
    ,pos(pos)
    ,dest_area(0,0,area.getWidth(),area.getHeight())
    ,update(0)
    {}

bool DeadUnitView::finished(){
    return (anim_it == dead_sprites.end());
}

void DeadUnitView::draw(Area& camara){
    (*anim_it)->render(src_area,dest_area);
    update++;
    if (update==4){
        anim_it++;
        update = 0;
    }
    dest_area.setX(pos.x - camara.getX() - camara.getWidth()/2);
    dest_area.setY(pos.y - camara.getY() - camara.getHeight()/2);
    (*anim_it)->render(src_area,dest_area);
}
