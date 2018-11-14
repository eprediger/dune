#include "OffensiveUnitView.h"

OffensiveUnitView::OffensiveUnitView(OffensiveUnit& unit, Area sprite_area)
    :UnitView(unit,sprite_area)
    ,offensiveUnit(unit)
    ,anim_it()
    ,update(0)
    ,animating_attack(false){}

 
void OffensiveUnitView::drawAttack(Area& camara, std::map<int, std::vector<SdlTexture*> >& sprites){
	Orientation prev_orient = orientation;
    orientation.calcular(prev_pos,offensiveUnit.getVictimPosition());
    prev_pos = offensiveUnit.getPosition();
    if (!(orientation == prev_orient) || (!animating_attack)){
        animating_attack = true;
        anim_it = sprites.at(orientation.getValor()).begin();
        update = 0;
    }  
    dest_area.setX(prev_pos.x - camara.getX() - sprite_area.getWidth()/2);
    dest_area.setY(prev_pos.y - camara.getY() - sprite_area.getHeight()/2);
    (*anim_it)->render(sprite_area,dest_area);
    update++;
    if (update == 10){
        anim_it++;
        update = 0;
        if (anim_it == sprites.at(orientation.getValor()).end()){
            animating_attack = false;
        }
    }
}
