#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Enemy.hpp"
#include "Constants.hpp"

Enemy::Enemy(float x, float y, Origin * origin) {
	this->origin = origin;
    last_origin_x = origin->getX();
	last_origin_y = origin->getY();
	setX(x);
	setY(y);
	speed = kDefaultSpeed;
	target = NULL;
	generateWanderTarget();
}

void Enemy::setSpeed(float speed) {
	this->speed = speed;
}

float Enemy::getSpeed() {
	return speed;
}

void Enemy::generateWanderTarget() {

    if (target) {
    	delete target;
    }

    float rand_x = getX() +(rand() % kTargetRange) -(kTargetRange / 2);
    float rand_y = getY() +(rand() % kTargetRange) -(kTargetRange / 2);
	target = new Target(rand_x, rand_y, kTargetWidth, kTargetHeight, origin);
}

void Enemy::update(sf::Time * delta_time) {
	Entity::update();
	target->update(delta_time);

	if (getX() < target->getCenterX())  {
		move(1 * getSpeed() * delta_time->asSeconds(), 0);
	}
	else if (getX() > target->getCenterX()) {
		move(-1 * getSpeed() * delta_time->asSeconds(), 0);
	}

	if (getY() < target->getCenterY()) {
		move(0, 1 * getSpeed() * delta_time->asSeconds());
	}
	else if (getY() > target->getCenterY()) {
		move(0, -1 * getSpeed() * delta_time->asSeconds());
	}

	if (isIntersecting(target)) {
        generateWanderTarget();
	}
}

void Enemy::draw(sf::RenderWindow * window) {
	sf::RectangleShape enemy_rect(sf::Vector2f(10,10));
	enemy_rect.setPosition(getX(), getY());
	enemy_rect.setFillColor(sf::Color::Red);
	sf::RectangleShape target_rect(sf::Vector2f(50, 50));
	target_rect.setPosition(target->getX(), target->getY());
	target_rect.setFillColor(sf::Color::Green);
	window->draw(enemy_rect);
}

Enemy::~Enemy() {
	if (target) {
		delete target;
	}
}
