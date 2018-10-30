#include "View.h"

View::View(SdlWindow &window, Area &camera) : window(window) ,camera(camera){

}

void View::addUnityView(Unity &unity) {
    unity_views.push_back(std::unique_ptr<VistaUnidad>( new VistaUnidad(unity, window)));
}

void View::draw() {
//    for (auto unity_view : unity_views){
    for (auto itr = unity_views.begin(); itr != unity_views.end(); ++itr){
        (*itr)->dibujar(camera);
    }
}


