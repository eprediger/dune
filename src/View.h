#ifndef __VIEW_H__
#define __VIEW_H__

#include "SdlWindow.h"
#include "VistaMap.h"
#include "VistaUnidad.h"
#include <memory>

class View {
private:
    std::vector<std::unique_ptr<VistaUnidad>> unity_views;
//    std::vector<VistaMap> map_view;
    SdlWindow& window;
    Area& camera;

public:
    View(SdlWindow &window, Area &camera);

    void addUnityView(Unity& unity);

    void draw();
};
#endif //__VIEW_H__
