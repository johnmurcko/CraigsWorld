#include <stddef.h>
#include "Origin.hpp"
#include "Constants.hpp"

bool Origin::instance_exists = false;
Origin * Origin::shared_origin = NULL;

Origin::Origin(float x, float y) {
	setX(x);
	setY(y);
	speed = kDefaultSpeed;
}

Origin * Origin::getInstance() {
	if (instance_exists) {
		return shared_origin;
	}

    instance_exists = true;
	shared_origin = new Origin(0, 0);
	return shared_origin;
}

void Origin::setX(float x) {
	this->x = x;
}

void Origin::setY(float y) {
	this->y = y;
}

float Origin::getX() {
	return x;
}

float Origin::getY() {
	return y;
}

void Origin::move(float x_delta, float y_delta) {
    setX(getX() + x_delta);
    setY(getY() + y_delta);
}

float Origin::getSpeed() {
	return speed;
}
