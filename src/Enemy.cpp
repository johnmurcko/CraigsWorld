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
    enemy_type = rand() % 2;
	speed = kDefaultSpeed / 100;
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
//		wander(delta_time);
	}

	if (distanceFrom(Player::getInstance()) < 200) {
		is_wandering = false;
//		followPlayer(delta_time);
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

    setXVelocity(cos(angleTo(target)*kDegreesToRadians) * getSpeed());
    setYVelocity(sin(angleTo(target)*kDegreesToRadians) * getSpeed());

	move(getXVelocity(), getYVelocity());

	if (isIntersecting(target)) {
        generateWanderTarget();
	}
}

void Enemy::followPlayer (sf::Time * delta_time) {


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
	//window->draw(enemy_rect);

	sf::Sprite enemy_sprite;
	sf::Texture enemy_texture;
	if (enemy_type == basic_enemy_one) {
        enemy_texture.loadFromFile("res/enemy-1.png");
        enemy_sprite.setScale(0.7f, 0.7f);

	}
	else if (enemy_type == basic_enemy_two) {
        enemy_texture.loadFromFile("res/enemy-2.png");
	}
	enemy_sprite.setTexture(enemy_texture, true);
	enemy_sprite.setOrigin(getWidth() / 2, getHeight() / 2);
	enemy_sprite.setPosition(getCenterX(), getCenterY());

	window->draw(enemy_sprite);
	//window->draw(target_rect);
}

Enemy::~Enemy() {
	if (target) {
		delete target;
	}
}
