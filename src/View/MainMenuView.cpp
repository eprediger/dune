#include "MainMenuView.h"
#include <iostream>	// print server y puerto

MainMenuView::MainMenuView(const int width, const int height) :
	View(width, height),
	backgroundImage("../assets/img/bkgr/dune2000_1.jpg", this->window),
	backgroundMusic("../assets/sound/music/options.mp3"),
	// title("Dune 2000", TITLE_FONT_SIZE, this->window),
	titleImage("../assets/img/bkgr/d2klogo.png", this->window),
	tags(),
	playButton(nullptr),
	selectedTextBox(nullptr),
	textBoxIndex(0) {
	this->backgroundMusic.start();

	this->tags.push_back(std::unique_ptr<Text>(new Text("Servidor  :", TAG_FONT_SIZE, this->window)));
	this->tags.push_back(std::unique_ptr<Text>(new Text("Puerto    :", TAG_FONT_SIZE, this->window)));

	this->inputBoxes.push_back(std::unique_ptr<TextBox>(new TextBox("localhost", BOX_FONT_SIZE, this->window)));
	this->inputBoxes.push_back(std::unique_ptr<TextBox>(new TextBox("10001", BOX_FONT_SIZE, this->window)));

	this->playButton.reset(new Text("Jugar", BTN_FONT_SIZE, this->window));
	this->selectedTextBox = this->inputBoxes[textBoxIndex].get();
}

MainMenuView::~MainMenuView() {
	backgroundMusic.stop();
	backgroundMusic.join();
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
			this->getTextBoxContent();
			playButtonFocus = true;
		}
	}

	return !playButtonFocus;
}

void MainMenuView::selectNextTextBox() {
	this->textBoxIndex++;
	selectedTextBox = this->inputBoxes[this->textBoxIndex % this->inputBoxes.size()].get();
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

void MainMenuView::getTextBoxContent() {
	for (unsigned i = 0; i < this->inputBoxes.size(); i++) {
		std::cout << this->inputBoxes[i]->getText() << std::endl;
	}
}

void MainMenuView::render() {
	Area bkgrImgSrc(0, 0, this->backgroundImage.width, this->backgroundImage.height);
	Area bkgrImgDest(0, 0, this->window.width, this->window.height);
	this->backgroundImage.render(bkgrImgSrc, bkgrImgDest);

	/*this->title.render((this->window.width - this->title.textWidth) / 2,
	                   this->window.height / 10);*/

	Area titleAreaSrc(0, 0, this->titleImage.width, this->titleImage.height);
	Area titleAreaDest(((this->window.width - (this->titleImage.width / 2)) / 2),
	                   this->window.height / 10,
	                   this->titleImage.width / 2,
	                   this->titleImage.height / 2);
	this->titleImage.render(titleAreaSrc, titleAreaDest);

	for (unsigned i = 0; i < this->tags.size(); i++) {
		/*Area tagArea((this->window.width / 4),
		             ((this->window.height - (this->tags.size() * this->tags[i]->textHeight)) / 2) + (i * this->tags[i]->textHeight),
		             this->tags[i]->textWidth,
		             this->tags[i]->textHeight);*/
		this->tags[i]->render((this->window.width / 4),
		                      ((this->window.height - (this->tags.size() * this->tags[i]->textHeight)) / 2) + (i * this->tags[i]->textHeight));
	}

	for (unsigned i = 0; i < this->inputBoxes.size(); i++) {
		this->inputBoxes[i]->render((this->window.width / 2), ((this->window.height - (this->inputBoxes.size() * this->inputBoxes[i]->textHeight)) / 2) + (i * this->inputBoxes[i]->textHeight));
	}

	/*Area buttonArea((this->window.width - this->playButton->textWidth) * 2 / 3,
	                (this->window.height * 2 / 3),
	                this->playButton->textWidth,
	                this->playButton->textHeight);*/
	this->playButton->render((this->window.width - this->playButton->textWidth) * 2 / 3,
	                         (this->window.height * 2 / 3));
	this->window.render();
}
