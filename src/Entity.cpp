#include "Entity.hpp"

void Entity::setX (float x) {
	this->x = x;
}

void Entity::setY (float y) {
	this->y = y;
}

void Entity::setWidth (int width) {
	this->width = width;
}

void Entity::setHeight (int height) {
	this->height = height;
}

float Entity::getX () {
	return x;
}

float Entity::getY () {
	return y;
}

int Entity::getWidth () {
	return width;
}

int Entity::getHeight () {
	return height;
}

void Entity::move (float x_delta, float y_delta) {
    setX (getX () + x_delta);
    setY (getY () + y_delta);
}

bool Entity::isIntersecting (Entity * entity) {
	if (entity->getX () >= getX ()
		|| entity->getX () + entity->getWidth() <= getX () + getWidth ()
		|| entity->getY () >= getY ()
		|| entity->getY () <= getY () + getHeight ()) {

		return true;
	}

	return false;
}

void Entity::update () {
	x = x + origin->getX () - last_origin_x;
	y = y + origin->getY () - last_origin_y;

	last_origin_x = origin->getX ();
	last_origin_y = origin->getY ();
}
