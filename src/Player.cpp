#include <stddef.h>
#include <cmath>
#include <SFML/System.hpp>
#include "Player.hpp"
#include "Constants.hpp"
#include "Trail.hpp"
#include "PlayerBullet.hpp"
#include "Enemy.hpp"
#include <iostream>

bool Player::instance_exists = false;
Player * Player::shared_player = NULL;

Player::Player(float x, float y) {
	origin = Origin::getInstance();
	setX(x - kWidth);
	setY(y - kHeight);
	setWidth(kWidth);
	setHeight(kHeight);
	setSpeed(5);
	setAcceleration(kDefaultAcceleration);
	setMaxSpeed(kDefaultMaxSpeed);
	setAngle(0);
	clock = new sf::Clock();
}

Player * Player::getInstance() {
    if (instance_exists) {
        return shared_player;
    }

    instance_exists = true;
    shared_player = new Player(kWindowWidth / 2, kWindowHeight / 2);

    return shared_player;
}

void Player::setSpeed(float speed) {
	this->speed = speed;
}

void Player::setAcceleration(float acceleration) {
	this->acceleration = acceleration;
}

void Player::setMaxSpeed(float max_speed) {
	this->max_speed = max_speed;
}

void Player::setAngle(float angle) {
	this->angle = angle;
}

void Player::setLastThrustAngle(float last_thrust_angle) {
    this->last_thrust_angle = last_thrust_angle;
}

float Player::getSpeed() {
	return speed;
}

float Player::getAcceleration() {
	return acceleration;
}

float Player::getMaxSpeed() {
	return max_speed;
}

float Player::getAngle() {
	return angle;
}

float Player::getLastThrustAngle() {
    return last_thrust_angle;
}

void Player::forwardThrust(sf::Time * delta_time) {

    setLastThrustAngle(getAngle()+90);

    setXVelocity( getXVelocity() + cos(getLastThrustAngle()*kDegreesToRadians)
        * getSpeed() * delta_time->asSeconds());
    setYVelocity( getYVelocity() + sin(getLastThrustAngle()*kDegreesToRadians)
        * getSpeed() * delta_time->asSeconds());

	origin->move(getXVelocity(), getYVelocity());

    sf::Time time_last_trail = clock->getElapsedTime();
    if (time_last_trail.asSeconds() > 0.1f) {
        createTrail();
        clock->restart();
    }
}

void Player::reverseThrust(sf::Time * delta_time) {
    setLastThrustAngle(getAngle() + 90+180);

	setXVelocity( getXVelocity() + cos(getLastThrustAngle()*kDegreesToRadians)
        * getSpeed() * delta_time->asSeconds());
    setYVelocity( getYVelocity() + sin(getLastThrustAngle()*kDegreesToRadians)
        * getSpeed() * delta_time->asSeconds());

	origin->move(getXVelocity(), getYVelocity());
}

void Player::enforceInertia(sf::Time * delta_time) {
	setXVelocity(getXVelocity()*0.99);//delta_time->asSeconds());
	setYVelocity(getYVelocity()*0.99);
	origin->move(getXVelocity(), getYVelocity());
}

void Player::update(std::vector<CombatEntity*> * enemy, sf::Time * delta_time) {
    for (unsigned int i = 0; i < trail.size(); i++) {
        trail.at(i)->update();
    }
    if (trail.size() > 0 && trail.at(0)->isOld()) {
        delete trail.at(0);
        trail.erase(trail.begin());
    }

	for (unsigned int i = 0; i < bullet.size(); i++) {
        bullet.at(i)->update(enemy, delta_time);
        if (bullet.at(i)->isDestroyed()) {
            delete bullet.at(i);
            bullet.erase(bullet.begin() + i);
            i--;
        }
	}
}

void Player::rotateLeft(sf::Time * delta_time) {
	setAngle(getAngle() - 200 * delta_time->asSeconds());
}

void Player::rotateRight(sf::Time * delta_time) {
	setAngle(getAngle() + 200 * delta_time->asSeconds());
}

void Player::createTrail() {
    Trail * new_trail = new Trail(getCenterX() + cos(getLastThrustAngle()*kDegreesToRadians) * 50,
        getCenterY() + sin(getLastThrustAngle()*kDegreesToRadians) * 50);
    trail.push_back(new_trail);
}

void Player::fireBullet() {
    PlayerBullet * new_bullet = new PlayerBullet(getCenterX(), getCenterY(), getAngle());
    bullet.push_back(new_bullet);
}

void Player::loseHealth() {

}

void Player::draw(sf::RenderWindow * window) {

    for (unsigned int i = 0; i < trail.size(); i++) {
        trail.at(i)->draw(window);
    }

    for (unsigned int i = 0; i < bullet.size(); i++) {
        bullet.at(i)->draw(window);
	}

	sf::RectangleShape rect(sf::Vector2f(getWidth(), getHeight()));
	rect.setPosition(getCenterX(), getCenterY());
	rect.setOrigin(getWidth()/2, getHeight()/2);
	rect.setOutlineColor(sf::Color::Red);


    sf::Sprite player_sprite;
    sf::Texture player_texture;
    player_texture.loadFromFile("res/player.png");
    player_sprite.setTexture(player_texture, true);
    player_sprite.setOrigin(getWidth() / 2, getHeight() / 2);
    player_sprite.setPosition(getCenterX(), getCenterY());
    player_sprite.setRotation(getAngle());

	window->draw(player_sprite);
	//window->draw(rect);
}

Player::~Player() {
    delete clock;
    for (unsigned int i = 0; i < trail.size(); i++) {
        delete trail.at(i);
    }
}
