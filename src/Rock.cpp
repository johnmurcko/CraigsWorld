#include "Rock.hpp"

Rock::Rock () {

}
Rock::Rock (float x, float y, Origin * origin) {
    this->origin = origin;
	last_origin_x = origin->getX ();
	last_origin_y = origin->getY ();
    setX (x);
    setY (y);
}

void Rock::draw (sf::RenderWindow * window) {
	sf::RectangleShape rockRect (sf::Vector2f (1,1));
	rockRect.setPosition (getX (), getY ());
	rockRect.setFillColor (sf::Color::Yellow);
    window->draw (rockRect);
}
