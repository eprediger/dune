#ifndef __VICTORYSCREENVIEW_H__
#define __VICTORYSCREENVIEW_H__


#include <View/View.h>

#define TXT_FONT_SIZE 	28
#define BOX_FONT_SIZE 	24
#define BTN_FONT_SIZE	36

class VictoryScreenView : public View {
public:
    VictoryScreenView(const int width, const int height, std::string winner_player);
    ~VictoryScreenView();

    virtual void render() override;
private:
    SdlTexture backgroundImage;
    SdlTexture titleImage;
    Text winner_tag;
    Text thanks_tag;
    Text author_tag;
    std::string winner_player;
};


#endif //__VICTORYSCREENVIEW_H__
