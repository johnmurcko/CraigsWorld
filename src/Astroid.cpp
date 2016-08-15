#include "Astroid.hpp"
#include <cstdlib>
#include <cmath>
#include "Constants.hpp"

Astroid::Astroid(float x, float y) {
	setX(x);
	setY(y);
	setWidth(kWidth);
	setHeight(kHeight);
	setAngle(rand() % 360);
}

void Astroid::update(sf::Time * delta_time) {
	Entity::update();
	setXVelocity(cos(getAngle() * kDegreesToRadians) * delta_time->asSeconds());
	setYVelocity(cos(getAngle() * kDegreesToRadians) * delta_time->asSeconds());

	move(getXVelocity(), getYVelocity());
}

void Astroid::draw(sf::RenderWindow * window) {
	sf::RectangleShape astroid_rect(sf::Vector2f(getWidth(), getHeight()));
	astroid_rect.setFillColor(sf::Color::Red);
	astroid_rect.setPosition(getX(), getY());
	window->draw(astroid_rect);
}
