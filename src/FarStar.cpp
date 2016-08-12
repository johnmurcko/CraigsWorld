#include "FarStar.hpp"
#include "Star.hpp"
#include "Constants.hpp"

FarStar::FarStar(float x, float y) : Star(x, y) {

}

void FarStar::update() {
	setX(getX() + origin->getX()/2 - last_origin_x/2);
	setY(getY() + origin->getY()/2 - last_origin_y/2);

	last_origin_x = origin->getX();
	last_origin_y = origin->getY();

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

void FarStar::draw (sf::RenderWindow * window) {
    sf::RectangleShape starRect(sf::Vector2f(1,1));
	starRect.setPosition(getX(), getY());
	starRect.setFillColor(sf::Color::White);
    window->draw(starRect);
}
