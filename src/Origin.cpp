#include "Origin.hpp"
#include "Constants.hpp"

Origin::Origin(float x, float y) {
	setX(x);
	setY(y);
	speed = kDefaultSpeed;
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
