#include <SFML/System.hpp>
#include <cmath>
#include "Player.hpp"
#include "Constants.hpp"
#include "Trail.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include <iostream>



Player::Player(float x, float y, Origin * origin) {
	this->origin = origin;
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

void Player::setXVelocity(float x_velocity) {
    this->x_velocity = x_velocity;
}

void Player::setYVelocity(float y_velocity) {
    this->y_velocity = y_velocity;
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

float Player::getXVelocity() {
    return x_velocity;
}

float Player::getYVelocity() {
    return y_velocity;
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

void Player::update(std::vector<Entity*> * enemy, sf::Time * delta_time) {
    for (unsigned int i = 0; i < trail.size(); i++) {
        trail.at(i)->update();
    }
    if (trail.size() > 0 && trail.at(0)->isOld()) {
        delete trail.at(0);
        trail.erase(trail.begin());
    }

	for (unsigned int i = 0; i < bullet.size(); i++) {
        bullet.at(i)->update(enemy, delta_time);
        if (distanceFrom(bullet.at(i)) > 500) {
            delete bullet.at(i);
            bullet.erase(bullet.begin() + i);
            i--;
        }
	}
}

void Player::rotateLeft(sf::Time * delta_time) {
	setAngle(getAngle() - 450 * delta_time->asSeconds());
}

void Player::rotateRight(sf::Time * delta_time) {
	setAngle(getAngle() + 450 * delta_time->asSeconds());
}

void Player::createTrail() {
    Trail * new_trail = new Trail(getX() + cos(getLastThrustAngle()*kDegreesToRadians) * 10,
        getY() + sin(getLastThrustAngle()*kDegreesToRadians) * 10, origin);
    trail.push_back(new_trail);
}

void Player::fireBullet() {
    Bullet * new_bullet = new Bullet(getCenterX(), getCenterY(), getAngle(), origin);
    bullet.push_back(new_bullet);
}

void Player::draw(sf::RenderWindow * window) {

    for (unsigned int i = 0; i < trail.size(); i++) {
        trail.at(i)->draw(window);
    }

    for (unsigned int i = 0; i < bullet.size(); i++) {
        bullet.at(i)->draw(window);
	}

    sf::Sprite player_sprite;
    sf::Texture player_texture;
    player_texture.loadFromFile("res/placeholdership.png");
    player_sprite.setTexture(player_texture, true);
    player_sprite.setOrigin(getWidth() / 2, getHeight() / 2);
    player_sprite.setPosition(getCenterX(), getCenterY());
    player_sprite.setRotation(getAngle());

	window->draw(player_sprite);
}

Player::~Player() {
    delete clock;
    for (unsigned int i = 0; i < trail.size(); i++) {
        delete trail.at(i);
    }
}
