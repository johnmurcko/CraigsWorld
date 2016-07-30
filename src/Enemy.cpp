#include "Enemy.hpp"
#include "Constants.hpp"

Enemy::Enemy (float x, float y, Origin * origin) {
	this->origin = origin;
	setX (x);
	setY (y);
	speed = kDefaultSpeed;
	generateWanderTarget ();
}

void Enemy::setSpeed (float speed) {
	this->speed = speed;
}

float Enemy::getSpeed () {
	return speed;
}

void Enemy::generateWanderTarget () {

}

void Enemy::draw (sf::RenderWindow * window) {
	sf::RectangleShape enemyRect(sf::Vector2f (10,10));
	enemyRect.setPosition(getX (), getY ());
	enemyRect.setFillColor (sf::Color::Red);
	window->draw (enemyRect);
}
