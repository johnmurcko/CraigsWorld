#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Enemy.hpp"
#include "Constants.hpp"

Enemy::Enemy(float x, float y, Origin * origin) {
	this->origin = origin;
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
	target->update();
    //std::cout << '\n' << getX();
	if (getX() <= target->getX()) {
		move(1 * getSpeed() * delta_time->asSeconds(), 0);
	}
	else if (getX() > target->getX()) {
		move(-1 * getSpeed() * delta_time->asSeconds(), 0);
	}

	if (getY() <= target->getY()) {
		move(0, 1 * getSpeed() * delta_time->asSeconds());
	}
	else if (getX() > target->getX()) {
		move(0, -1 * getSpeed() * delta_time->asSeconds());
	}

    if (isIntersecting(target)) {
        generateWanderTarget();
    }
}

void Enemy::draw(sf::RenderWindow * window) {
	sf::RectangleShape enemyRect(sf::Vector2f(10,10));
	enemyRect.setPosition(getX(), getY());
	enemyRect.setFillColor(sf::Color::Red);
	window->draw(enemyRect);
}

void Enemy::dealloc() {
	if (target) {
		delete target;
	}
}
