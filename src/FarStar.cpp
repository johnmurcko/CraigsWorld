#include "FarStar.hpp"
#include "Star.hpp"

FarStar::FarStar(float x, float y) : Star(x, y) {

}

void FarStar::move(float x_delta, float y_delta) {
    setX(getX() + x_delta / 10);
    setY(getY() + y_delta / 10);
}

void FarStar::update() {
    Star::update();
}

void FarStar::draw (sf::RenderWindow * window) {
    sf::RectangleShape starRect(sf::Vector2f(1,1));
	starRect.setPosition(getX(), getY());
	starRect.setFillColor(sf::Color::White);
    window->draw(starRect);
}
