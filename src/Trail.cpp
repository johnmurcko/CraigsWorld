#include "Trail.hpp"

Trail::Trail(float x, float y, Origin * origin) {
    this->origin = origin;
    setX(x);
    setY(y);
    setWidth(kTrailWidth);
    setHeight(kTrailHeight);
}

void Trail::draw(sf::RenderWindow * window) {
	sf::RectangleShape trail_rect(sf::Vector2f(getWidth(), getHeight()));
	trail_rect.setPosition(getX(), getY());
	trail_rect.setFillColor(sf::Color::Yellow);
	window->draw(trail_rect);
}
