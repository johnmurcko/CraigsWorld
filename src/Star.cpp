#include "Star.hpp"
#include "Constants.hpp"

Star::Star(float x, float y) {
	origin = Origin::getInstance();
	last_origin_x = origin->getX();
	last_origin_y = origin->getY();
    setX(x);
    setY(y);
}

void Star::draw(sf::RenderWindow * window) {
	sf::RectangleShape starRect(sf::Vector2f(1,1));
	starRect.setPosition(getX(), getY());
	starRect.setFillColor(sf::Color::White);
    window->draw(starRect);
}

void Star::update() {
    Entity::update();
    if (getX() > kWindowWidth) {
        setX(getX() - kWindowWidth);
    }
    else if (getX() < 0) {
        setX(getX() + kWindowWidth);
    }

    if (getY() > kWindowHeight) {
        setY(getY() - kWindowHeight);
    }
    else if (getY() < 0) {
        setY(getY() + kWindowHeight);
    }
}
