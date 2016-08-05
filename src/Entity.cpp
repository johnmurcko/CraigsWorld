#include <cmath>
#include "Entity.hpp"

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

void Entity::update() {
	setX(getX() + origin->getX() - last_origin_x);
	setY(getY() + origin->getY() - last_origin_y);

	last_origin_x = origin->getX();
	last_origin_y = origin->getY();
}
