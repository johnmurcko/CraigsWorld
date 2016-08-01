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

// TODO: THIS NEEDS TO BE FIXED
bool Entity::isIntersecting(Entity * entity) {
    float this_top_left_x = getX();
    float this_top_left_y = getY();
    float this_bottom_right_x = getX() + getWidth();
    float this_bottom_right_y = getY() + getHeight();

    float that_top_left_x = entity->getX();
    float that_top_left_y = entity->getY();
    float that_bottom_right_x = entity->getX() + entity->getWidth();
    float that_bottom_right_y = entity->getY() + entity->getHeight();

	if (this_top_left_x > that_bottom_right_x
        || this_bottom_right_x > that_top_left_x) {

        return false;
    }

    if (this_top_left_y > that_bottom_right_y
        || this_bottom_right_y > that_top_left_y) {

        return false;
    }

    return true;
}

void Entity::update() {
	x = x + origin->getX() - last_origin_x;
	y = y + origin->getY() - last_origin_y;

	last_origin_x = origin->getX();
	last_origin_y = origin->getY();
}
