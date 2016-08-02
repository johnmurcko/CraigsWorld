#include "Bullet.hpp"
#include <iostream>

Bullet::Bullet(float x, float y, float angle, Origin * origin) {
    this->origin = origin;
    last_origin_x = origin->getX();
	last_origin_y = origin->getY();
	setX(x);
	setY(y);
	setWidth(10);
	setHeight(10);
	setAngle(angle - 90);
	setSpeed(kBulletSpeed);
	setXVelocity(cos(getAngle()*kDegreesToRadians) * getSpeed());
    setYVelocity(sin(getAngle()*kDegreesToRadians) * getSpeed());
}

void Bullet::setSpeed(float speed) {
	this->speed = speed;
}

void Bullet::setAngle(float angle) {
	this->angle = angle;
}

void Bullet::setXVelocity(float x_velocity) {
    this->x_velocity = x_velocity;
}

void Bullet::setYVelocity(float y_velocity) {
    this->y_velocity = y_velocity;
}

float Bullet::getSpeed() {
	return speed;
}

float Bullet::getAngle() {
	return angle;
}

float Bullet::getXVelocity() {
    return x_velocity;
}

float Bullet::getYVelocity() {
    return y_velocity;
}

void Bullet::update(sf::Time * delta_time) {
	Entity::update ();

    move(getXVelocity() * delta_time->asSeconds(),
        getYVelocity() * delta_time->asSeconds());
}

void Bullet::draw(sf::RenderWindow * window) {
    sf::RectangleShape bullet_rect(sf::Vector2f(getWidth(),getHeight()));
    bullet_rect.setOrigin(getWidth() / 2, getHeight() / 2);
	bullet_rect.setPosition(getX(), getY());

	bullet_rect.setFillColor(sf::Color::Yellow);
	bullet_rect.setRotation(getAngle());
	window->draw(bullet_rect);
}
