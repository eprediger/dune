#include "GameView.h"

GameView::GameView(const int width, const int height) :
	View(width, height),
	backgroundMusic("../assets/sound/music/fight-for-power.mp3"),
	moneyTag(Text("DINERO", TAG_FONT_SIZE, this->window)),
	buildingTag(Text("EDIFICIOS", TAG_FONT_SIZE, this->window)),
	unitsTag(Text("UNIDADES", TAG_FONT_SIZE, this->window)),
	moneyBalance(0),
	buildings(),
	units(),
	buttons("../assets/img/btns/cursors.png", this->window) {
	/*barracks-atreides.jpg
	barracks-harkonnen.jpg
	barracks-ordos.jpg*/
	this->buildings.push_back(new SdlTexture("../assets/img/btns/buildings/windtrap.gif", this->window));
	this->buildings.push_back(new SdlTexture("../assets/img/btns/buildings/refinery.jpg", this->window));
	this->buildings.push_back(new SdlTexture("../assets/img/btns/buildings/silo.gif", this->window));
	this->buildings.push_back(new SdlTexture("../assets/img/btns/buildings/light-factory.gif", this->window));
	this->buildings.push_back(new SdlTexture("../assets/img/btns/buildings/heavy-factory.gif", this->window));
	this->units.emplace_back(new SdlTexture("../assets/img/btns/units/harvest.gif", this->window));
	this->units.emplace_back(new SdlTexture("../assets/img/btns/units/linfantry.gif", this->window));
	this->units.emplace_back(new SdlTexture("../assets/img/btns/units/hinfantry.gif", this->window));
	this->units.emplace_back(new SdlTexture("../assets/img/btns/units/raider.gif", this->window));
	this->units.emplace_back(new SdlTexture("../assets/img/btns/units/trike.jpg", this->window));
	this->units.emplace_back(new SdlTexture("../assets/img/btns/units/tank.gif", this->window));
	backgroundMusic.start();
}

GameView::~GameView() {
	backgroundMusic.stop();
	backgroundMusic.join();
	while (this->buildings.size() > 0) {
		delete this->buildings.back();
		this->buildings.pop_back();
	}
	while (this->units.size() > 0) {
		delete this->units.back();
		this->units.pop_back();
	}
}

void GameView::RenderHPBar(int x, int y, int w, int h, float percent, SDL_Color FGColor, SDL_Color BGColor) {
	percent = percent > 1.f ? 1.f : percent < 0.f ? 0.f : percent;
	SDL_Color old;
	SDL_GetRenderDrawColor(this->window.getRenderer(), &old.r, &old.g, &old.g, &old.a);
	SDL_Rect bgrect = { x, y, w, h };
	SDL_SetRenderDrawColor(this->window.getRenderer(), BGColor.r, BGColor.g, BGColor.b, BGColor.a);
	SDL_RenderFillRect(this->window.getRenderer(), &bgrect);
	SDL_SetRenderDrawColor(this->window.getRenderer(), FGColor.r, FGColor.g, FGColor.b, FGColor.a);
	int pw = (int)((float)w * percent);
	int px = x + (w - pw);
	SDL_Rect fgrect = { px, y, pw, h };
	SDL_RenderFillRect(this->window.getRenderer(), &fgrect);
	SDL_SetRenderDrawColor(this->window.getRenderer(), old.r, old.g, old.b, old.a);
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

void GameView::render() {
	// Dinero
	this->moneyTag.render((this->window.width - this->moneyTag.textWidth) / 2, 0);
	// Botones
	// Vender Edificio
	// Area sellSrc(20, 450, 30, 40);	// boton venta habilitada
	Area sellSrc(170, 75, 35, 40);	// boton ventana deshabilitada
	Area sellDest(this->window.width * 16 / 20, this->window.height * 5 / 16, 35, 40);
	this->buttons.render(sellSrc, sellDest);

	// Edificios
	// this->buildingTag.render(this->window.width * 12 / 16, this->window.height * 5 / 16);
	for (unsigned i = 0; i < this->buildings.size(); ++i) {
		Area buildingSrc(0, 0, this->buildings[i]->width, this->buildings[i]->height);
		Area buildingDest(this->window.width * 16 / 20,	//this->window.width * 1 / 128,
		                  this->window.height * (6 + 2 * i) / 16,	//this->window.height * (1 + 8 * i) / 64,
		                  80,
		                  80 * 3 / 4);
		this->buildings[i]->render(buildingSrc, buildingDest);
	}

	// Unidades
	// this->unitsTag.render(this->window.width * 28 / 32, this->window.height * 5 / 16);
	for (unsigned i = 0; i < this->units.size(); ++i) {
		Area UnitSrc(0, 0, this->units[i]->width, this->units[i]->height);
		Area UnitDest(this->window.width * 18 / 20,	// this->window.width * 29 / 32,
		              this->window.height * (6 + 2 * i) / 16,	// this->window.height * (1 + 8 * i) / 64,
		              80,
		              80 * 3 / 4);
		this->units[i]->render(UnitSrc, UnitDest);
	}
	// Barra de energia harcodeada, se debe leer la energia del jugador en el modelo
	SDL_Color available = { 0x0, 0x80, 0x0, 0xFF };	//{ 0xFF, 0x0, 0x0, 0xFF };
	SDL_Color bkgrColor = { 0xA9, 0xA9, 0xA9, 0xFF };	//{ 0x0, 0xFF, 0x0, 0xFF };
	this->RenderVPBar(this->window.width * 63 / 80,	//this->window.width * 1 / 10,
	                  this->window.height * 6 / 16,	//this->window.height * 1 / 64,
	                  5,
	                  this->window.height * 19 / 32,
	                  0.75f, available, bkgrColor);

	this->window.render();
}
