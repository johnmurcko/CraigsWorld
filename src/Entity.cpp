#include <cmath>
#include "Entity.hpp"
#include "Constants.hpp"

void Entity::setX(float x) {
	this->x = x;
}

void Entity::setY(float y) {
	this->y = y;
}

void Entity::setWidth(int width) {
	this->width = width;
}

void Entity::setHeight(int height) {
	this->height = height;
}

void Entity::setXVelocity(float x_velocity) {
    this->x_velocity = x_velocity;
}

void Entity::setYVelocity(float y_velocity) {
    this->y_velocity = y_velocity;
}

float Entity::getXVelocity() {
    return x_velocity;
}

float Entity::getYVelocity() {
    return y_velocity;
}

float Entity::getX() {
	return x;
}

float Entity::getY() {
	return y;
}

float Entity::getCenterX () {
    return getX() + getWidth() / 2;
}

float Entity::getCenterY() {
    return getY() + getHeight() / 2;
}

int Entity::getWidth() {
	return width;
}

int Entity::getHeight() {
	return height;
}

void Entity::move(float x_delta, float y_delta) {
    setX(getX() + x_delta);
    setY(getY() + y_delta);
}

bool Entity::isIntersecting(Entity * entity) {
    if (getX() <= entity->getX() + entity->getWidth()
        && getX() + getWidth() >= entity->getX()
        && getY() <= entity->getY() + entity->getHeight()
        && getY() + getHeight() >= entity->getY()) {

        return true;
    }

    return false;
}

float Entity::distanceFrom(Entity * entity) {
    return sqrt(pow(getX() - entity->getX(), 2) + pow(getY() - entity->getY(), 2));
}

float Entity::angleTo(Entity * entity) {
	return atan2((entity->getCenterY() - getCenterY()), (entity->getCenterX() - getCenterX())) * kRadiansToDegrees + 90;
}

void Entity::update() {
	setX(getX() + origin->getX() - last_origin_x);
	setY(getY() + origin->getY() - last_origin_y);

	last_origin_x = origin->getX();
	last_origin_y = origin->getY();
}
