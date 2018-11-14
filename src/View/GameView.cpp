#include "GameView.h"
#include "View.h"
#include "../Model/Model.h"
#include "BuildingView.h"
#include <algorithm>

GameView::GameView(const int width, const int height, Model& model) :
	View(width / 2, height / 2),
	model(model),
	unitViews(),
	buildingViews(),
	selectorView(nullptr),
	map_view(model.getMap(), window),
	camera(0, 0, width / 2, height / 2),
	backgroundMusic("../assets/sound/music/fight-for-power.mp3"),
	moneyTag(Text("DINERO", TAG_FONT_SIZE, this->window)),
	moneyBalance(Text(std::to_string(model.getPlayer(0).gold), TAG_FONT_SIZE, this->window)),
	buildingTag(Text("EDIFICIOS", TAG_FONT_SIZE, this->window)),
	unitsTag(Text("UNIDADES", TAG_FONT_SIZE, this->window)),
	buildingButtons(),			// nombre
	unitButtons(),				// nombre
	buttons("../assets/img/btns/cantSell.png", this->window),
	map_width(width),
	map_height(height),
	camera_width(width / 2),
	camera_height(height / 2) {
	this->buildingButtons.push_back(new SdlTexture("../assets/img/btns/buildings/windtrap.gif", this->window));
	this->buildingButtons.push_back(new SdlTexture("../assets/img/btns/buildings/refinery.jpg", this->window));
	this->buildingButtons.push_back(new SdlTexture("../assets/img/btns/buildings/silo.gif", this->window));
	this->buildingButtons.push_back(new SdlTexture("../assets/img/btns/buildings/light-factory.gif", this->window));
	this->buildingButtons.push_back(new SdlTexture("../assets/img/btns/buildings/heavy-factory.gif", this->window));
	this->unitButtons.emplace_back(new SdlTexture("../assets/img/btns/units/harvest.gif", this->window));
	this->unitButtons.emplace_back(new SdlTexture("../assets/img/btns/units/linfantry.gif", this->window));
	this->unitButtons.emplace_back(new SdlTexture("../assets/img/btns/units/hinfantry.gif", this->window));
	this->unitButtons.emplace_back(new SdlTexture("../assets/img/btns/units/raider.gif", this->window));
	this->unitButtons.emplace_back(new SdlTexture("../assets/img/btns/units/trike.jpg", this->window));
	this->unitButtons.emplace_back(new SdlTexture("../assets/img/btns/units/tank.gif", this->window));
	backgroundMusic.start();

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
	bool has_dead_views = false;
	for (auto unit_view : unitViews) {
		if (UnitView::isDead(unit_view)) {
			has_dead_views = true;
			delete unit_view;
		}
	}
	if (has_dead_views) {
		unitViews.erase(std::remove_if(unitViews.begin(), unitViews.end(), UnitView::isDead));
	}
}

GameView::~GameView() {
	backgroundMusic.stop();

	while (this->buildingButtons.size() > 0) {
		delete this->buildingButtons.back();
		this->buildingButtons.pop_back();
	}
	while (this->unitButtons.size() > 0) {
		delete this->unitButtons.back();
		this->unitButtons.pop_back();
	}

	for (auto unit_view : unitViews) {
		delete unit_view;
	}
	for (auto building_view : buildingViews) {
		delete building_view;
	}
	backgroundMusic.join();
}

SdlWindow &GameView::getWindow() {
	return window;
}

void GameView::render() {
	//    for (auto unit_view : unitViews){
	map_view.draw(camera);
	for (auto itr = unitViews.begin(); itr != unitViews.end(); ++itr) {
		if (!Unit::isDead(&(*itr)->getUnit())) {
			(*itr)->draw(camera);
		}
	}

	for (auto itr = buildingViews.begin(); itr != buildingViews.end(); ++itr) {
		(*itr)->draw(camera);
	}

	if (selectorView != nullptr) {
		selectorView->draw(camera);
	}

	// Dinero
	this->moneyTag.render((this->window.width - this->moneyTag.textWidth) / 2, 0);
	this->moneyBalance.setText(std::to_string(model.getPlayer(0).gold));
	this->moneyBalance.render((this->window.width - this->moneyBalance.textWidth) / 2 + this->moneyTag.textWidth, 0);
	// Botones
	// Vender Edificio
	// Area sellSrc(20, 450, 30, 40);	// boton venta habilitada
	this->buttons.render(this->window.width * 16 / 20, this->window.height * 4 / 16);

	// Edificios
	this->buildingTag.render(this->window.width * 12 / 16, this->window.height * 5 / 16);
	for (unsigned i = 0; i < this->buildingButtons.size(); ++i) {
		Area buildingSrc(0, 0, this->buildingButtons[i]->width, this->buildingButtons[i]->height);
		Area buildingDest(this->window.width * 16 / 20,	//this->window.width * 1 / 128,
		                  this->window.height * (6 + 2 * i) / 16,	//this->window.height * (1 + 8 * i) / 64,
		                  80,
		                  80 * 3 / 4);
		this->buildingButtons[i]->render(buildingSrc, buildingDest);
	}

	// Unidades
	this->unitsTag.render(this->window.width * 28 / 32, this->window.height * 5 / 16);
	for (unsigned i = 0; i < this->unitButtons.size(); ++i) {
		Area UnitSrc(0, 0, this->unitButtons[i]->width, this->unitButtons[i]->height);
		Area UnitDest(this->window.width * 18 / 20,	// this->window.width * 29 / 32,
		              this->window.height * (6 + 2 * i) / 16,	// this->window.height * (1 + 8 * i) / 64,
		              80,
		              80 * 3 / 4);
		this->unitButtons[i]->render(UnitSrc, UnitDest);
	}
	// Barra de energia harcodeada, se debe leer la energia del jugador en el modelo
	SDL_Color available = { 0x0, 0x80, 0x0, 0xFF };	//{ 0xFF, 0x0, 0x0, 0xFF };
	SDL_Color bkgrColor = { 0xA9, 0xA9, 0xA9, 0xFF };	//{ 0x0, 0xFF, 0x0, 0xFF };
	this->RenderVPBar(this->window.width * 63 / 80,	//this->window.width * 1 / 10,
					  this->window.height * 0 / 16,	//this->window.height * 1 / 64,
					  5,
					  this->window.height * 19 / 32,
					  0.5f,//this->model.getPlayer(0).consumedEnergy/this->model.getPlayer(0).generatedEnergy,
					  available, bkgrColor);

	if (selectorView!=nullptr){
		selectorView->draw(camera);
	}

	this->window.render();
}

void GameView::RenderVPBar(int x, int y, int w, int h, float percent, SDL_Color FGColor, SDL_Color BGColor) {
	percent = percent > 1.f ? 1.f : percent < 0.f ? 0.f : percent;
	SDL_Color old;
	SDL_GetRenderDrawColor(this->window.getRenderer(), &old.r, &old.g, &old.g, &old.a);
	SDL_Rect bgrect = { x, y, w, h };
	SDL_SetRenderDrawColor(this->window.getRenderer(), BGColor.r, BGColor.g, BGColor.b, BGColor.a);
	SDL_RenderFillRect(this->window.getRenderer(), &bgrect);
	SDL_SetRenderDrawColor(this->window.getRenderer(), FGColor.r, FGColor.g, FGColor.b, FGColor.a);
	int ph = (int)((float)h * percent);
	int py = y + (h - ph);
	SDL_Rect fgrect = { x, py, w, ph };
	SDL_RenderFillRect(this->window.getRenderer(), &fgrect);
	SDL_SetRenderDrawColor(this->window.getRenderer(), old.r, old.g, old.b, old.a);
}

void GameView::moveUp(int distance) {
	int new_y = camera.getY() - distance;
	camera.setY((new_y > 0) ? new_y : 0);
}

void GameView::moveDown(int distance) {
	int new_y = camera.getY() + distance;
	camera.setY((new_y < (map_height - camera_height)) ? new_y : map_height - camera_height);
}

void GameView::moveLeft(int distance) {
	int new_x = camera.getX() - distance;
	camera.setX((new_x > 0) ? new_x : 0);
}

void GameView::moveRight(const int distance) {
	int new_x = camera.getX() + distance;
	camera.setX((new_x < (map_width - camera_width)) ? new_x : map_width - camera_width);
}
