#include "UnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Position.h"
#include "Orientation.h"
#include "../../Common/Area.h"
#include <map>
#include <vector>
#include <memory>

std::vector<std::unique_ptr<SdlTexture> > UnitView::damage_sprites;

UnitView::UnitView(Unit& unit, Area sprite_area, SdlWindow& window):
	window(window),
	playerColorRect(),
	unit(unit),
	damage_sprite_area(Area(0, 0, 15, 15)),
	sprite_area(sprite_area),
	damage_dest_area(Area(0, 0, 7, 7)),
	dest_area(sprite_area),
	prev_pos(unit.getPosition()),
	orientation(),
	life(unit.getLife()),
	damage_anim_it(),
	damage_update(0),
	animating_damage(false) {
	PlayerColorMaker::makeColor(unit.getPlayer(), &player_r, &player_g, &player_b);
	playerColorRect.x = 0;
	playerColorRect.y = 0;
	playerColorRect.w = sprite_area.getWidth();
	playerColorRect.h = sprite_area.getHeight();
	if (damage_sprites.empty()) {
		damage_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebc36.bmp",window)));
		damage_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebc00.bmp",window)));
		damage_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebbb2.bmp",window)));
		damage_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebb55.bmp",window)));
		damage_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002eb959.bmp",window)));
		damage_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002eb9fa.bmp",window)));
		damage_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002eba90.bmp",window)));
		damage_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebb55.bmp",window)));
		damage_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebbb2.bmp",window)));
		damage_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebc00.bmp",window)));
		damage_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebc36.bmp",window)));
	}
	damage_anim_it = damage_sprites.begin();
}

UnitView::~UnitView() {}

Unit &UnitView::getUnit() {
	return unit;
}

bool UnitView::isDead(const UnitView *unit_view) {
	return unit_view->unit.isDead();
}

void UnitView::draw(Area& camara, std::map<int, std::unique_ptr<SdlTexture>>& sprites) {
	Position pos = unit.getPosition();
	dest_area.setX(pos.x - camara.getX() - sprite_area.getWidth() / 2);
	dest_area.setY(pos.y - camara.getY() - sprite_area.getHeight() / 2);
	orientation.calcular(prev_pos, pos);
	prev_pos = pos;
	playerColorRect.x = dest_area.getX();
	playerColorRect.y = dest_area.getY();

	SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(window.getRenderer(), player_r, player_g, player_b, 250);
	SDL_RenderDrawRect(window.getRenderer(), &playerColorRect);
	SDL_SetRenderDrawColor(window.getRenderer(), player_r, player_g, player_b, 30);
	SDL_RenderFillRect(window.getRenderer(), &playerColorRect);
	sprites.at(orientation.getValor())->render(sprite_area, dest_area);

	if (life > unit.getLife()) {
		life = unit.getLife();
		animating_damage = true;
	}
	if (animating_damage) {
		drawDamage(camara);
	}
}


void UnitView::draw(Area& camara, std::map<int, std::vector<std::unique_ptr<SdlTexture> > >& sprites
                    , std::vector<std::unique_ptr<SdlTexture> >::iterator& anim_it, int& update)
{
	Position pos = unit.getPosition();
	dest_area.setX(pos.x - camara.getX() - sprite_area.getWidth() / 2);
	dest_area.setY(pos.y - camara.getY() - sprite_area.getHeight() / 2);
	if (!(prev_pos == pos)) {
		Orientation prev_orient = orientation;
		orientation.calcular(prev_pos, pos);
		if (!(orientation == prev_orient)) {
			anim_it = sprites.at(orientation.getValor()).begin();
			update = 0;
		}
		if (update == 0) {
			anim_it++;
			update = 0;
			if (anim_it == sprites.at(orientation.getValor()).end()) {
				anim_it = sprites.at(orientation.getValor()).begin();
			}
		} else {
			update++;
		}
		prev_pos = pos;
	}
	playerColorRect.x = dest_area.getX();
	playerColorRect.y = dest_area.getY();

	SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(window.getRenderer(), player_r, player_g, player_b, 250);
	SDL_RenderDrawRect(window.getRenderer(), &playerColorRect);
	SDL_SetRenderDrawColor(window.getRenderer(), player_r, player_g, player_b, 30);
	SDL_RenderFillRect(window.getRenderer(), &playerColorRect);

	//(*anim_it)->setColor(unit.getPlayer().getId());
	(*anim_it)->render(sprite_area, dest_area);
	if (life > unit.getLife()) {
		life = unit.getLife();
		animating_damage = true;
	}
	if (animating_damage) {
		drawDamage(camara);
	}
}

void UnitView::drawDamage(Area& camara) {
	damage_dest_area.setX(dest_area.getX() + dest_area.getWidth() / 2 - 4);
	damage_dest_area.setY(dest_area.getY() + dest_area.getHeight() / 2);
	if (damage_update == 4) {
		damage_anim_it++;
		damage_update = 0;
		if (damage_anim_it == damage_sprites.end()) {
			animating_damage = false;
			damage_anim_it = damage_sprites.begin();
		}
	} else {
		damage_update++;
	}
	(*damage_anim_it)->render(damage_sprite_area, damage_dest_area);
}


DeadUnitView* UnitView::getDeadUnitView() {
	return new DeadUnitView(prev_pos, this->getDeadUnitSrcArea(), this->getDeadUnitDestArea(),
	                        this->getDeadSprites(), player_r, player_g, player_b, window);
}
