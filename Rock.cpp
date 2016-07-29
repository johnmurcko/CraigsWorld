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
void Rock::setX (float x) {
	this->x = origin->getX () + x;
}

void Rock::setY (float y) {
	this->y = origin->getY () + y;
}

float Rock::getX () {
	return x;
}

float Rock::getY () {
	return y;
}

void Rock::update () {
	x = x + origin->getX () - last_origin_x;
	y = y + origin->getY () - last_origin_y;

	last_origin_x = origin->getX ();
	last_origin_y = origin->getY ();
}

void Rock::draw (sf::RenderWindow * window) {
	sf::RectangleShape rockRect (sf::Vector2f (1,1));
	rockRect.setPosition (getX (), getY ());
	rockRect.setFillColor (sf::Color::Yellow);
    window->draw (rockRect);
}
