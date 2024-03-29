#include "BarracksView.h"
#include "BuildingView.h"
#include "Model/Buildings/Barracks.h"
#include <Area.h>
#include "Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string> 
#include <memory>
#include <Path.h>

std::map<std::string, std::vector< std::unique_ptr<SdlTexture> > > BarracksView::sprites;

BarracksView::BarracksView(Barracks& barracks, SdlWindow& window)
    :BuildingView(barracks,window,Area(0,0,72,68),Area(0,0,72,68))
{
    if (sprites.empty()){
        std::vector < std::unique_ptr<SdlTexture> > vector;
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001512c3.bmp"),window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00152601.bmp"),window)));
        sprites.emplace(std::make_pair("Atreides",std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0019be4d.bmp"),window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0019cf5f.bmp"),window)));
        sprites.emplace(std::make_pair("Harkonnen",std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001e6511.bmp"),window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001e7669.bmp"),window)));
        sprites.emplace(std::make_pair("Ordos",std::move(vector)));
        }
    anim_it = sprites.at(building.getPlayer()->getHouse()).begin();
} 
 
void BarracksView::draw(Area& camara){
    if ((!destroyed) && building.getLife()<=0){
        destroyed = true;
    }
    BuildingView::draw(camara,*anim_it);    
}
