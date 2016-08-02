#include "Trail.hpp"

Trail::Trail(float x, float y, Origin * origin) {
    this->origin = origin;
    last_origin_x = origin->getX();
	last_origin_y = origin->getY();
    setX(x);
    setY(y);
    setWidth(kTrailWidth);
    setHeight(kTrailHeight);
}

void Trail::draw(sf::RenderWindow * window) {


	sf::Sprite trail_sprite;
    sf::Texture trail_texture;
    trail_texture.loadFromFile("res/placeholdercloud.png");
    trail_sprite.setTexture(trail_texture, true);
    trail_sprite.setOrigin(getWidth() / 2, getHeight() / 2);
    trail_sprite.setPosition(getX(), getY());


	window->draw(trail_sprite);
}
