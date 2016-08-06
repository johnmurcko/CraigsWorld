#include "Bullet.hpp"
#include <iostream>

Bullet::Bullet(float x, float y, float angle) {
	origin = Origin::getInstance();
    last_origin_x = origin->getX();
	last_origin_y = origin->getY();
	destroyed = false;
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

void Bullet::setVelocity(float x_velocity, float y_velocity) {
    setXVelocity(x_velocity);
    setYVelocity(y_velocity);
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

bool Bullet::isDestroyed() {
    return destroyed;
}

void Bullet::update(std::vector<CombatEntity*> * bullet_target, sf::Time * delta_time) {
	Entity::update ();

    if (!isDestroyed()) {
        for (unsigned int i = 0; i < bullet_target->size(); i++) {
            if (isIntersecting(bullet_target->at(i))) {
                bullet_target->at(i)->takeDamage();
               // destroyed = true;
                break;
            }
        }

        move(getXVelocity() * delta_time->asSeconds(),
            getYVelocity() * delta_time->asSeconds());
    }
}

void Bullet::draw(sf::RenderWindow * window) {
    if (!isDestroyed()) {
        sf::RectangleShape bullet_rect(sf::Vector2f(getWidth(),getHeight()));
        bullet_rect.setOrigin(getWidth() / 2, getHeight() / 2);
        bullet_rect.setPosition(getX(), getY());

        bullet_rect.setFillColor(sf::Color::Yellow);
        bullet_rect.setRotation(getAngle());
        window->draw(bullet_rect);
	}
}
