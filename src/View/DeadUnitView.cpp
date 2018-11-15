#include "DeadUnitView.h"
#include <vector>
#include "../Position.h"
#include "Area.h"


DeadUnitView::DeadUnitView(Position pos, Area area
                            ,std::vector<SdlTexture*>& sprites
                            ,int r, int g, int b, SdlWindow& window)
    :dead_sprites(sprites)
    ,anim_it(sprites.begin())
    ,src_area(area)
    ,pos(pos)
    ,dest_area(0,0,area.getWidth()/3,area.getHeight()/3)
    ,update(0)
    ,player_r(r)
    ,player_g(g)
    ,player_b(b)
    ,window(window)
    {}

bool DeadUnitView::finished(){
    return (anim_it == dead_sprites.end());
}

#include <iostream>
void DeadUnitView::draw(Area& camara){
    std::cout<<"in\n";
    dest_area.setX(pos.x - camara.getX() - dest_area.getWidth()/2);
    dest_area.setY(pos.y - camara.getY() - dest_area.getHeight()/2);
    (*anim_it)->render(src_area,dest_area);
    update++;
    if (update==8){
        anim_it++;
        update = 0;
    }
    std::cout<<"out\n";
}
