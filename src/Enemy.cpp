#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Enemy.hpp"
#include "Constants.hpp"
#include "Player.hpp"
#include "GridManager.hpp"

Enemy::Enemy(float x, float y) {
	origin = Origin::getInstance();
    last_origin_x = origin->getX();
	last_origin_y = origin->getY();
	setX(x);
	setY(y);
    enemy_type = rand() % 2;
	speed = kDefaultSpeed / 50;
	is_wandering = true;
	target = NULL;
	setDestroyed(false);
    clock = new sf::Clock();
	generateWanderTarget();
	GridManager::getInstance()->assignEntityToCells(this);
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

	if (distanceFrom(Player::getInstance()) < 500) {
		is_wandering = false;
		followPlayer(delta_time);
	}
	else if (distanceFrom(Player::getInstance()) > kSpawnRadius) {
        CombatEntity::setDestroyed(true);
	}
	else {
		is_wandering = true;
	}

	std::vector<CombatEntity*> player;
	player.push_back(Player::getInstance());
	for (unsigned int i = 0; i < bullet.size(); i++) {
        bullet.at(i)->update(&player, delta_time);
        if (distanceFrom(bullet.at(i)) > 1000 
			|| bullet.at(i)->isDestroyed()) {

            delete bullet.at(i);
            bullet.erase(bullet.begin() + i);
            i--;
        }
	}
}

void Enemy::wander(sf::Time * delta_time) {

    setXVelocity(cos(angleTo(target)*kDegreesToRadians) * getSpeed());
    setYVelocity(sin(angleTo(target)*kDegreesToRadians) * getSpeed());

	move(getXVelocity(), getYVelocity());

	if (isIntersecting(target)) {
        generateWanderTarget();
	}
}

void Enemy::followPlayer (sf::Time * delta_time) {

    setXVelocity(cos(angleTo(Player::getInstance())*kDegreesToRadians)
		* getSpeed());
    setYVelocity(sin(angleTo(Player::getInstance())*kDegreesToRadians)
		* getSpeed());

	move(getXVelocity(), getYVelocity());

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

    fire_buffer.loadFromFile("res/enemyshoot.wav");
    fire_sound.setBuffer(fire_buffer);
    fire_sound.play();
}

void Enemy::takeDamage() {
    CombatEntity::setDestroyed(true);
}

Enemy::~Enemy() {
	if (target) {
		delete target;
	}
}
