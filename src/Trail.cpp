#include "Trail.hpp"
#include "SFML/System.hpp"

Trail::Trail(float x, float y) {
    origin = Origin::getInstance();
    last_origin_x = origin->getX();
	last_origin_y = origin->getY();
    setX(x);
    setY(y);
    setWidth(kTrailWidth);
    setHeight(kTrailHeight);
    clock = new sf::Clock();
    is_old = false;
}

void Trail::update() {
    Entity::update();
    sf::Time time_since_creation = clock->getElapsedTime();
    if (time_since_creation.asSeconds() > 2) {
        is_old = true;
    }

}

bool Trail::isOld() {
    return is_old;
}


void Trail::draw(sf::RenderWindow * window) {

	sf::Sprite trail_sprite;
    sf::Texture trail_texture;
    trail_texture.loadFromFile("res/placeholdercloud.png");
    trail_sprite.setScale(2.0f,2.0f);
    trail_sprite.setTexture(trail_texture, true);
    trail_sprite.setOrigin(getWidth() / 2, getHeight() / 2);
    trail_sprite.setPosition(getX(), getY());


	window->draw(trail_sprite);
}

Trail::~Trail() {
    delete clock;
}
