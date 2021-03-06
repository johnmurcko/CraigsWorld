#include "Trail.hpp"
#include "SFML/System.hpp"

Trail::Trail(float x, float y) {
    origin = Origin::getInstance();
    last_origin_x = origin->getX();
	last_origin_y = origin->getY();
	setRadius(kTrailRadius);
	setTransparency(255);
    setX(x - getRadius() / 2);
    setY(y - getRadius() / 2);

    clock = new sf::Clock();
    is_old = false;
}

void Trail::update(sf::Time * delta_time) {
    Entity::update();
    setRadius(getRadius() * 1.02f);
    setTransparency(getTransparency() * 0.95f);
    if (getRadius() > 60) {
        is_old = true;
    }
}

void Trail::setRadius (float radius) {
    this->radius = radius;
}

void Trail::setTransparency(float transparency) {
    this->transparency = transparency;
}

float Trail::getRadius () {
    return radius;
}

float Trail::getTransparency() {
    return transparency;
}

bool Trail::isOld() {
    return is_old;
}

void Trail::draw(sf::RenderWindow * window) {

    sf::Color trail_color(0, 255, 255, getTransparency());

    sf::CircleShape trail_circle(getRadius());
    trail_circle.setOutlineColor(trail_color);
    trail_circle.setOutlineThickness(4);
    trail_circle.setFillColor(sf::Color::Transparent);
    trail_circle.setOrigin(getRadius() / 2, getRadius() / 2);
    trail_circle.setPosition(getX(), getY());

	window->draw(trail_circle);
}

Trail::~Trail() {
    delete clock;
}
