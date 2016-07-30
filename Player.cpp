#include "Player.hpp"
#include "Constants.hpp"

Player::Player (float x, float y, Origin * origin) {
	this->origin = origin;
	setX (x);
	setY (y);
	speed = kDefaultSpeed;
}


void Player::setSpeed (float speed) {
	this->speed = speed;
}


float Player::getSpeed () {
	return speed;
}

void Player::draw (sf::RenderWindow * window) {
	sf::RectangleShape playerRect(sf::Vector2f (10,10));
	playerRect.setPosition(getX (), getY ());
	playerRect.setFillColor (sf::Color::Green);
	window->draw (playerRect);
}
