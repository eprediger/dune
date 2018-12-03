#include "GameView.h"
#include "View.h"
#include "Model/Model.h"
#include "BuildingView.h"
#include "RocketView.h"
#include "BuildingViewFactory.h"
#include "Controller/GameHandler.h"
#include <algorithm>
#include <string>
#include <vector>
#include <memory>

GameView::GameView(const int width, const int height,
                   Model& model, Player& player) :
	View(width, height),
	model(model),
	player(player),
	unitViews(),
	deadUnitViews(),
	buildingViews(),
	rocketViews(),
	selectorView(nullptr),
	playerView(player, window, 3 * width / 4, width / 4),
	constructorView(nullptr),
	map_view(model.getMap(), window),
	camera(0, 0, 3 * width / 4, height),
	backgroundMusic("../assets/sound/music/fight-for-power.mp3"),
	buildingTag(Text("EDIFICIOS", TAG_FONT_SIZE, this->window)),
	unitsTag(Text("UNIDADES", TAG_FONT_SIZE, this->window)),
	buildingButtons(),
	unitButtons(),
	buildingSellButton(nullptr),
	map_width(model.getMap().getWidth()),
	map_height(model.getMap().getHeight()),
	camera_width(camera.getWidth()),
	camera_height(camera.getHeight()) {
	backgroundMusic.start();
}

GameView::~GameView() {
	backgroundMusic.stop();
	while (!this->buildingButtons.empty()) {
		delete this->buildingButtons.back();
		this->buildingButtons.pop_back();
	}
	while (!this->unitButtons.empty()) {
		delete this->unitButtons.back();
		this->unitButtons.pop_back();
	}
	for (auto& unit_view : unitViews) {
		delete unit_view;
	}
	for (auto& deadUnitView : deadUnitViews) {
		delete deadUnitView;
	}
	for (auto& building_view : buildingViews) {
		delete building_view;
	}
	if (selectorView != nullptr) {
		delete this->selectorView;
		this->selectorView = nullptr;
	}
	if (buildingSellButton != nullptr) {
		delete this->buildingSellButton;
		this->buildingSellButton = nullptr;
	}
	if (constructorView != nullptr) {
		delete this->constructorView;
		this->constructorView = nullptr;
	}
	backgroundMusic.join();
}

void GameView::addUnitView(UnitView* unitView) {
	unitViews.push_back(std::move(unitView));
}

void GameView::addBuildingView(BuildingView* buildingView) {
	buildingViews.push_back(std::move(buildingView));
}

void GameView::addRocketView(RocketView* rocketView) {
	rocketViews.push_back(std::move(rocketView));
}

void GameView::addSelectorView(Selector& selector) {
	this->selectorView = new SelectorView(selector, window);
}

void GameView::addBuildingConstructorView(BuildingConstructor* constructor) {
	this->constructorView = new BuildingConstructorView(*constructor, window);
}

void GameView::cleanDeadViews() {
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

	std::vector<BuildingView*>::iterator it2 = buildingViews.begin();
	while (it2 != buildingViews.end()) {
		if (BuildingView::isDead(*it2)) {
			deadUnitViews.emplace_back((*it2)->getDeadBuildingView());
			delete (*it2);
			it2 = buildingViews.erase(it2);
		} else {
			it2++;
		}
	}

	std::vector<RocketView*>::iterator rocketView = rocketViews.begin();
	while (rocketView != rocketViews.end()) {
		if ((*rocketView)->finished) {
			delete (*rocketView);
			rocketView = rocketViews.erase(rocketView);
		} else {
			rocketView++;
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

std::vector<RocketView*>& GameView::getRocketViews() {
	return this->rocketViews;
}

SdlWindow &GameView::getWindow() {
	return window;
}

void GameView::render() {
	this->cleanDeadViews();
	map_view.draw(camera);

	if (constructorView != nullptr) {
		constructorView->draw(camera);
	}

	for (auto &deadUnitView : deadUnitViews) {
		deadUnitView->draw(camera);
	}

	for (auto &unitView : unitViews) {
		unitView->draw(camera);
	}

	for (auto &buildingView : buildingViews) {
		buildingView->draw(camera);
	}

	for (auto &rocketView : rocketViews) {
		rocketView->draw(camera);
	}

	if (selectorView != nullptr) {
		selectorView->draw(camera);
	}

	playerView.draw();

	// Botones
	// Vender Edificio
	Area sellBuildingDest(this->window.width * 16 / 20,
	                      this->window.height * 9 / 32,
	                      BTN_SELL_BUILDING,
	                      BTN_SELL_BUILDING);
	this->buildingSellButton->render(sellBuildingDest);

	// Botones de Edificios
	this->buildingTag.render(this->window.width * 16 / 20, this->window.height * 11 / 32);
	for (unsigned i = 0; i < this->buildingButtons.size(); ++i) {
		Area buildingDest(this->window.width * 16 / 20,
		                  (this->window.height * (BTN_INIT_HEIGHT) / 16) + (BTN_VERT_SPACE * i),
		                  BTN_WIDTH,
		                  BTN_HEIGHT);
		this->buildingButtons[i]->render(buildingDest);
	}

	// Botones de Unidades
	this->unitsTag.render(this->window.width * 18 / 20, this->window.height * 11 / 32);
	for (unsigned i = 0; i < this->unitButtons.size(); ++i) {
		Area UnitButtonDest(this->window.width * 18 / 20,
		                    (this->window.height * (BTN_INIT_HEIGHT) / 16) + (BTN_VERT_SPACE * i),
		                    BTN_WIDTH,
		                    BTN_HEIGHT);
		this->unitButtons[i]->render(UnitButtonDest);
	}

	// Barra de energia
	SDL_Color available = { 0x0, 0x80, 0x0, 0xFF };		// verde
	SDL_Color bkgrColor = { 0xA9, 0xA9, 0xA9, 0xFF };	// gris
	this->RenderVPBar(this->window.width * 63 / 80,
	                  this->window.height * 6 / 16,
	                  this->window.height * 32 / 64,
	                  this->player.getEnergyRatio(),
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

int GameView::getCameraX() const {
	return this->camera.getX();
}

int GameView::getCameraY() const {
	return this->camera.getY();
}

int GameView::getCameraWidth() const {
	return this->camera_width;
}

int GameView::getCameraHeight() const {
	return this->camera_height;
}

void GameView::grabMouse() {
	this->window.grabMouse(true);
}

void GameView::releaseMouse() {
	this->window.grabMouse(false);
}

ButtonView& GameView::createUnitButton(const std::string &filename, int number_steps) {
	ButtonView* newButtonView = new ButtonView(filename, this->window, number_steps);
	this->unitButtons.emplace_back(newButtonView);
	return *newButtonView;
}

ButtonView& GameView::createBuildingButton(const std::string &playerHouse, int number_steps) {
	std::string filename;
	if (playerHouse == "Atreides") {
		filename = "../assets/img/btns/buildings/barracks-atreides.jpg";
	} else if (playerHouse == "Harkonnen") {
		filename = "../assets/img/btns/buildings/barracks-harkonnen.jpg";
	} else if (playerHouse == "Ordos") {
		filename = "../assets/img/btns/buildings/barracks-ordos.jpg";
	} else {
		filename = playerHouse;
	}
	ButtonView* newButtonView = new ButtonView(filename, this->window, number_steps);
	this->buildingButtons.emplace_back(newButtonView);
	return *newButtonView;
}

ButtonView& GameView::createSellBuildingButton(const std::string& filename) {
	this->buildingSellButton = new ButtonView(filename, this->window);
	return *(this->buildingSellButton);
}
