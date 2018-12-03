#include "MainMenuView.h"
#include <string>

MainMenuView::MainMenuView(const int width, const int height) :
	View(width, height),
	backgroundImage("../assets/img/bkgr/dune2000_1.jpg", this->window),
	backgroundMusic(Mix_LoadMUS("../assets/sound/music/options.mp3")),
	titleImage("../assets/img/bkgr/d2klogo.png", this->window),
	tags(),
	playButton(nullptr),
	selectedTextBox(nullptr),
	textBoxIndex(0) {
	Sound::getSound()->playMusic(backgroundMusic);
	this->tags.push_back(std::unique_ptr<Text>(new Text("Nickname  :", TXT_FONT_SIZE, this->window)));
	this->tags.push_back(std::unique_ptr<Text>(new Text("Servidor  :", TXT_FONT_SIZE, this->window)));
	this->tags.push_back(std::unique_ptr<Text>(new Text("Puerto    :", TXT_FONT_SIZE, this->window)));
	this->tags.push_back(std::unique_ptr<Text>(new Text("Ancho     :", TXT_FONT_SIZE, this->window)));
	this->tags.push_back(std::unique_ptr<Text>(new Text("Alto      :", TXT_FONT_SIZE, this->window)));

	this->inputBoxes.push_back(std::unique_ptr<TextBox>(new TextBox("guest", BOX_FONT_SIZE, this->window)));
	this->inputBoxes.push_back(std::unique_ptr<TextBox>(new TextBox("localhost", BOX_FONT_SIZE, this->window)));
	this->inputBoxes.push_back(std::unique_ptr<TextBox>(new TextBox("8080", BOX_FONT_SIZE, this->window)));
	this->inputBoxes.push_back(std::unique_ptr<TextBox>(new TextBox("1366", BOX_FONT_SIZE, this->window)));
	this->inputBoxes.push_back(std::unique_ptr<TextBox>(new TextBox("768", BOX_FONT_SIZE, this->window)));

	this->playButton.reset(new Text("Jugar", BTN_FONT_SIZE, this->window));
	this->selectedTextBox = this->inputBoxes[textBoxIndex].get();
}
#include <iostream>
MainMenuView::~MainMenuView() {
	if (Sound::getSound()->getCurrentMusic() == backgroundMusic){
		Sound::getSound()->stopMusic();
	}
	Mix_FreeMusic(backgroundMusic);
	if (this->selectedTextBox != nullptr) {
		this->selectedTextBox = nullptr;
	}
}

bool MainMenuView::setFocusOn(const unsigned x, const unsigned y) {
	bool textBoxFocus = false;
	bool playButtonFocus = false;

	for (unsigned i = 0; i < this->inputBoxes.size(); i++) {
		unsigned textBox_x = (this->window.width / 2);
		unsigned textBox_width = textBox_x + this->inputBoxes[i]->textWidth;
		unsigned textBox_y = ((this->window.height - (this->inputBoxes.size() * this->inputBoxes[i]->textHeight)) / 2) + (i * this->inputBoxes[i]->textHeight);
		unsigned textBox_height = textBox_y + this->inputBoxes[i]->textHeight;

		if (((x >= textBox_x) && (x <= textBox_width)) && ((y >= textBox_y) && (y <= textBox_height))) {
			this->selectedTextBox = this->inputBoxes[i].get();
			textBoxFocus = true;
		}
	}

	if (!textBoxFocus) {
		unsigned button_x = (this->window.width - this->playButton->textWidth) * 2 / 3;
		unsigned button_width = button_x + this->playButton->textWidth;
		unsigned button_y = (this->window.height * 2 / 3);
		unsigned button_height = button_y + this->playButton->textHeight;
		if (((x >= button_x) && (x <= button_width)) && ((y >= button_y) && (y <= button_height))) {
			playButtonFocus = true;
		}
	}

	return !playButtonFocus;
}

void MainMenuView::selectNextTextBox() {
	this->textBoxIndex++;
	unsigned index = this->textBoxIndex % this->inputBoxes.size();
	selectedTextBox = this->inputBoxes[index].get();
}

void MainMenuView::deleteFromTextBox() {
	if (this->selectedTextBox != nullptr) {
		this->selectedTextBox->deleteText();
	}
}

void MainMenuView::insertTextToTextBox(const char* text) {
	if (this->selectedTextBox != nullptr) {
		this->selectedTextBox->insert(text);
	}
}

std::string MainMenuView::getPlayerName() const {
	return this->inputBoxes[0]->getText();
}

std::string MainMenuView::getHost() const {
	return this->inputBoxes[1]->getText();
}

std::string MainMenuView::getPort() const {
	return this->inputBoxes[2]->getText();
}

std::string MainMenuView::getWindowWidth() const {
	return this->inputBoxes[3]->getText();
}

std::string MainMenuView::getWindowHeight() const {
	return this->inputBoxes[4]->getText();
}

void MainMenuView::render() {
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

	for (unsigned i = 0; i < this->tags.size(); i++) {
		this->tags[i]->render((this->window.width / 4), ((this->window.height -
		                   (this->tags.size() * this->tags[i]->textHeight)) / 2)
		                    + (i * this->tags[i]->textHeight));
	}

	for (unsigned i = 0; i < this->inputBoxes.size(); i++) {
		this->inputBoxes[i]->render((this->window.width / 2),
			((this->window.height -
			(this->inputBoxes.size() * this->inputBoxes[i]->textHeight)) / 2)
			 + (i * this->inputBoxes[i]->textHeight));
	}

	this->playButton->render((this->window.width - this->playButton->textWidth) * 2 / 3,
	                         (this->window.height * 2 / 3));

	this->window.render();
}
