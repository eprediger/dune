#include "HouseSelectionView.h"
#include <memory>
#include <string>
#include <Path.h>

HouseSelectionView::HouseSelectionView(const int width, const int height) :
	View(width, height),
	backgroundImage(Path::rootVar("assets/img/bkgr/dune2000_4.jpg"), this->window),
	backgroundMusic(Mix_LoadMUS(Path::rootVar("assets/sound/music/plotting.mp3").c_str())),
	title("ELIGE TU CASA", TITLE_FONT_SIZE / 2, this->window),
	houses(),
	houseNames(),
	selectedHouse(nullptr) {
	this->houses.push_back(std::unique_ptr<SdlTexture>(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/houses/atreides.png"), this->window))));
	this->houses.push_back(std::unique_ptr<SdlTexture>(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/houses/harkonnen.png"), this->window))));
	this->houses.push_back(std::unique_ptr<SdlTexture>(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/houses/ordos.png"), this->window))));
	this->houseNames.push_back(std::unique_ptr<Text>(new Text("Atreides", HOUSE_FONT_SIZE, this->window)));
	this->houseNames.push_back(std::unique_ptr<Text>(new Text("Harkonnen", HOUSE_FONT_SIZE, this->window)));
	this->houseNames.push_back(std::unique_ptr<Text>(new Text("Ordos", HOUSE_FONT_SIZE, this->window)));
	Sound::getSound()->playMusic(backgroundMusic);
}

HouseSelectionView::~HouseSelectionView() {
	if (Sound::getSound()->getCurrentMusic() == backgroundMusic){
		Sound::getSound()->stopMusic();
	}
	Mix_FreeMusic(backgroundMusic);
}

bool HouseSelectionView::setFocusOn(const int x, const int y) {
	bool houseSelected = false;
	for (unsigned i = 0; i < this->houses.size(); i++) {
		unsigned finalWidth = this->houses[i]->width / 2;
		unsigned finalHeight = this->houses[i]->height / 2;
		int houseBox_x = (((this->window.width / 4) * (i + 1)) - (finalWidth / 2));
		int houseBox_width = houseBox_x + finalWidth;
		int houseBox_y = (this->window.height - finalHeight) / 2;
		int houseBox_height = houseBox_y + finalHeight;

		if (((x >= houseBox_x) && (x <= houseBox_width)) && ((y >= houseBox_y) && (y <= houseBox_height))) {
			this->selectedHouse = this->houseNames[i].get();
			houseSelected = true;
		}
	}
	return houseSelected;
}

std::string HouseSelectionView::getHouse() const {
	return this->selectedHouse->getText();
}

void HouseSelectionView::render() {
	Area src(0, 0, backgroundImage.width, backgroundImage.height);
	Area dest(0, 0, window.width, window.height);
	this->backgroundImage.render(src, dest);

	this->title.render((this->window.width - this->title.textWidth) / 2,
	                   this->window.height / 10);

	for (unsigned i = 0; i < this->houses.size(); i++) {
		Area houseSrc(0, 0, this->houses[i]->width, this->houses[i]->height);
		unsigned finalWidth = this->houses[i]->width * 2 / 5;
		unsigned finalHeight = this->houses[i]->height * 2 / 5;
		Area houseDest((((this->window.width / 4) * (i + 1)) - (finalWidth / 2)),
		               (this->window.height - finalHeight) / 2,
		               (finalWidth),
		               (finalHeight));
		this->houses[i]->render(houseSrc, houseDest);
	}

	for (unsigned i = 0; i < this->houseNames.size(); i++) {
		this->houseNames[i]->render(((this->window.width / 4) * (i + 1)) - (this->houseNames[i]->textWidth / 2),
		                            (this->window.height - this->houseNames[i]->textHeight) * 4 / 5);
	}

	this->window.render();
}
