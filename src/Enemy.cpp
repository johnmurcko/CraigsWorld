#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Enemy.hpp"
#include "Constants.hpp"
#include "Player.hpp"

Enemy::Enemy(float x, float y) {
	origin = Origin::getInstance();
    last_origin_x = origin->getX();
	last_origin_y = origin->getY();
	setX(x);
	setY(y);
	speed = kDefaultSpeed;
	is_wandering = true;
	target = NULL;
    clock = new sf::Clock();
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
	target = new Target(rand_x, rand_y, kTargetWidth, kTargetHeight);
}

void Enemy::update(sf::Time * delta_time) {
	Entity::update();
    target->update();

	if (is_wandering) {
		wander(delta_time);
	}

	if (distanceFrom(Player::getInstance()) < 200) {
		is_wandering = false;
		followPlayer(delta_time);
	}
	else {
		is_wandering = true;
	}


	std::vector<CombatEntity*> player;
	player.push_back(Player::getInstance());
	for (unsigned int i = 0; i < bullet.size(); i++) {
        bullet.at(i)->update(&player, delta_time);
        if (distanceFrom(bullet.at(i)) > 500 || bullet.at(i)->isDestroyed()) {
            delete bullet.at(i);
            bullet.erase(bullet.begin() + i);
            i--;
        }
	}
}

void Enemy::wander(sf::Time * delta_time) {
	if (getX() < target->getCenterX())  {
		move(1 * getSpeed() * delta_time->asSeconds(), 0);
	}
	else if (getX() > target->getCenterX()){
		move(-1 * getSpeed() * delta_time->asSeconds(), 0);
	}

	if (getY() < target->getCenterY()) {
		move(0, 1 * getSpeed() * delta_time->asSeconds());
	}
	else if (getY() > target->getCenterY()){
		move(0, -1 * getSpeed() * delta_time->asSeconds());
	}

	if (isIntersecting(target)) {
        generateWanderTarget();
	}
}

void Enemy::followPlayer (sf::Time * delta_time) {
	if (getCenterX() < Player::getInstance()->getCenterX()) {
		move(1 * getSpeed() * delta_time->asSeconds(), 0);
	}
	else {
		move(-1 * getSpeed() * delta_time->asSeconds(), 0);
	}

	if (getCenterY() < Player::getInstance()->getCenterY()) {
		move(0, 1 * getSpeed() * delta_time->asSeconds());
	}
	else {
		move(0, -1 * getSpeed() * delta_time->asSeconds());
	}

    sf::Time time_since_last_fire = clock->getElapsedTime();

	if (distanceFrom(Player::getInstance()) < 500
        && time_since_last_fire.asSeconds() > 1) {

        fireBullet();
        clock->restart();
	}

	if (isIntersecting(Player::getInstance())) {
		//Player::getInstance()->loseHealth();
	}
}

void Enemy::fireBullet() {
    Bullet * new_bullet = new Bullet(getCenterX(), getCenterY(),
		angleTo(Player::getInstance()));
    bullet.push_back(new_bullet);
}

void Enemy::draw(sf::RenderWindow * window) {
    for (unsigned int i = 0; i < bullet.size(); i++) {
        bullet.at(i)->draw(window);
	}

	sf::RectangleShape enemy_rect(sf::Vector2f(10,10));
	enemy_rect.setPosition(getX(), getY());
	enemy_rect.setFillColor(sf::Color::Red);
	sf::RectangleShape target_rect(sf::Vector2f(50, 50));
	target_rect.setPosition(target->getX(), target->getY());
	target_rect.setFillColor(sf::Color::Green);
	window->draw(enemy_rect);
	window->draw(target_rect);
}

Enemy::~Enemy() {
	if (target) {
		delete target;
	}
}
