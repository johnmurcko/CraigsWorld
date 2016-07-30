#include "Player.hpp"

Player::Player (float x, float y, Origin * origin) {
	this->origin = origin;
	setX (x);
	setY (y);
}

float Player::getX () {
	return x;
}

float Player::getY () {
	return y;
}

void Player::setX (float x) {
	this->x = x;
}

void Player::setY (float y) {
	this->y = y;
}

void Player::move (float x_delta, float y_delta) {
    setX (getX () + x_delta);
    setY (getY () + y_delta);
}

void Player::draw (sf::RenderWindow * window) {
	sf::RectangleShape playerRect(sf::Vector2f (10,10));
	playerRect.setPosition(getX (), getY ());
	playerRect.setFillColor (sf::Color::Green);
	window->draw (playerRect);
}
