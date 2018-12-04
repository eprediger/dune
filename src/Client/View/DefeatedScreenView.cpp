#include <Path.h>
#include "DefeatedScreenView.h"

DefeatedScreenView::DefeatedScreenView(const int width, const int height) :
        View(width, height),
        backgroundImage(Path::rootVar("assets/img/bkgr/dune2000_1.jpg"), this->window),
        titleImage(Path::rootVar("assets/img/bkgr/d2klogo.png"), this->window),
        defeated_tag("You've been defeated!", TITLE_FONT_SIZE, this->window),
        thanks_tag("Thank You for playing!", TXT_FONT_SIZE, this->window),
        author_tag("Authors: Grupo 2 [Perez Ondarts Flavio - Poggio Demian - Prediger Emiliano]", TXT_FONT_SIZE, this->window)
{}

DefeatedScreenView::~DefeatedScreenView() {}

void DefeatedScreenView::render() {
    Area bkgrImgSrc(0, 0, this->backgroundImage.width,
                    this->backgroundImage.height);
    Area bkgrImgDest(0, 0, this->window.width, this->window.height);
    this->backgroundImage.render(bkgrImgSrc, bkgrImgDest);

    Area titleAreaSrc(0, 0, this->titleImage.width, this->titleImage.height);
    Area titleAreaDst(((this->window.width - (this->titleImage.width / 2)) / 2),
                      this->window.height / 10,
                      this->titleImage.width / 2,
                      this->titleImage.height / 2);
    this->titleImage.render(titleAreaSrc, titleAreaDst);

    this->defeated_tag.render((this->window.width / 4), (this->window.height - this->defeated_tag.textHeight) / 4 + defeated_tag.textHeight);
    this->thanks_tag.render((this->window.width / 4), (this->window.height - this->thanks_tag.textHeight) / 2 + thanks_tag.textHeight);
    this->author_tag.render((this->window.width - this->author_tag.textWidth) / 2, (this->window.height - this->author_tag.textHeight) * 8 / 10 + author_tag.textHeight);

    this->window.render();
}


