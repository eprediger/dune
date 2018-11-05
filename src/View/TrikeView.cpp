#include "TrikeView.h"
#include <map>
#include "SdlTexture.h"
#include "../Unit/Trike.h"
#include "../Position.h"
#include "UnitView.h"
#include "Orientation.h"
#include <vector>

std::map<int,SdlTexture*> TrikeView::trike_sprites;
std::map<int,std::vector<SdlTexture*> > TrikeView:: attack_sprites;

TrikeView::TrikeView(Trike& trike, SdlWindow& window)
	:UnitView(trike,window)
	,trike(trike)
	,attacking(false)
	,anim_it()
	,update_sprite(0)
{
    if (trike_sprites.empty()){  
        trike_sprites.emplace(std::make_pair(Orientation::indefinida(),new SdlTexture("../imgs/imgs/0009e9ca.bmp",window)));		
		trike_sprites.emplace(std::make_pair(Orientation::norte(),new SdlTexture("../imgs/imgs/0009e6d8.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::noroeste(),new SdlTexture("../imgs/imgs/0009eb8b.bmp",window)));	
		trike_sprites.emplace(std::make_pair(Orientation::oeste(),new SdlTexture("../imgs/imgs/0009f4f4.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::sudoeste(),new SdlTexture("../imgs/imgs/0009fe42.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::sur(),new SdlTexture("../imgs/imgs/000a038f.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::sudeste(),new SdlTexture("../imgs/imgs/00128cdd.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::este(),new SdlTexture("../imgs/imgs/000a1090.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::noreste(),new SdlTexture("../imgs/imgs/0012a366.bmp",window)));
    
		std::vector<SdlTexture*> norte;
		norte.emplace_back(new SdlTexture("../imgs/imgs/trike-n1.bmp",window));
		norte.emplace_back(new SdlTexture("../imgs/imgs/trike-n2.bmp",window));
		attack_sprites.emplace(std::make_pair(Orientation::norte(),
									std::move(norte)));

		std::vector<SdlTexture*> noroeste;
		noroeste.emplace_back(new SdlTexture("../imgs/imgs/trike-nw1.bmp",window));
		noroeste.emplace_back(new SdlTexture("../imgs/imgs/trike-nw2.bmp",window));
		attack_sprites.emplace(std::make_pair(Orientation::noroeste(),
									std::move(noroeste)));
		
		std::vector<SdlTexture*> oeste;
		oeste.emplace_back(new SdlTexture("../imgs/imgs/trike-w1.bmp",window));
		oeste.emplace_back(new SdlTexture("../imgs/imgs/trike-w2.bmp",window));
		attack_sprites.emplace(std::make_pair(Orientation::oeste(),
									std::move(oeste)));

		std::vector<SdlTexture*> sudoeste;
		sudoeste.emplace_back(new SdlTexture("../imgs/imgs/trike-sw1.bmp",window));
		sudoeste.emplace_back(new SdlTexture("../imgs/imgs/trike-sw2.bmp",window));
		attack_sprites.emplace(std::make_pair(Orientation::sudoeste(),
									std::move(sudoeste)));

		std::vector<SdlTexture*> sur;
		sur.emplace_back(new SdlTexture("../imgs/imgs/trike-s1.bmp",window));
		sur.emplace_back(new SdlTexture("../imgs/imgs/trike-s2.bmp",window));
		attack_sprites.emplace(std::make_pair(Orientation::sur(),
									std::move(sur)));
		
		std::vector<SdlTexture*> sudeste;
		sudeste.emplace_back(new SdlTexture("../imgs/imgs/trike-se1.bmp",window));
		sudeste.emplace_back(new SdlTexture("../imgs/imgs/trike-se2.bmp",window));
		attack_sprites.emplace(std::make_pair(Orientation::sudeste(),
									std::move(sudeste)));
		
		std::vector<SdlTexture*> este;
		este.emplace_back(new SdlTexture("../imgs/imgs/trike-e1.bmp",window));
		este.emplace_back(new SdlTexture("../imgs/imgs/trike-e2.bmp",window));
		attack_sprites.emplace(std::make_pair(Orientation::este(),
									std::move(este)));

		std::vector<SdlTexture*> noreste;
		noreste.emplace_back(new SdlTexture("../imgs/imgs/trike-ne1.bmp",window));
		noreste.emplace_back(new SdlTexture("../imgs/imgs/trike-ne2.bmp",window));
		
		attack_sprites.emplace(std::make_pair(Orientation::noreste(),
									std::move(noreste)));
	
	}  
}  

 

void TrikeView::comenzar_ataque(){
    anim_it = attack_sprites.at(orientation.getValor()).begin();
}
 
void TrikeView::draw(Area& camara){ 
    Position pos = unit.getPosition();
	Area dest(pos.getX()- 13 - camara.getX(),pos.getY()-13 - camara.getY() ,25,25);
	orientation.calcular(prev_pos,pos);

    if (trike.attacking && !attacking){
        update_sprite = 0;
        attacking = true;
        comenzar_ataque();
    } 
    while (attacking){
        (*anim_it)->render(Area(0,0,30,30),dest);
        if (update_sprite == 10){
            anim_it++;
            update_sprite = 0;
        }
        update_sprite+=1;
        if (anim_it == attack_sprites.at(orientation.getValor()).end()){
            trike.attacking = false;
            attacking = false;
        }
        return;
    }
    prev_pos = pos;
    trike_sprites.at(orientation.getValor())->render(Area(0,0,30,30),dest);
}