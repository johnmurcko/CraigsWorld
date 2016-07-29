#include "OriginRock.hpp"

OriginRock::OriginRock (float x, float y, Origin * origin) {
    this->origin = origin;
    last_origin_x = origin->getX ();
	last_origin_y = origin->getY ();
    setX(x);
    setY(y);
}
void OriginRock::setX (float x) {
	this->x = origin->getX()+x;
}

void OriginRock::setY (float y) {
	this->y = origin->getY()+y;
}

float OriginRock::getX () {
	return x;
}

float OriginRock::getY () {
	return y;
}

void OriginRock::update () {
	x = x + origin->getX () - last_origin_x;
	y = y + origin->getY () - last_origin_y;

	last_origin_x = origin->getX ();
	last_origin_y = origin->getY ();
}

void OriginRock::draw (sf::RenderWindow * window) {
	sf::RectangleShape rockRect(sf::Vector2f(5,5));
	rockRect.setPosition(getX(), getY());
	rockRect.setFillColor(sf::Color::Blue);
    window->draw(rockRect);
}
