#include "GameView.h"
#include "View.h"
#include "../Model/Model.h"
#include "BuildingView.h"
#include <algorithm>
#include <string>
#include <vector>

GameView::GameView(const int width, const int height, Model& model) :
	View(width / 2, height / 2),
	model(model),
	unitViews(),
	deadUnitViews(),
	buildingViews(),
	selectorView(nullptr),
	map_view(model.getMap(), window),
	camera(0, 0, width / 2, height / 2),
	backgroundMusic("../assets/sound/music/fight-for-power.mp3"),
	moneyTag(Text("DINERO", TAG_FONT_SIZE, this->window)),
	moneyBalance(Text(std::to_string(model.getPlayer(0).gold), TAG_FONT_SIZE, this->window)),
	buildingTag(Text("EDIFICIOS", TAG_FONT_SIZE, this->window)),
	unitsTag(Text("UNIDADES", TAG_FONT_SIZE, this->window)),
	buildingButtons(),
	unitButtons(),
	buttons("../assets/img/btns/cantSell.png", this->window),
	map_width(width),
	map_height(height),
	camera_width(width / 2),
	camera_height(height / 2) {
//	backgroundMusic.start();
}

GameView::~GameView() {
//	backgroundMusic.stop();
	while (!this->buildingButtons.empty()) {
		delete this->buildingButtons.back();
		this->buildingButtons.pop_back();
	}
	while (!this->unitButtons.empty()) {
		delete this->unitButtons.back();
		this->unitButtons.pop_back();
	}
	for (auto unit_view : unitViews) {
		delete unit_view;
	}
	for (auto deadUnitView : deadUnitViews) {
		delete deadUnitView;
	}
	for (auto building_view : buildingViews) {
		delete building_view;
	}
//	backgroundMusic.join();
}

void GameView::addUnitView(UnitView* unitView) {
	unitViews.push_back(std::move(unitView));
}

void GameView::addBuildingView(BuildingView* buildingView) {
	buildingViews.push_back(std::move(buildingView));
}

void GameView::addSelectorView(Selector& selector) {
	this->selectorView = new SelectorView(selector, window);
}

void GameView::cleanDeadUnitViews() {
	std::vector<UnitView*>::iterator it = unitViews.begin();
	while (it != unitViews.end()) {
		if (UnitView::isDead(*it)) {
			deadUnitViews.emplace_back((*it)->getDeadUnitView());
			delete (*it);
			it = unitViews.erase(it);
		} else {
			it++;
		}
	}

	std::vector<DeadUnitView*>::iterator dead_it = deadUnitViews.begin();
	while (dead_it != deadUnitViews.end()) {
		if ((*dead_it)->finished()) {
			delete (*dead_it);
			dead_it = deadUnitViews.erase(dead_it);
		} else {
			dead_it++;
		}
	}
}

SdlWindow &GameView::getWindow() {
	return window;
}

void GameView::render() {
	//    for (auto unit_view : unitViews){
	map_view.draw(camera);

	if (selectorView != nullptr) {
		selectorView->draw(camera);
	}

	for (auto itr = deadUnitViews.begin(); itr != deadUnitViews.end(); ++itr) {
		(*itr)->draw(camera);
	}

	for (auto itr = unitViews.begin(); itr != unitViews.end(); ++itr) {
		(*itr)->draw(camera);
	}

	for (auto itr = buildingViews.begin(); itr != buildingViews.end(); ++itr) {
		(*itr)->draw(camera);
	}

	if (selectorView != nullptr) {
		selectorView->draw(camera);
	}

	// Dinero
	this->moneyTag.render((this->window.width - this->moneyTag.textWidth) * 18 / 20, this->window.height * 9 / 32);
	this->moneyBalance.setText(std::to_string(model.getPlayer(0).gold));
	this->moneyBalance.render((this->window.width - this->moneyBalance.textWidth) * 18 / 20 + this->moneyTag.textWidth, this->window.height * 9 / 32);
	// Botones
	// Vender Edificio
//	this->buttons.render(this->window.width * 16 / 20, this->window.height * 9 / 32);

	// Botones de Edificios
	this->buildingTag.render(this->window.width * 16 / 20, this->window.height * 11 / 32);
	for (unsigned i = 0; i < this->buildingButtons.size(); ++i) {
//		Area buildingSrc(0, 0, this->buildingButtons[i]->width, this->buildingButtons[i]->height);
		Area buildingDest(this->window.width * 16 / 20,	//this->window.width * 1 / 128,
		                  (this->window.height * (BTN_INIT_HEIGHT) / 16) + (BTN_VERT_SPACE * i),	//this->window.height * (1 + 8 * i) / 64,
		                  BTN_WIDTH,
		                  BTN_HEIGHT);
		this->buildingButtons[i]->render(buildingDest);
	}

	// Botones de Unidades
	this->unitsTag.render(this->window.width * 18 / 20, this->window.height * 11 / 32);
	for (unsigned i = 0; i < this->unitButtons.size(); ++i) {
//		Area UnitSrc(0, 0, this->unitButtons[i]->width, this->unitButtons[i]->height);
		Area UnitButtonDest(this->window.width * 18 / 20,	// this->window.width * 29 / 32,
		                    (this->window.height * (BTN_INIT_HEIGHT) / 16) + (BTN_VERT_SPACE * i),	// this->window.height * (1 + 8 * i) / 64,
		                    BTN_WIDTH,
		                    BTN_HEIGHT);
		this->unitButtons[i]->render(UnitButtonDest);
	}

	// Barra de energia
	SDL_Color available = { 0x0, 0x80, 0x0, 0xFF };	// { 0xFF, 0x0, 0x0, 0xFF };
	SDL_Color bkgrColor = { 0xA9, 0xA9, 0xA9, 0xFF };	// { 0x0, 0xFF, 0x0, 0xFF };
	this->RenderVPBar(this->window.width * 63 / 80,	//this->window.width * 1 / 10,
	                  this->window.height * 6 / 16,	//this->window.height * 1 / 64,
	                  this->window.height * 32 / 64,
	                  (float)this->model.getPlayer(0).consumedEnergy / (float)this->model.getPlayer(0).generatedEnergy,
	                  available, bkgrColor);

	this->window.render();
}

void GameView::RenderVPBar(int x, int y, int h, float percent, SDL_Color FGColor, SDL_Color BGColor) {
	percent = percent > 1.f ? 1.f : percent < 0.f ? 0.f : percent;
	SDL_Color old;
	SDL_GetRenderDrawColor(this->window.getRenderer(), &old.r, &old.g, &old.g, &old.a);
	SDL_Rect bgrect = { x, y, ENERGY_BAR_WIDTH, h };
	SDL_SetRenderDrawColor(this->window.getRenderer(), BGColor.r, BGColor.g, BGColor.b, BGColor.a);
	SDL_RenderFillRect(this->window.getRenderer(), &bgrect);
	SDL_SetRenderDrawColor(this->window.getRenderer(), FGColor.r, FGColor.g, FGColor.b, FGColor.a);
	int ph = (int)((float)h * percent);
	int py = y + (h - ph);
	SDL_Rect fgrect = { x, py, ENERGY_BAR_WIDTH, ph };
	SDL_RenderFillRect(this->window.getRenderer(), &fgrect);
	SDL_SetRenderDrawColor(this->window.getRenderer(), old.r, old.g, old.b, old.a);
}

void GameView::moveUp(const int distance) {
	int new_y = camera.getY() - distance;
	camera.setY((new_y > 0) ? new_y : 0);
}

void GameView::moveDown(const int distance) {
	int new_y = camera.getY() + distance;
	camera.setY((new_y < (map_height - camera_height)) ? new_y : map_height - camera_height);
}

void GameView::moveLeft(const int distance) {
	int new_x = camera.getX() - distance;
	camera.setX((new_x > 0) ? new_x : 0);
}

void GameView::moveRight(const int distance) {
	int new_x = camera.getX() + distance;
	camera.setX((new_x < (map_width - camera_width)) ? new_x : map_width - camera_width);
}

int GameView::getCameraX() {
	return this->camera.getX();
}

int GameView::getCameraY() {
	return this->camera.getY();
}

void GameView::grabMouse() {
	this->window.grabMouse(true);
}

void GameView::releaseMouse() {
	this->window.grabMouse(false);
}

ButtonView& GameView::createUnitButton(const std::string &filename) {
	ButtonView* newButtonView = new ButtonView(filename, this->window);
	this->unitButtons.emplace_back(newButtonView);
	return *newButtonView;
}

ButtonView &GameView::createBuildingButton(const std::string &filename) {
	ButtonView* newButtonView = new ButtonView(filename, this->window);
	this->buildingButtons.emplace_back(newButtonView);
	return *newButtonView;
}
