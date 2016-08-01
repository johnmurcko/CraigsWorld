#include <SFML/System.hpp>
#include <cmath>
#include "Player.hpp"
#include "Constants.hpp"
#include <iostream>



Player::Player(float x, float y, Origin * origin) {
	this->origin = origin;
	setX(x);
	setY(y);
	setWidth(kWidth);
	setHeight(kHeight);
	setSpeed(5);
	setAcceleration(kDefaultAcceleration);
	setMaxSpeed(kDefaultMaxSpeed);
	setAngle(0);
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

    setXVelocity( getXVelocity() + cos(getLastThrustAngle()*kDegreesToRadians) * delta_time->asSeconds() * getSpeed());
    setYVelocity( getYVelocity() + sin(getLastThrustAngle()*kDegreesToRadians) * delta_time->asSeconds()* getSpeed());

	origin->move(getXVelocity(), getYVelocity());std::cout << getAngle() << '\n';
}

void Player::reverseThrust(sf::Time * delta_time) {
    setLastThrustAngle(getAngle() + 90+180);

	setXVelocity( getXVelocity() + cos(getLastThrustAngle()*kDegreesToRadians) * getSpeed() * delta_time->asSeconds());
    setYVelocity( getYVelocity() + sin(getLastThrustAngle()*kDegreesToRadians) * getSpeed() * delta_time->asSeconds());

	origin->move(getXVelocity(), getYVelocity());
}

void Player::enforceInertia(sf::Time * delta_time) {
	setXVelocity(getXVelocity()*0.99);//delta_time->asSeconds());
	setYVelocity(getYVelocity()*0.99);
	origin->move(getXVelocity(), getYVelocity());
}

void Player::update(sf::Time *delta_time) {

}

void Player::rotateLeft(sf::Time * delta_time) {
	setAngle(getAngle() + 450 * delta_time->asSeconds());
	std::cout << getAngle() << '\n';
}

void Player::rotateRight(sf::Time * delta_time) {
	setAngle(getAngle() - 450 * delta_time->asSeconds());
}

void Player::draw(sf::RenderWindow * window) {
    sf::Sprite player_sprite;
    sf::Texture player_texture;
    player_texture.loadFromFile("res/placeholdership.png");
    player_sprite.setTexture(player_texture, true);
    player_sprite.setOrigin(getWidth() / 2, getHeight() / 2);
    player_sprite.setPosition(getX(), getY());
    player_sprite.setRotation(getAngle());



	window->draw(player_sprite);
}
