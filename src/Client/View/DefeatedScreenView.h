#ifndef __DEFEATED_SCREEN_VIEW_H__
#define __DEFEATED_SCREEN_VIEW_H__


#include <View/View.h>

#define TXT_FONT_SIZE 	28
#define BOX_FONT_SIZE 	24
#define BTN_FONT_SIZE	36

class DefeatedScreenView : public View {
public:
    DefeatedScreenView(const int width, const int height);
    ~DefeatedScreenView();

    virtual void render() override;
private:
    SdlTexture backgroundImage;
    SdlTexture titleImage;
    Text defeated_tag;
    Text thanks_tag;
    Text author_tag;
};


#endif //__DEFEATED_SCREEN_VIEW_H__
